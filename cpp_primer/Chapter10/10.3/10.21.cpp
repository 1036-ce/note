#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int v = 10;
	auto f = [v] () mutable -> bool { 
		if (v == 0)
			return true; 
		else 
			--v; 
		return false; };

	int i = 0;
	while (!f()) {
		++i;
	}
	cout << i << endl;
	
	return 0;
}

