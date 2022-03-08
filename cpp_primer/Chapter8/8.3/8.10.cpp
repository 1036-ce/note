#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	ifstream ifile(argv[1], ifstream::in);
	vector<string> vec;
	string line;
	while(getline(ifile, line))
		vec.push_back(line);

	for(auto i: vec) {
		istringstream is(i);
		string s;
		while(is >> s)
			cout << s << endl;
	}
	return 0;
}
