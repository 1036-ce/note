#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int main(void)
{
	auto p = make_shared<int>(12);
	shared_ptr<int> p1(new int(*p));
	cout << *p << endl;
	*p1 = 1;
	cout << *p1 << endl;
	return 0;
}
