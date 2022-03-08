#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HasPtr {
public:
	HasPtr(const std::string &s = std::string()):
		ps(new std::string(s)), i(0) { cout << "HasPtr()" << endl; }

	//拷贝构造函数
	HasPtr(const HasPtr &hp): ps(new string(*(hp.ps))), i(hp.i)
	{ cout << "HasPtr(const)" << endl; }
	//拷贝赋值运算符
	HasPtr &operator=(const HasPtr &hp)
	{
		i = hp.i;
		ps = new string(*(hp.ps));
		cout << "operator=" << endl;
		return *this;
	}
	//析构函数
	~HasPtr() { delete ps; cout << "~HasPtr()" << endl;}

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
	const HasPtr hp1("string1");
	HasPtr hp2 = hp1;
	return 0;
}
