#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(void)
{
	unordered_map<string, size_t> word_count;
	string word;
	while (cin >> word)
		++word_count[word];
	for (const auto &w: word_count)
		cout << "\" " <<  w.first << " \"" << " occurs " << w.second 
			<< ((w.second > 1) ? " times" : " time") << endl;
	return 0;
}
