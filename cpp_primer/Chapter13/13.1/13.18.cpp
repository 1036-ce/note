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
		EmpNo = num++;
	}

	Employee(const Employee &dest)
	{
		name = dest.name;
		EmpNo = num++;
	}

	Employee &operator=(const Employee &dest)
	{
		name = dest.name;
		EmpNo = num++;
		return *this;
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
