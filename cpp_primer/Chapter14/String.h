#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <algorithm>
#include <cstring>

class String {
public:
	friend std::ostream &operator<<(std::ostream&,const String&);
	friend bool operator==(const String&, const String&);
	friend bool operator!=(const String&, const String&);
	friend bool operator<(const String&, const String&);
	String(): str(nullptr), eos(nullptr) {}
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	char& operator[](std::size_t);
	const char& operator[](std::size_t) const;

	//移动构造函数
	String(String&&) noexcept;
	//移动赋值运算符
	String& operator=(String&&) noexcept;

	~String();

	std::size_t size() const { return eos - str; }
private:
	static std::allocator<char> alloc;
	void free();
	char *str;
	char *eos;
};

std::allocator<char> String::alloc;

void String::free()
{
	if (str)
	{
		std::for_each(str, eos, 
				[](char &c) { alloc.destroy(&c); });
		alloc.deallocate(str, eos - str);
	}
	std::cout << "free" << std::endl;
}
String::String(const char *s)
{
	int size = strlen(s);
	str = alloc.allocate(size);
	eos = std::uninitialized_copy_n(s, size, str);
}

String::String(const String &s)
{
	str = alloc.allocate(s.size());
	eos = std::uninitialized_copy(s.str, s.eos, str);
	std::cout << "clone" << std::endl;
}

String& String::operator=(const String &s)
{
	auto newstr = alloc.allocate(s.size());
	auto neweos = std::uninitialized_copy(s.str, s.eos, newstr);
	free();
	str = newstr;
	eos = neweos;
	std::cout << "clone=" << std::endl;
	return *this;
}

String::~String()
{
	free();
}

String::String(String &&s) noexcept: str(s.str), eos(s.eos)
{
	s.str = s.eos = nullptr;
	std::cout << "move" << std::endl;
}

String& String::operator=(String &&rhs) noexcept
{
	if (this != &rhs)
	{
		free();
		str = rhs.str;
		eos = rhs.eos;
		rhs.str = rhs.eos = nullptr;
	}
	std::cout << "move=" << std::endl;
	return *this;
}

std::ostream &operator<<(std::ostream &os,const String &s)
{
	auto it = s.str;
	while (it != s.eos)
	{
		os << *it;
		++it;
	}
	return os;
}

bool operator==(const String &s1, const String &s2)
{
	auto it1 = s1.str, it2 = s2.str;
	while (it1 != s1.eos && it2 != s2.eos)
	{
		if (*it1 != *it2)
			return false;
		++it1, ++it2;
	}
	if (it1 == s1.eos && it2 == s2.eos)
		return true;
	return false;
}

bool operator!=(const String &s1, const String &s2)
{
	return !(s1 == s2);
}

bool operator<(const String &s1, const String &s2)
{
	auto it1 = s1.str, it2 = s2.str;
	while (it1 != s1.eos && it2 != s2.eos)
	{
		if (*it1 >= *it2)
			return false;
		++it1, ++it2;
	}
	return it1 == s1.eos;
}

char& String::operator[](std::size_t n)
{
	return *(str + n);
}

const char& String::operator[](std::size_t n) const
{
	return *(str + n);
}
