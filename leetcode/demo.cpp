#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
	double myPow(double x, long long n) {
		if (n == 0) return 1;
		if (n < 0) {
			x = 1.0 / x;
			n = -n;
		}
		double num = 1.0;
		while (n != 1) {
			if (n & 1) 
				num *= x;
			x = x * x;
			n = n >> 1;
		}
		return x * num;
	}
};

int main(void)
{
	vector<int> vec{1,2,3};
	cout << vec.size() << endl;
	return 0;
}
