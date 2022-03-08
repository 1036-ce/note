#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct PersonInfo{
	string name;
	vector<string> phones;
};

int main(void)
{
	string line, word;
	vector<PersonInfo> people;
	istringstream record;

	while(getline(cin, line)) {
		PersonInfo info;
		record.str(line);
		record >> info.name;
		while (record >> word) 
			info.phones.push_back(word);
		people.push_back(info);
		record.clear();		//将record的所有条件状态复位
	}

	for (auto i: people) {
		cout << i.name << " : ";
		for (auto j: i.phones) 
			cout << j ;
		cout << endl;
	}
	return 0;
}
