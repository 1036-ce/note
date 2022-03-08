#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

bool valid(const smatch &m)
{
	if (m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched && m[4].str() == m[6].str();
}

int main(void)
{
	string phone = 
		"(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	regex r(phone);
	string fmt = "$2.$5.$7";
	string number = "12312(908) 555-1800";
	cout << regex_replace(number, r, fmt, regex_constants::format_no_copy) << endl;
	return 0;
}
