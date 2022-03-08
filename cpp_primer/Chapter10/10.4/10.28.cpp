#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main(void)
{
	vector<int> vec{1,2,3,4,5,6,7,8,9};
	vector<int> v1;
	vector<int> v2;
	deque<int> v3;
	copy(vec.begin(), vec.end(), inserter(v1, v1.begin()));
	copy(vec.begin(), vec.end(), back_inserter(v2));
	copy(vec.begin(), vec.end(), front_inserter(v3));

	cout << "v1" << endl;
	for (auto i: v1)
		cout << i << " ";
	cout << endl;
	cout << "v2" << endl;
	for (auto i: v2)
		cout << i << " ";
	cout << endl;
	cout << "v3" << endl;
	for (auto i: v3)
		cout << i << " ";
	cout << endl;
	return 0;
}

