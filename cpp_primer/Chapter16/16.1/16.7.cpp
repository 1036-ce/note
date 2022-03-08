#include <iostream>

using namespace std;

template<typename T, unsigned N> constexpr
unsigned size(T (&arr)[N])
{
	return N;
}

int main(void)
{
	int arr[] = {112,21,33,34,34,5546,23,4546,68,6787,12};
	cout << size(arr) << endl;
	return 0;
}
