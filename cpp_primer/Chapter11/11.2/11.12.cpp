#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main(void)
{
	vector<pair<string, int>> vec;
	pair<string, int> p;
	while (cin >> p.first >> p.second)
		vec.push_back(p);

	for (const auto &i: vec)
		cout << i.first << " " << i.second << endl;
	return 0;
}
