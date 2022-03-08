#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template<typename T, unsigned N>
T *mybegin(T (&arr)[N])
{
	return &arr[0];
}

template<typename T, unsigned N>
T *myend(T (&arr)[N])
{
	return &arr[N];
}
int main(void)
{
	int arr[] = {1,234,123,564,756,12312};
	auto beg = mybegin(arr);
	auto ed = myend(arr) - 1;
	cout << *beg << endl;
	cout << *ed << endl;
	return 0;
}
