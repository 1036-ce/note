#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

int main(void)
{
	tuple<string, vector<string>, pair<string, int>>
		t("123", {"12", "123"}, make_pair("123", 12));
	auto it = get<2>(t);
	cout << it.first << endl;
	cout << it.second << endl;
	return 0;
}
