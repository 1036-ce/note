#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T, unsigned N>
void print(T (&arr)[N])
{
	for (auto i: arr)
		cout << i << " ";
	cout << endl;
}
int main(void)
{
	int arr[]={1,2,4,1,23,4,23,5,466,74};
	print(arr);
	string str[] = {"1231", "45345d", "asads", "213123"};
	print(str);
	return 0;
}
