#include <cstddef>
#include <cwctype>
#include <iostream>
#include <string>
#include <utility>
#include <memory>

class StrVec {
public:
	StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	~StrVec();
	void push_back(const std::string&);

	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	void reserve(size_t);
	void resize(size_t, const std::string&);

	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }
private:
	static std::allocator<std::string> alloc;	//分配元素
	//被添加元素的函数所使用
	void chk_n_alloc()
	{ if (size() == capacity()) reallocate(); }

	//工具函数，被拷贝构造函数，赋值运算符，和析构函数所使用
	std::pair<std::string*, std::string*> alloc_n_copy
		(const std::string*, const std::string*);
	void free();
	void reallocate();
	std::string *elements;
	std::string *first_free;
	std::string *cap;
};

std::allocator<std::string> StrVec::alloc;

void StrVec::push_back(const std::string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy
	(const std::string *b, const std::string *e)
{
	auto data = alloc.allocate(e - b);
	return { data, std::uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
	if (elements)
	{
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
	free();
}

StrVec& StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void StrVec::reserve(size_t n)
{
	if (n <= capacity())
		return;
	auto newdata = alloc.allocate(n);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	elements = newdata;
	first_free = dest;
	cap = elements + n;
}

void StrVec::resize(size_t n, const std::string &s = "")
{
	if (n <= size())
		while (first_free != elements + n)
			alloc.destroy(--first_free);
	else if (n <= capacity())
		while (first_free != elements + n)
			alloc.construct(first_free++, s);
	else
	{
		auto newdata = alloc.allocate(n);
		auto elem = elements;
		auto dest = newdata;

		for (size_t i = 0; i != size(); ++i)
			alloc.construct(dest++, std::move(*elem++));
		elements = newdata;
		first_free = dest;
		cap = elements + n;

		while (first_free != elements +n)
			alloc.construct(first_free++, s);
	}
} 

int main(void)
{
	return 0;
}

