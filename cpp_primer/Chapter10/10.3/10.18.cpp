#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto it = unique(words.begin(), words.end());
	words.erase(it, words.end());
}

string make_plural(int count, const string &a, const string &b)
{
	return count > 1 ? a + b : a;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(),
			[] (const string &a, const string &b) { return a.size() < b.size();});

	// auto wc = find_if(words.begin(), words.end(), 
			// [sz] (const string &a) { return a.size() >= sz; });

	auto wc = partition(words.begin(), words.end(),
			[sz] (const string &a) {return a.size() < sz;});
	
	auto count = words.end() - wc;

	cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer " << endl;

	for_each(wc, words.end(), [] (const string &s) { cout << s << " " ;});
	cout << endl;
}

int main(void)
{
	vector<string> vec{"the","quick","red","fox","jumps","over","the","slow","red","turtl"};
	biggies(vec, 4);
	return 0;
}

