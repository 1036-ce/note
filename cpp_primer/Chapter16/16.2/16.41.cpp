#include <fstream>
#include <iostream>
#include <ostream>
#include <memory>
#include <vector>
#include <type_traits>

using namespace std;

template <typename T>
auto sum(T lhs, T rhs) -> decltype(lhs + rhs)
{
	return lhs + rhs;
}

int main(void)
{
	auto ans = sum(1234567898768765432, 23899876544568765);
	cout << ans << endl;
	return 0;
}
