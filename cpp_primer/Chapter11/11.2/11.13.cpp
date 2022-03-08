#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main(void)
{
	vector<pair<string, int>> vec;
	//第一种方法
	/* pair<string, int> p;
	 * while (cin >> p.first >> p.second)
	 *     vec.push_back(p); */

	//第二种方法
	/* string s;
	 * int n;
	 * while (cin >> s >> n)
	 *     vec.push_back(make_pair(s, n)); */

	//第三种方法
	/* string s;
	 * int n;
	 * pair<string, int> p;
	 * while (cin >> s >> n)
	 * {
	 *     p = {s, n};
	 *     vec.push_back(p);
	 * } */

	for (const auto &i: vec)
		cout << i.first << " " << i.second << endl;
	return 0;
}
