#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s("ab2c3d7R4E6");
	string num("0123456789");
	string alpha("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

	string::size_type pos = 0;

	cout << "num" << endl;
	while ((pos = s.find_first_of(num, pos)) != string::npos) 
	{
		cout << "pos: " << pos << " value: " << s[pos] << endl;
		++pos;
	}

    cout << "alpha" << endl;
	pos = 0;
	while ((pos = s.find_first_of(alpha, pos)) != string::npos) 
	{
		cout << "pos: " << pos << " value "	<< s[pos] << endl;
		++pos;
	}


	cout << "num" << endl;
	pos = 0;
	while ((pos = s.find_first_not_of(alpha, pos)) != string::npos) 
	{
		cout << "pos: " << pos << " value: " << s[pos] << endl;
		++pos;
	}

	cout << "alpha" << endl;
	pos = 0;
	while ((pos = s.find_first_of(num, pos)) != string::npos) 
	{
		cout << "pos: " << pos << " value "	<< s[pos] << endl;
		++pos;
    } 
	return 0;
}
