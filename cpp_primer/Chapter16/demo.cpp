#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main(void)
{
	int i = 12;
	int i1 = 13;
	const int *p = &i;		//底层const
	int const *p = &i;		//底层const
	int* const p = &i;		//顶层const
	return 0;
}
