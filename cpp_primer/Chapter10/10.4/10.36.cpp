#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <list>
#include <algorithm>

using namespace std;

int main(void)
{
	list<int> lst{1,2,34,5,6,0,123,2,20,12,0,321,23};
	auto ans = find(lst.crbegin(), lst.crend(), 0);
	cout << *ans << endl;
	return 0;
}

