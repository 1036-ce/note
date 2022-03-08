#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(void)
{
	istream_iterator<int> in(cin), eof;
	vector<int> vec(in, eof);
	sort(vec.begin(), vec.end());
	ostream_iterator<int> out(cout, " ");
	unique_copy(vec.begin(), vec.end(), out);
	return 0;
}

