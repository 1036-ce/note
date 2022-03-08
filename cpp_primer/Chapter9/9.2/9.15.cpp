#include <iostream>
#include <vector>

using namespace std;

//if v1 == v2 returun 1, else return 0;
int equal(vector<int>& v1, vector<int> &v2)
{
	if (v1.size() > v2.size())
		return 1;
	if (v1.size() < v2.size())
		return 0;

	for (auto i = 0; i != v1.size(); ++i) {
		if(v1[i] != v2[i])
			return 0;
	}
	return 1;
}
int main(void)
{
	vector<int> v1{1,2,3,4};
	vector<int> v2{1,2,3,4};
	cout << equal(v1, v2) << endl;
	vector<int> v3{1,2,4,4};
	cout << equal(v1, v3) << endl;
	vector<int> v4{1,2,2,4};
	cout << equal(v1, v4) << endl;
	return 0;
}
