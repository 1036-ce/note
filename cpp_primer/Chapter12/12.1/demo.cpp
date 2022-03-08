#include <ctime>
#include <iostream>
#include <system_error>
#include <vector>
#include <string>
#include <memory>

using namespace std;


int main(void)
{
	auto p = make_shared<int>(21);
	weak_ptr<int> wp(p);
	cout << wp.use_count() << endl;
	cout << wp.expired() << endl;
	auto p1 = wp.lock();
	cout << *p1 << endl;
	cout << *wp.lock() << endl;
	return 0;
}
