#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <vector>
#include <memory>

using namespace std;
using line_no = std::vector<std::string>::size_type;
using QueryResult = tuple<std::string, std::shared_ptr<std::set<line_no>>, std::shared_ptr<std::vector<std::string>>>;

class TextQuery {
public:
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream &is): file(new vector<string>)
{
	string text;
	while (getline(is, text))
	{
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) 
		{
			if (ispunct(word[word.size() - 1]))
				word = word.substr(0, word.size() - 1);

			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}
 
QueryResult
TextQuery::query(const string &sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

ostream &print(ostream &os, const QueryResult &qr)
{
	os << get<0>(qr) << " occurs " << get<1>(qr)->size() << " "
		   << (get<1>(qr)->size() == 1 ? "time" : "times") << endl;

	for (auto num: *get<1>(qr))
		os << "\t(line " << num + 1 << ") "
			<< *(get<2>(qr)->begin() + num) << endl;
	return os;
}

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	while (true)
	{
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q")
			break;
		print(cout, tq.query(s)) << endl;
	}
}
int main(int argc, char **argv)
{
	ifstream infile(argv[1], ifstream::in);
	runQueries(infile);
	return 0;
}
