#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void read(vector<string> &vec)
{
	ifstream is("in.txt", ifstream::in);
	string s;
	while(getline(is, s))
		vec.push_back(s);
}
int main(void)
{
	vector<string> vec;
	read(vec);
	for(auto v: vec)
		cout << v << endl;
	return 0;
}
