#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

template<typename IterType, typename ValueType>
IterType myfind(IterType begin, IterType end, ValueType value)
{
	IterType ret = begin;
	while (ret != end)
	{
		if (*ret == value)
			return ret;
		++ret;
	}
	return ret;
}

int main(void)
{
	vector<int> vec{1,2,3,4,5};
	list<string> lst{"123", "234", "345"};
	auto ans = find(lst.begin(), lst.end(), "234");
	cout << *ans << endl;
	return 0;
}
