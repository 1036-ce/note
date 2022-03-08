#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Quote.h"

using namespace std;

int main(void)
{
	Quote q("123",10);
	Bulk_Quote bq("1234", 3, 1, 0.1);
	vector<Quote> vec;
	vec.push_back(q);
	vec.push_back(bq);
	int sum = 0;
	for_each(vec.begin(), vec.end(),[&sum](const Quote &q) { sum += q.net_price(1); });
	cout << sum << endl;
	return 0;
}
