#include <iostream>
#include <string>
#include <vector>

using namespace std;

string add_something(const string &s, const string &ft, const string &lt) 
{
	string ret = s;
	ret.insert(ret.begin(), ft.begin(), ft.end());
	ret.append(lt);
	return ret;
}
int main(void)
{
	string s("james");
	string ret = add_something(s, "Mr. ", " Jr.");
	cout << ret << endl;
	return 0;
}
