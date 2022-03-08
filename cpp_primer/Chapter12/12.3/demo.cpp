#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <istream>
#include <iterator>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>

using namespace std;

struct QueryResult {
	int occurs_times;
	shared_ptr<set<int>> line_number;
	shared_ptr<vector<string>> file;
};

class TextQuery {
public:
	TextQuery(ifstream&);
	shared_ptr<QueryResult> query(string&);
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<int>> > query_map;
};

TextQuery::TextQuery(ifstream &infile)
{
	string line;
	int num = 0;
	file = make_shared<vector<string>>();
	while (getline(infile, line))
	{
		file->push_back(line);
		istringstream is(line);
		string word;
		while (is >> word)
		{
			if (ispunct(word[word.size() - 1]))
				word = word.substr(0, word.size() - 1);
			if (query_map.find(word) == query_map.end())
			{
				auto set_ptr = make_shared<set<int>>();
				set_ptr->insert(num);
				query_map[word] = set_ptr;
			}
			else
				query_map[word]->insert(num);
		}
		++num;
	}
}

shared_ptr<QueryResult> TextQuery::query(string &word)
{
	auto res = make_shared<QueryResult>();
	int occurs_times = 0;
	res->file = this->file;
	res->line_number = query_map[word];
	auto line_set = query_map[word];
	auto it = line_set->begin();
	while (it != line_set->end())
	{
		string line = (*file)[*it];
		int start = -1;
		while ((start = line.find(word, start + 1)) != string::npos)
			++occurs_times;
		++it;
	}
	res->occurs_times = occurs_times;
	return res;
}

ostream &print(ostream &os, shared_ptr<QueryResult> res)
{
	os << "element occurs " << res->occurs_times << 
		(res->occurs_times == 1 ? "time" : "times") << endl;
	auto it = res->line_number->begin();
	auto file = res->file;
	while (it != res->line_number->end())
	{
		os << "    (line " << *it << ") " << (*file)[*it] << endl;
		++it;
	}
	return os;
}

int main(int argc, char **argv)
{
	ifstream infile(argv[1], ifstream::in);
	TextQuery tq(infile);
	while (true)
	{
		cout << "enter word to look for, or q to quit: " << endl;
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s)) << endl;
	}
	return 0;
}
