#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <list>

using namespace std;

template <typename T>
void print(T &container)
{
	for (typename T::size_type i = 0; i != container.size(); ++i)
	{
		std::cout << container[i] << std::endl;
	}
}

int main(void)
{
	vector<int> vec{1,2,3,4,5,6,7,8};
	deque<int> lst{1,2,3,4,5,6,78};
	print(vec);
	print(lst);
	return 0;
}
