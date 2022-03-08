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
		ps = new string(*(hp.ps));
		i = hp.i;
		return *this;
	}
private:
	std::string  *ps;
	int i;
};

int main(void)
{
	HasPtr hp1("123");
	HasPtr hp2 = hp1;
	return 0;
}
