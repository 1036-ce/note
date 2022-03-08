#include <iostream>
#include <vector>
#include <list>

using namespace std;

bool equal(list<int> &lt, vector<int> &vec) 
{
	if (lt.size() != vec.size()) 
		return false;
	auto iter1 = lt.begin();
	auto iter2 = vec.begin();
	while (iter1 != lt.end()) {
		if (*iter1 != *iter2)
			return false;
		++iter1, ++iter2;
	}
	return true;
}
int main(void)
{
	list<int> lt{1,2,3,4};
	vector<int> vec{1,2,3,4};
	cout << equal(lt, vec) << endl;
	vector<int> vec1{1,2,3};
	cout << equal(lt, vec1) << endl;
	vector<int> vec2{1,2,2,4};
	cout << equal(lt, vec2) << endl;
	vector<int> vec3{1,2,4,4};
	cout << equal(lt, vec3) << endl;
	return 0;
}
