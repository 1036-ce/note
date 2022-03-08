#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	vector<string> s1{"1","2","3","4","5","6","7"};
	vector<string> s2{"1.0","2.2","3.3","4.4"};

	int ians = 0;
	for (auto i: s1)
		ians += stoi(i);
	cout << ians << endl;

	float fans = 0;
	for (auto i: s2)
		fans += stof(i);
	cout << fans << endl;
	return 0;
}
