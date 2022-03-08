#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, string> build_map(ifstream &map_file)
{
	unordered_map<string, string> trans_map;
	string key, value;

	while (map_file >> key && getline(map_file, value))
	{
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			throw runtime_error("no rule for " + key);
	}
	return trans_map;
}

const string& 
transform(const string &s, const unordered_map<string, string> &m)
{
	auto map_it = m.find(s);
	if (map_it == m.end())
		return s;
	else
		return map_it->second;
}
void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = build_map(map_file);
	string text;
	while (getline(input, text))
	{
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word)
		{
			if (firstword)
				firstword = false;
			else
				cout << " ";
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

int main(int argc, char **argv)
{
	ifstream map_file(argv[1], ifstream::in), input(argv[2], ifstream::in);
	word_transform(map_file, input);
	return 0;
}
