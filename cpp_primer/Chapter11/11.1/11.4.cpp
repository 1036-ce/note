#include <cctype>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;

void change(string &word)
{
	string target{",.?!"};
	auto it = word.find_first_of(target);
	if (it != string::npos)
		word.erase(it);
	for (auto i = word.begin(); i != word.end() ; ++i)
	{
		*i = tolower(*i);
	}
}
int main(void)
{
	map<string, size_t> word_count;
	string word;
	while (cin >> word)
	{
		change(word);
		++word_count[word];
	}
	for (const auto &w: word_count)
		cout << w.first << " occurs " << w.second
			<< ((w.second > 1) ? " times" : "time") << endl;
	return 0;
}
