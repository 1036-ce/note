#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
int compare(const T &v1, const T &v2)
{
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

int main(void)
{
	int ans = compare<string>("123", "12");
	cout << ans << endl;
	return 0;
}
