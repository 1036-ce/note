#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

using namespace std;

void show(vector<int> &vec)
{
	for (auto i: vec)
		cout << i << endl;
	cout << endl;
}
int main(void)
{
	vector<int> vec{0,2,3,4,5,6,7,8,9};
	auto iter = vec.begin();
	while (iter != vec.end())
		if (*iter % 2) 
			iter = vec.insert(iter, *iter);
		++iter;
	show(vec);
	return 0;
}
