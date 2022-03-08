#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HasPtr {
public:
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

int main(void)
{
	return 0;
}
