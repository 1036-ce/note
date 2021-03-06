#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include "TextQuery.h"


TextQuery::TextQuery(std::ifstream &is): file(new std::vector<std::string>)
{
	std::string text;
	while (std::getline(is, text))
	{
		file->push_back(text);
		int n = file->size() - 1;
		std::istringstream line(text);
		std::string word;
		while (line >> word) 
		{
			if (ispunct(word[word.size() - 1]))
				word = word.substr(0, word.size() - 1);
			if (ispunct(word[0]))
				word = word.substr(1, word.size() - 1);

			auto &lines = wm[word];
			if (!lines)
				lines.reset(new std::set<line_no>);
			lines->insert(n);
		}
	}
}


QueryResult TextQuery::query(const std::string &sought) const
{
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

/* 
 * inline std::set<QueryResult::line_no>::iterator QueryResult::begin() const
 * {
 *     return lines->begin();
 * }
 * inline std::set<QueryResult::line_no>::iterator QueryResult::end() const
 * {
 *     return lines->end();
 * }
 * inline std::shared_ptr<std::vector<std::string>> QueryResult::get_file() const
 * {
 *     return file;
 * }  */

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< (qr.lines->size() == 1 ? "time" : "times") << std::endl;

	for (auto num: *qr.lines)
		os << "\t(line " << num + 1 << ") "
			<< *(qr.file->begin() + num) << std::endl;
	return os;
}



