#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main(void)
{
	unsigned seed;
	unsigned min, max;
	cout << "seed: ";
	cin >> seed;
	cout << "min: ";
	cin >> min;
	cout << "max: ";
	cin >> max;
	default_random_engine e(seed);
	uniform_int_distribution<unsigned> u(min, max);
	for(int i = 0; i< 10; ++i)
		cout << u(e) << endl;
	return 0;
}
