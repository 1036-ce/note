#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include "debug_rep.h"

using namespace std;


int main(void)
{
	cout << debug_rep("123123") << endl;
	char p[] = "12312123123123123123121231";
	cout << debug_rep(p) << endl;
	return 0;
}
