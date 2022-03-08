#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class numbered {
friend void f(numbered);
// friend void f(const numbered&);
public:
	static int n;

	numbered():mysn(n++) {}
	numbered(const numbered &nb)
	{
		mysn = n++;
	} 
private:
	int mysn;
};
int numbered::n = 0;

void f(numbered s)
{
	cout << s.mysn << endl;
}
/* void f(const numbered &s)
 * {
 *     cout << s.mysn << endl;
 * }  */

int main(void)
{
	numbered a, b = a, c = a;
	f(a); f(b); f(c);
	return 0;
}
