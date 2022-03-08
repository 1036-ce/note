#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class DebugDelete {
public:
	DebugDelete(std::ostream &s = std::cerr): os(s) {  }
	template <typename T> void operator() (T *p) const
	{ os << "deleteing unique_ptr" << std::endl; delete p;}
private:
	std::ostream &os;
};

int main(void)
{
	unique_ptr<int, DebugDelete> p(new int, DebugDelete());
	unique_ptr<string,	DebugDelete> sp(new string, DebugDelete());
	return 0;
}
