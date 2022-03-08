#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(int argc, char **argv)
{
	ifstream infile(argv[1], ifstream::in);
	vector<string> file;
	map<string, set<int>> query_map;

	string line;
	int num = 0;
	while (getline(infile, line))
	{
		file.push_back(line);
		istringstream is(line);
		string word;
		while (is >> word)
		{
			if (ispunct(word[word.size() - 1]))
				word = word.substr(0, word.size() - 1);
			query_map[word].insert(num);
		}
		++num;
	}

	while (true)
	{
		cout << "enter word to look for, or q to quit: " << endl;
		string s;
		if (!(cin >> s) || s == "q") break;
		if (query_map.find(s) == query_map.end())
			cout << "element occurs 0 time" << endl;
		else
		{
			int occurs_times = 0;
			auto line_set = query_map[s];
			auto it = line_set.begin();
			while (it != line_set.end())
			{
				int start = -1;
				string s1 = file[*it];
				while ((start = line.find(s1, start + 1)) != string::npos)
					++occurs_times;
				++it;
			}

			cout << "element occurs " << occurs_times <<
				(occurs_times == 1 ? "time" : "times") << endl;
			it = line_set.begin();
			while (it != line_set.end())
			{
				cout << "    (line " << *it << ") " << file[*it] << endl;
				++it;
			}

		}
	}
	return 0;
}
