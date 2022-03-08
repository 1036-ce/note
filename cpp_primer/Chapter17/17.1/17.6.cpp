#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Sales_data.h"

using namespace std;

struct matches{
	matches(vector<Sales_data>::size_type s,
			vector<Sales_data>::const_iterator l,
			vector<Sales_data>::const_iterator r): st(s), lhs(l), rhs(r) {  }
	vector<Sales_data>::size_type st;
	vector<Sales_data>::const_iterator lhs, rhs;
};

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

vector<matches>
findbook(const vector<vector<Sales_data>> &files, const string &book)
{
	vector<matches> ret;

	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second)
			ret.push_back(matches(it - files.cbegin(), found.first, found.second));
	}
	return ret;
}

int main(void)
{
	
	return 0;
}
