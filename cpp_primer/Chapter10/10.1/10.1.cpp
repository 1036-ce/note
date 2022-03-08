#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> vec{1,2,2,3,3,2,4,5};
	cout << count(vec.begin(), vec.end(), 3) << endl;
	return 0;
}
