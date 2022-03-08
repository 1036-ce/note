#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto it = unique(words.begin(), words.end());
	words.erase(it, words.end());
}

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}
int main(void)
{
	vector<string> vec{"the","quick","red","fox","jumps","over","the","slow","red","turtl"};
	elimDups(vec);
	stable_sort(vec.begin(), vec.end(), isShorter);
	for (auto i: vec)
		cout << i << endl;
	return 0;
}

