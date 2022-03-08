#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	ifstream is(argv[1], ifstream::in);
	const string target("aceimnorsuvwxz");
	string word;
	vector<string> ans;

	while (is >> word) 
	{
		if (word.find_first_not_of(target) == string::npos) 
		{
			if (ans.empty() || word.size() > ans[0].size())
			{
				if (!ans.empty())
					ans.clear();
				ans.push_back(word);
			}
			else if (word.size() == ans[0].size())
				ans.push_back(word);
		}
	}

	for (auto i: ans)
		cout << i << endl;
	return 0;
}
