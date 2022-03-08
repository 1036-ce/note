#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	map<string, vector<int>> m{{"123", {1,2,3}}};
	map<string, vector<int>>::iterator it = m.find("123");
	for (auto i: it->second)
		cout << i << endl;
	return 0;
}
