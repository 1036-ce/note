#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include "Quote.h"

using namespace std;

int main(void)
{
	Quote q("123",10);
	Bulk_Quote bq("1234", 3, 1, 0.1);
	vector<shared_ptr<Quote>> vec;
	vec.push_back(make_shared<Quote>(q));
	vec.push_back(make_shared<Bulk_Quote>(bq));
	int sum = 0;
	for_each(vec.begin(), vec.end(),
			[&sum](shared_ptr<Quote> qp)  { sum += qp->net_price(1); });
	cout << sum << endl;
	return 0;
}
