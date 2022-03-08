#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(void)
{
	list<int> lt{1,2,3,4};
	vector<double> vec(lt.begin(), lt.end());
	for (auto i: vec)
		cout << i << endl;
	vector<int> v1{1,2,3,4};
	vector<double> vec1(v1.begin(), v1.end());
	for (auto i: vec)
		cout << i << endl;
	return 0;
}
