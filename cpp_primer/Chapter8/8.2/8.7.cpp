#include <fstream>
#include <iostream>
#include "Sales_data.h"

using namespace std;

int main(int argc, char **argv)
{
	Sales_data total;
	ifstream is(argv[1], ifstream::in);
	ofstream os(argv[2], ofstream::out);

	if(read(is, total)) {
		Sales_data trans;
		while(read(is,trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(os, total) << endl;
				total = trans;
			}
		}
		print(os, total) << endl;
	} else {
		cerr << "No data?!" << endl;
	}
	return 0;
}
