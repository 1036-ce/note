#include <cstdio>
#include <iostream>
#include <istream>
#include <sstream>
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
	string s = "1 12 123 1234";
	istringstream is(s);
	read(is);
	return 0;
}
