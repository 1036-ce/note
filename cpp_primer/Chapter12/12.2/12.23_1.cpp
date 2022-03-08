#include <iostream>
#include <string>
#include <memory>
#include <cstring>

using namespace std;

int main(void)
{
	char a[] = "123", b[] = "456";
	char *ans = new char[strlen(a) + strlen(b)];
	strcpy(ans, a);
	strcpy(ans + strlen(a), b);
	cout << ans << endl;
	return 0;
}
