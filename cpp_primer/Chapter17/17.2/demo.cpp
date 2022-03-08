#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

int main(void)
{
	bitset<8> b("10101010");
	cout << "any(): " << b.any() << endl;
	cout << "all(): " << b.all()  << endl;
	cout << "none(): " << b.none() << endl;
	cout << "count(): " << b.count() << endl;
	cout << "size(): " << b.size() << endl;
	cout << "b[2]: " << b[2] << endl;
	cout << b.to_ulong() << endl;
	cout << b.to_string() << endl;
	return 0;
}
