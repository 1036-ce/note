#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include "Sales_data.h"

using namespace std;

int main(void)
{
	unordered_multiset<Sales_data> sd;
	sd.insert(Sales_data("12424"));
	sd.insert(Sales_data("12098"));
	sd.insert(Sales_data("124"));
	sd.insert(Sales_data("1233"));
	sd.insert(Sales_data("324"));

	for (auto i: sd)
	    cout << i << endl; 
	return 0;
}
