#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main(void)
{
	vector<int> vec{1,2,2,3,2,4,3,4};
	list<int> lst;
	sort(vec.begin(), vec.end());
	unique_copy(vec.begin(), vec.end(), back_inserter(lst));
	for (auto i: lst)
		cout << i << endl;
	return 0;
}

