#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main(void)
{
	unsigned seed;
	cout << "seed: ";
	cin >> seed;
	default_random_engine e(seed);
	uniform_int_distribution<unsigned> u;
	for(int i = 0; i< 10; ++i)
		cout << u(e) << endl;
	return 0;
}
