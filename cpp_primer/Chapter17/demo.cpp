#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main(void)
{
	tuple<int, int, int> t(12,123,1234);
	cout << get<1>(t) << endl;
	return 0;
}
