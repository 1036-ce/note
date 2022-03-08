#include <cstdio>
#include <iostream>
#include <istream>
#include <string>

using namespace std;

istream &read(istream &is) 
{
	auto rd = is.rdstate();
	string s;
	while(is >> s)
	{
		cout << s << endl;
	}
	is.setstate(rd);
	return is;
}

int main(void)
{
	freopen("in.txt","r",stdin);
	read(cin);
	return 0;
}
