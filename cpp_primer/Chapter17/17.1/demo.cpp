#include <iostream>
#include <tuple>
#include <algorithm>
#include <numeric>
#include "Sales_data.h"

using namespace std;

tuple<int, int> f()
{
	return tuple<int, int>(1,2);
}

int main(void)
{
	Sales_data a("1", 12, 1.2);
	Sales_data b("2", 1, 1.2);
	Sales_data c = a + b;
	cout << c << endl;
	/* auto a = f();
	 * cout << get<0>(a) << endl;
	 * cout << get<1>(a) << endl;
	 * accumulate() */
	return 0;
}
