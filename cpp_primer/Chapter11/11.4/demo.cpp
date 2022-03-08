#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iterator>

using namespace std;

int main(void)
{
	unordered_map<int, int> um;
	hash<string> a;
	um.insert({1,2});
	cout << um.bucket_count() << endl;
	cout << um.max_bucket_count() << endl;
	cout << um.load_factor() << endl;
	return 0;
}
