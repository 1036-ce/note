#include <iostream>
#include <vector>
#include <string>

using namespace std;

void rep(string &s, const string &oldVal, const string &newVal) 
{
	for (auto i = 0; i != s.size(); ++i) 
	{
		if (s[i] == oldVal[0])
		{
			string tmp = s.substr(i, oldVal.size());
			if (tmp == oldVal) 
			{
				s.replace(i, oldVal.size(), newVal);
				i += newVal.size();
			}
		}
	}
}
int main(void)
{
	string s("123123123");
	cout << s << endl;
	rep(s, "12", "12");
	cout << s << endl;
	return 0;
}
