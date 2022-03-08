#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

template <typename T>
void print(T &container)
{
	auto it = container.begin();
	while (it != container.end())
	{
		cout << *it << endl;
		++it;
	}
}

int main(void)
{
	vector<int> vec{1,2,3,4,5,6,7};
	list<int> lst{2,3,3,1,21,23,1213,12};
	print(vec);
	print(lst);
	return 0;
}
