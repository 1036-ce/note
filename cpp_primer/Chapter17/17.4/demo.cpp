#include <cstddef>
#include <ctime>
#include <iostream>
#include <sched.h>
#include <string>
#include <vector>
#include <random>
#include <cmath>

using namespace std;

bool play(bool i)
{
	return true;
}

int main(void)
{
	default_random_engine e;
	bernoulli_distribution b;
	string resp;
	do {
		bool first = b(e);
		cout << (first ? "We go first"
					   : "You get to go first") << endl;
		cout << ((play(first)) ? "sorry, you lost"
							   : "congrats, you won") << endl;
		cout << "play again ? Enter 'yes' or 'no'" << endl;
	}while (cin >> resp && resp[0] == 'y');
	return 0;
}
