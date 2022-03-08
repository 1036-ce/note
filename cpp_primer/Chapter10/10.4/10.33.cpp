#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char **argv)
{
	ifstream is(argv[1], ifstream::in);
	ofstream os1(argv[2], ofstream::out);
	ofstream os2(argv[3], ofstream::out);

	istream_iterator<int> in(is), eof;
	ostream_iterator<int> out1(os1, " "), out2(os2, "\n");

	while (in != eof)
	{
		int a = *in++;
		if (a % 2)
			out1 = a;
		else
			out2 = a;
	}
	return 0;
}

