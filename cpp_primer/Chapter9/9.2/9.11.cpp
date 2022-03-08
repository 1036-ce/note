#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> v1;
	vector<int> v2{1,2,3};
	vector<int> v3(v2);
	vector<int> v4(v2.begin(), v2.end());
	vector<int> v5(10);
	vector<int> v6(10,10);
	return 0;
}
