#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	fstream inOut("in", fstream::ate | fstream::in | fstream::out);
	if (!inOut)
	{
		cerr << "Unable to open file" << endl;
		return EXIT_FAILURE;
	}

	auto end_mark = inOut.tellg();
	inOut.seekg(0, fstream::beg);
	size_t cnt = 0;
	string line;
	while (inOut && inOut.tellg() != end_mark && getline(inOut, line))
	{
		cnt += line.size() + 1;
		auto mark = inOut.tellg();
		inOut.seekp(0, fstream::end);
		inOut << cnt;

		if (mark != end_mark) inOut << " ";
		inOut.seekg(mark);
	}
	inOut.seekp(0, fstream::end);
	inOut << "\n"; 
	return 0;
}
