#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

template <typename T>
unsigned count(vector<T> vec, T t)
{
	unsigned ret = 0;
	auto it = vec.begin();
	while (it != vec.end())
	{
		if (*it == t)
			++ret;
		++it;
	}
	return ret;
}

template<>
unsigned count(vector<const char*> vec, const char* t)
{
	unsigned ret = 0;
	auto it = vec.begin();
	while (it != vec.end())
	{
		if (!strcmp(*it, t))
			++ret;
		++it;
	}
	return ret;

}

int main(void)
{
	vector<double> vecd{1.2,1.3,1.4,1.5,1.4};
	vector<int> veci{1,2,3,4,3,4,3,1};
	vector<string> vecs{"123","23123","123","534"};
	vector<const char*> vecc{"123", "1231", "123", "121212"};

	cout << count(vecd, 1.4) << endl;
	cout << count(veci, 2) << endl;
	cout << count(vecs, string("123")) << endl;
	cout << count(vecc, "23") << endl;
	return 0;
}
