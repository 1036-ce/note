#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main(void)
{
	list<string> lst{"12","12","2","4","2","2","123"};
	lst.unique();
	return 0;
}
