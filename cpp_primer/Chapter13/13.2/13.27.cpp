#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HasPtr {
public:
	HasPtr(const string &s): ps(new string(s)), i(0), use(new size_t(1)) {}
	//拷贝构造函数
	HasPtr(const HasPtr &hp): ps(hp.ps), i(hp.i), use(hp.use) { ++*use; }
	//拷贝赋值运算符
	HasPtr &operator=(const HasPtr &hp)
	{
		++*hp.use;
		if (--*use == 0)
		{
			delete ps;
			delete use;
		}
		ps = hp.ps;
		i = hp.i;
		use = hp.use;
		return *this;
	}
	 ~HasPtr()
	 {
		 if (--*use == 0)
		 {
			 delete ps;
			 delete use;
		 }
	 }
private:
	std::string *ps;
	int i;
	std::size_t *use;
};

int main(void)
{
	HasPtr hp("123");
	return 0;
}
