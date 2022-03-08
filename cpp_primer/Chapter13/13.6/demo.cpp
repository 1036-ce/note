#include <algorithm>
#include <iostream>
#include <sched.h>
#include <string>
#include <utility>
#include <vector>
#include <memory>
#include "StrVec.h"

using namespace std;

int main(void)
{
	string s1("123");
	StrVec vec;
	vec.push_back(s1);
	vec.push_back("123");
	return 0;
}
