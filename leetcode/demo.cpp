#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <tuple>

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
	int a = 1, b = 2;
	tie(a, b) = pair(b * 12 - 2, a * 21 - 3);
	cout << a << endl;
	cout << b << endl; 
	return 0;
}
