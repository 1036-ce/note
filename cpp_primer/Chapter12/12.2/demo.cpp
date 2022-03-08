#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int main(void)
{
	allocator<int> alloc;
	auto p = alloc.allocate(10);
	vector<int> vec{1,2,3,4,5};
	// uninitialized_copy(vec.begin(), vec.end(), p);
	uninitialized_fill_n(p, 5, 12);
	for (int i = 0; i < 5; ++i)
		cout << p[i] << endl;
	return 0;
}
