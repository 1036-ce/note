#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include "Sales_data.h"

using namespace std;

typedef pair<vector<Sales_data>::size_type, 
			pair<vector<Sales_data>::const_iterator, 
				vector<Sales_data>::const_iterator>>	matches;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

vector<matches>
findbook(const vector<vector<Sales_data>> &files, const string &book)
{
	vector<matches> ret;

	for (auto it = files.cbegin(); it != files.cend(); ++it)
	{
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second)
			ret.push_back(make_pair(it - files.cbegin(),
									make_pair(found.first, found.second)));
	}
	return ret;
}

int main(void)
{
	return 0;
}
