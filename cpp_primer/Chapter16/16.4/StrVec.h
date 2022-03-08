#ifndef STRVEC_H
#define STRVEC_H

#include <alloca.h>
#include <cstddef>
#include <cwctype>
#include <initializer_list>
#include <iostream>
#include <string>
#include <type_traits>
#include <utility>
#include <memory>
#include <algorithm>

class StrVec {
public:
	friend bool operator==(const StrVec&, const StrVec&);
	friend bool operator!=(const StrVec&, const StrVec&);
	friend bool operator<(const StrVec&, const StrVec&);
	StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(std::initializer_list<std::string>);
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	std::string& operator[](std::size_t);
	const std::string& operator[](std::size_t) const;

	//移动构造函数
	StrVec(StrVec &&) noexcept;
	//移动赋值运算符
	StrVec &operator=(StrVec&&) noexcept;
	StrVec &operator=(std::initializer_list<std::string>);

	~StrVec();
	void push_back(const std::string&);
	void push_back(std::string&&);

	template <typename... Args>	void emplace_back(Args&&... ); 

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
	std::cout << "push_back&" << std::endl;
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

void StrVec::push_back(std::string &&s)
{
	std::cout << "push_back&&" << std::endl;
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
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
		std::for_each(elements, first_free,
				[](std::string &s) { alloc.destroy(&s); });
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(std::initializer_list<std::string> il)
{
	auto p = alloc_n_copy(il.begin(), il.end());
	elements = p.first;
	first_free = p.second;
	cap = elements + il.size();
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

StrVec::StrVec(StrVec &&s) noexcept 
	:elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept
{
	if (this != &rhs)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
	}
	return *this;
}

bool operator==(const StrVec &st1, const StrVec &st2)
{
	auto it1 = st1.elements, it2 = st2.elements;
	while (it1 != st1.first_free && it2 != st2.first_free)
	{
		if (*it1 != *it2)
			return false;
		++it1, ++it2;
	}
	if (it1 == st1.first_free && it2 == st2.first_free)
		return true;
	return false;
}

bool operator!=(const StrVec &st1, const StrVec &st2)
{
	return !(st1 == st2);
}

bool operator<(const StrVec &st1, const StrVec &st2)
{
	auto it1 = st1.elements, it2 = st2.elements;
	while (it1 != st1.first_free && it2 != st2.first_free)
	{
		if (*it1 >= *it2)
			return false;
		++it1, ++it2;
	}

	return it1 == st1.first_free;
}

inline
StrVec& StrVec::operator=(std::initializer_list<std::string> il)
{
	auto it = il.begin();
	while (it != il.end())
	{
		this->push_back(*it);
		++it;
	}
	return *this;
}

inline
std::string& StrVec::operator[](std::size_t n)
{
	return *(elements + n);
}

inline
const std::string& StrVec::operator[](std::size_t n) const
{
	return *(elements + n);
}

template <typename... Args>
inline
void StrVec::emplace_back(Args&&... args)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args)...);
}

#endif 
