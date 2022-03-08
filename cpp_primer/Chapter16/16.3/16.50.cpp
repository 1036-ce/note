#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

template <typename T> void f(T a) {
	cout << "f(T)" << endl;
}
template <typename T> void f(const T* a) {
	cout << "f(const T*)" << endl;
}
template <typename T> void g(T a) {
	cout << "g(T)" << endl;
}
template <typename T> void g(T* a) {
	cout << "g(T*)" << endl;
}

int main(void)
{
	int i = 42, *p = &i;
	const int ci = 0, *p2 = &ci;
	g(42);	// -> g(T)
	g(p);	// -> g(T*)
	g(ci);	// -> g(T)
	g(p2);	// -> g(T*)
	f(42);	// -> f(T)
	f(p);	// -> f(T)
	f(ci);	// -> f(T)
	f(p2);	// -> f(const T*)
	return 0;
}
