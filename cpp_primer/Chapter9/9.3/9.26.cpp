#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(void)
{
	int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
	vector<int> vec;
	list<int> lst;

	for(int i = 0; i < 11; ++i) {
		vec.push_back(ia[i]);
		lst.push_back(ia[i]);
	}

	auto it1 = lst.begin();
	while (it1 != lst.end()) {
		if (*it1 % 2 == 1)
			it1 = lst.erase(it1);
		else
			++it1;
	}
	for (auto i: lst)
	    cout << i << endl; 
 
    cout << endl;

	auto it2 = vec.begin();
	while (it2 != vec.end()) {
		if (*it2 % 2 == 0)
			it2 = vec.erase(it2);
		else
			++it2;
	}
	for (auto i: vec)
        cout << i << endl;    
	return 0;
}
