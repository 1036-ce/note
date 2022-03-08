#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
	map<string, vector<string>> family;
	cout << "Enter the name of family" << endl;
	string family_name;
	cin >> family_name;
	cout << "Enter names of childres" << endl;
	vector<string> children_name;
	string word;
	while (cin >> word)
		children_name.push_back(word);
	family[family_name] = children_name;

	for (const auto &i: family)
	{
		cout << i.first << endl;
		for (const auto &j: i.second)
			cout << j << endl;
	}
	return 0;
}

