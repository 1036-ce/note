#include <iostream>
#include <istream>
#include <string>
#include <vector>

using namespace std;

class Read_string {
public:
	string operator()(istream &is)
	{
		string s;
		getline(is, s);
		return s;
	}
};

int main(void)
{
	Read_string rw;
	vector<string> vec;
	string s;
	while ((s = rw(cin)) != "")
	{
		vec.push_back(s);
	}
	for (auto i: vec)
		cout << i << endl;
	return 0;
}
