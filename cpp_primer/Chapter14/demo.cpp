#include <iostream>
#include "StrBlob.h"

using namespace std;

int main(void)
{
	StrBlob sb({"123", "456", "7890"});
	StrBlobPtr sbp(sb, 0);
	cout << *sbp << endl;
	cout << sbp->front() << endl;
	return 0;
}
