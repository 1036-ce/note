#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HasPtr {
public:
	friend void swap(HasPtr&, HasPtr&);
	HasPtr(const string &s): ps(new string(s)), i(0) {}
	HasPtr(const HasPtr &hp): ps(new string(*(hp.ps))), i(hp.i) {}

	HasPtr& operator=(const HasPtr &hp)
	{
		auto newp = new string(*(hp.ps));
		delete ps;
		ps = newp;
		i = hp.i;
		return *this;
	}
	~HasPtr() { delete ps; }
private:
	std::string  *ps;
	int i;
};

inline
void swap(HasPtr &hp1, HasPtr &hp2)
{
	using std::swap;
	swap(hp1.ps, hp2.ps);
	swap(hp1.i, hp2.i);
	cout << "swap" << endl;
}

int main(void)
{
	HasPtr hp1("123");
	HasPtr hp2("456");
	swap(hp1, hp2);
	return 0;
}
