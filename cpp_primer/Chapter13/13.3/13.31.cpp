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
		std::cout << "swap" << std::endl;
	}

	friend bool operator<(HasPtr &hp1, HasPtr &hp2)
	{
		return *hp1.ps < *hp2.ps;
	}

	HasPtr(const std::string &s): ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr &hp): ps(new std::string(*(hp.ps))), i(hp.i) {}

	HasPtr& operator=(const HasPtr &hp)
	{
		auto newp = new std::string(*(hp.ps));
		delete ps;
		ps = newp;
		i = hp.i;
		return *this;
	}
	~HasPtr() { delete ps; }

	void print()
	{
		std::cout << *ps << std::endl;
	}
private:
	std::string  *ps;
	int i;
};
int main(void)
{
	/* HasPtr hp1("123");
	 * HasPtr hp2("456");
	 * swap(hp1, hp2); */
	HasPtr hp1("123");
	HasPtr hp2("012");
	HasPtr hp3("673");
	HasPtr hp4("034");
	std::vector<HasPtr> vec;
	vec.push_back(hp1);
	vec.push_back(hp2);
	vec.push_back(hp3);
	vec.push_back(hp4);

	sort(vec.begin(), vec.end());
	for (auto i: vec)
		i.print();
	return 0;
}
