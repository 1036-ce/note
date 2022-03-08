#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class HasPtr {
public:
	friend void swap(HasPtr &hp1, HasPtr &hp2)
	{
		using std::swap;
		swap(hp1.ps, hp2.ps);
		swap(hp1.i, hp2.i);
		// std::cout << "swap" << std::endl;
	}

	friend bool operator<(HasPtr &hp1, HasPtr &hp2)
	{
		return *hp1.ps < *hp2.ps;
	}

	HasPtr(const std::string &s = ""): ps(new std::string(s)), i(0) {}

	HasPtr(const HasPtr &hp): ps(new std::string(*(hp.ps))), i(hp.i) {}

	HasPtr& operator=(const HasPtr &hp)
	{
		auto newp = new std::string(*(hp.ps));
		delete ps;
		ps = newp;
		i = hp.i;
		return *this;
	} 
	HasPtr(HasPtr&&) noexcept;
	HasPtr& operator=(HasPtr&&) noexcept;
	~HasPtr() { delete ps; }

	void print()
	{
		std::cout << *ps << std::endl;
	}
private:
	std::string  *ps;
	int i;
};

HasPtr::HasPtr(HasPtr &&hp) noexcept
: ps(hp.ps), i(hp.i)
{
	hp.ps = nullptr;
	i = 0;
}

HasPtr& HasPtr::operator=(HasPtr &&hps) noexcept
{
	if (this != &hps)
	{
		delete ps;
		ps = hps.ps;
		i = hps.i;
		hps.ps = nullptr;
		hps.i = 0;
	}
	std::cout << "move=" << std::endl;
	return *this;
}

int main(void)
{
	HasPtr hp1("123");
	HasPtr hp2;
	hp2 = hp1;
	return 0;
}
