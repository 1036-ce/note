#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <algorithm>
#include <cstring>

class String {
public:
	String(): str(nullptr), eos(nullptr) {}
	String(const char*);
	String(const String&);
	String& operator=(const String&);
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
	std::cout << "String(const String&)" << std::endl;
}

String& String::operator=(const String &s)
{
	auto newstr = alloc.allocate(s.size());
	auto neweos = std::uninitialized_copy(s.str, s.eos, newstr);
	free();
	str = newstr;
	eos = neweos;
	std::cout << "=" << std::endl;
	return *this;
}

String::~String()
{
	free();
}

int main(void)
{
	char s1[] = "1234asd";
	String s2(s1);
	String s3;
	s3 = s2;
	return 0;
}
