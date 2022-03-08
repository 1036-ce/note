#include <iostream>
#include <vector>

using namespace std;

bool find(vector<int> vec, int target) 
{
	for(auto i = vec.begin(); i != vec.end(); ++i) {
		if (*i == target)
			return true;
	}
	return false;
}
int main(void)
{
	vector<int> vec{1,2,3,4,5,6,7,8,9};
	bool b = find(vec,0);
	cout << b << endl;
	return 0;
}
