#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include "Sales_data.h"

using namespace std;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

int main(void)
{
	// 下面两个都可以
	// typedef bool F(const Sales_data&, const Sales_data&);
	using F = bool(const Sales_data&, const Sales_data&);

	multiset<Sales_data, F*> bookstre(compareIsbn);
	return 0;
}

