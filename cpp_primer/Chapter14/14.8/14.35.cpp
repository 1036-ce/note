#include <iostream>
#include <istream>
#include <string>

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
	string s = rw(cin);
	cout << s << endl;
	return 0;
}
