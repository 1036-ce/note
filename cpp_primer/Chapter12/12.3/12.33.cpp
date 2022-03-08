#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>
#include <memory>

using namespace std;
class QueryResult;
class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;
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

class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	using line_no = std::vector<std::string>::size_type;
	QueryResult(std::string s,
				std::shared_ptr<std::set<line_no>> p,
				std::shared_ptr<std::vector<std::string>> f):
		sought(s), lines(p), file(f) {  }
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

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
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< (qr.lines->size() == 1 ? "time" : "times") << endl;

	for (auto num: *qr.lines)
		os << "\t(line " << num + 1 << ") "
			<< *(qr.file->begin() + num) << endl;
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
