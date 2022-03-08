#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	string s("pi = 3.14");
	double d = stod(s.substr(s.find_first_of("+-.0123456789")));
	cout << d << endl;
	return 0;
}
