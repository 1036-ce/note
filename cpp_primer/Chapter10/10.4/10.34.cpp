#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

int main(void)
{
	vector<int> vec{1,2,3,4,5,6,7,8,9};
	auto it = vec.crbegin();
	while (it != vec.crend())
	{
		cout << *it++ << endl;
	}
	return 0;
}

