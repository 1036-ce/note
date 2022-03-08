#include <iostream>
#include <string>

using namespace std;

void rep(string &s, const string &oldVal, const string &newVal) 
{
	for (auto i = s.begin(); i != s.end(); ++i) 
	{
		if (*i == oldVal[0])
		{
			string tmp = s.substr(i - s.begin(), oldVal.size());
			if (tmp == oldVal)
			{
				i = s.erase(i, i + oldVal.size());
				i = s.insert(i, newVal.begin(), newVal.end());
				i += newVal.size();
			}
		}
	}
}

int main(void)
{
	string s("123123123");
	cout << s << endl;
	rep(s, "12", "4123");
	cout << s << endl;
	return 0;
}
