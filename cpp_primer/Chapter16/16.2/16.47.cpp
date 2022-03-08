#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <type_traits>
#include <functional>
#include <typeinfo>

using namespace std;

template <typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2)
{
	f(std::forward<T2>(t2),std::forward<T1>(t1));
}

void g(int &&i, int &j)
{
	cout << i << " " << j << endl;
} 

int main(void)
{
	int i = 1;
	flip2(g, i, 42);
	return 0;
}
