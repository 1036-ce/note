#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(void)
{
	vector<int> vec{1,2,3,4,5,6,7,8,9};
	int ans = accumulate(vec.cbegin(), vec.cend(), 0);
	cout << ans << endl;
	return 0;
}
