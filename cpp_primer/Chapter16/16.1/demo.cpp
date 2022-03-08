#include <iostream>
#include <vector>
#include <string>

using namespace std;

class A {
public:
	A() = default;
	A(const A &a): val(a.val) {  }
private:
	int val;
};

int main(void)
{
	A p;
	A p1(p);
	return 0;
}
