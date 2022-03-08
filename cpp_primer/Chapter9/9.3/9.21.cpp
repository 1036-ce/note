#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	vector<string> vec;
	string word;
	auto iter = vec.begin();
	while (cin >> word)
		iter = vec.insert(iter, word);
	for (auto i: vec)
		cout << i << endl;
	return 0;
}
