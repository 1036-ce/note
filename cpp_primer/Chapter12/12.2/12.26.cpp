#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int main(void)
{
	int n = 10;
	allocator<string> alloc;
	string *const p = alloc.allocate(n);
	string s;
	string *q = p;
	while (cin >> s && q != p + n)
		alloc.construct(q++, s);
	const size_t size = q - p;
	while (q != p)
		alloc.destroy(--q);
	alloc.deallocate(p, n);
	return 0;
}
