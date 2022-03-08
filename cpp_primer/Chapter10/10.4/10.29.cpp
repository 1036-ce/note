#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char **argv)
{
	vector<string> vec;
	ifstream is(argv[1], ifstream::in);
	istream_iterator<string> in(is), eof;

	while (in != eof)
	{
		vec.push_back(*in++);
	}

	ostream_iterator<string> out(cout, "\n");
	copy(vec.begin(), vec.end(), out);
	return 0;
}

