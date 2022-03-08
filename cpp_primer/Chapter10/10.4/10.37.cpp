#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <list>

using namespace std;

int main(void)
{
	vector<int> vec{0,1,2,3,4,5,6,7,8,9};
	list<int> lst;
	for_each(vec.crbegin() + 3, vec.crbegin() + 8, 
			[&lst] (int a) { lst.push_back(a); });

	for (auto i: lst)
	    cout << i << endl; 
	return 0;
}

