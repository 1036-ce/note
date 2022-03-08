#include <iostream>
#include <map>
#include <string>

using namespace std;

void show(multimap<string, string> m)
{
	for (auto i: m)
		cout << i.first << " " << i.second << endl;
}
int main(void)
{
	multimap<string, string> author_book_map;
	string author, book;
	while (cin >> author >> book)
		author_book_map.insert({author, book});
	show(author_book_map);
	return 0;
}
