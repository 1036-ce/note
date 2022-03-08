#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main(void)
{
	list<const char*> lt{"1", "2", "3", "4"};
	vector<string> vec;
	vec.assign(lt.begin(), lt.end());
	return 0;
}
