#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <cctype>
#include <endian.h>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

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


class QueryResult {
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	using line_no = std::vector<std::string>::size_type;

	std::set<line_no>::iterator begin() const
	{ return lines->begin(); }
	std::set<line_no>::iterator end() const
	{ return lines->end(); }
	std::shared_ptr<std::vector<std::string>> get_file() const
	{ return file; }

	QueryResult(std::string s,
				std::shared_ptr<std::set<line_no>> p,
				std::shared_ptr<std::vector<std::string>> f):
		sought(s), lines(p), file(f) {  }
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

std::ostream& print(std::ostream&, const QueryResult&);

#endif
