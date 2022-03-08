#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
public:
	static unsigned num;
	Employee(const string s): name(s)
	{
		EmpNo = ++num;
	}
private:
	string name;
	unsigned EmpNo;
};
unsigned Employee::num = 0;

int main(void)
{
	Employee a("asd");

	return 0;
}
