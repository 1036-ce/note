#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HasPtr {
public:
	HasPtr(const std::string &s = std::string()):
		ps(new std::string(s)), i(0) {}

	//拷贝构造函数
	HasPtr(const HasPtr &hp): ps(new string(*(hp.ps))), i(hp.i) {}

	void print()
	{
		cout << *ps << endl;
	}
private:
	std::string *ps;
	int i;
};

int main(void)
{
	HasPtr hp = HasPtr("string");
	hp.print();
	return 0;
}
