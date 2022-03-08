#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

int main(void)
{
	vector<string> vec{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
	/* for (auto i: vec)
	 *     cout << i << endl; 
	 * cout << endl; */
	cout << vec.size() << endl;
	sort(vec.begin(), vec.end());
	auto it = unique(vec.begin(), vec.end());
	cout << vec.size() << endl;
	cout << *(vec.end() - 1) << endl;
	/* for (auto i: vec)
	 *     cout << i << endl;  */
	vec.erase(it, vec.end());
	cout << vec.size() << endl;
	/* cout << endl;
	 * for (auto i: vec)
	 *     cout << i << endl;  */
	return 0;
}
