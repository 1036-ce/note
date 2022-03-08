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

int main(void)
{
	vector<string> vec{"the","quick","red","fox","jumps","over","the","slow","red","turtl"};
	return 0;
}

