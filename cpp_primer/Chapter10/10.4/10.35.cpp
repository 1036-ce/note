#include <endian.h>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

int main(void)
{
	vector<int> vec{1,2,3,4,5,6,7,8,9};
	auto it = vec.cend() - 1;

	while (it +1 != vec.cbegin())
		cout << *it-- << endl;
	return 0;
}

