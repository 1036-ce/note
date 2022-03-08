#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<const char*> roster1{"1","2","3"};
	vector<const char*> roster2{"1","2","3"};
	cout << equal(roster1.cbegin(), roster1.cend(), roster2);
	return 0;
}
