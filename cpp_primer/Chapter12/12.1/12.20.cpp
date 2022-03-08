#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "../StrBlob.h"

using namespace std;

int main(int argc, char **argv)
{
	ifstream is(argv[1], ifstream::in);
	StrBlob sb;
	string s;
	
	while (getline(is, s))
		sb.push_back(s);

	auto it = sb.begin();
	while (!it.equal(sb.end()))
	{
		cout << it.deref() << endl;
		it = it.incr();
	}
	return 0;
}
