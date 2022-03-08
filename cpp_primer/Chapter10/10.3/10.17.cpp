#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Sales_data.h"

using namespace std;

/* bool compareIsbn(Sales_data &sd1, Sales_data &sd2)
 * {
 *     return sd1.isbn().size() < sd2.isbn().size();
 * } */

int main(void)
{
	vector<Sales_data> vec{string("1212133"),string("1234"),string("12345")};
	sort(vec.begin(), vec.end(),
			[] (Sales_data &sd1, Sales_data &sd2)
			    { return sd1.isbn().size() < sd2.isbn().size(); });
	for (auto i: vec)
		cout << i.isbn() << endl;
	return 0;
}

