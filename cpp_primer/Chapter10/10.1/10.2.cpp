#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	vector<string> vec{"1","1","12","1","12","123"};
	cout << count(vec.begin(), vec.end(), "12") << endl;
	return 0;
}
