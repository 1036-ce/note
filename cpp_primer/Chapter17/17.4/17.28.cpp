#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

int main(void)
{
	default_random_engine e(time(0));
	uniform_int_distribution<unsigned> u;
	for(int i = 0; i< 10; ++i)
		cout << u(e) << endl;
	return 0;
}
