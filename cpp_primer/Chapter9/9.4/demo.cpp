#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	freopen("in.txt", "r", stdin);
	vector<string> vec;
	string word;
	while (cin >> word) {
		vec.push_back(word);
	}
	vec.resize(vec.size() + vec.size() / 2);
	for (auto i: vec) {
		if (i == "")
			cout << "0" << endl;
		else
			cout << i << endl;
	}
	cout << endl;

	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	return 0;
}
