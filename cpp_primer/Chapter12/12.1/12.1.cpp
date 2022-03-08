#include <iostream>
#include <vector>
#include <string>
#include "../StrBlob.h"

using namespace std;

int main(void)
{
	StrBlob b1;
	{
		StrBlob b2 = {"a", "an", "the"};
		b1 = b2;
		b2.push_back("about");
	}
	//这段代码结束时，b1包含4个元素，而b2已经被销毁
	return 0;
}
