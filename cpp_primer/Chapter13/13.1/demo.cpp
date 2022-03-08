#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "../StrBlob.h"

using namespace std;

int main(void)
{
	// vector<string> vec{"12","1234"};
	StrBlob sb({"12", "123"});
	StrBlob sb1 = sb;
	StrBlobPtr sbp = sb;
	return 0;
}
