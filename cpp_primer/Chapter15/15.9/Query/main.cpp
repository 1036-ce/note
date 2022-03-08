#include <cstdlib>
#include <iostream> 
#include <iterator>
#include <sstream>
#include <string>
#include <fstream> 
#include <stack>
#include <type_traits>
#include "TextQuery.h"
#include "Query.h"

using namespace std;

void calc(char sym, stack<Query>& query_stack)
{
	switch (sym)
	{
		case '~':
			{
				Query q = query_stack.top();
				query_stack.pop();
				query_stack.push(~q);
				break;
			}
		case '|':
			{
				Query q1 = query_stack.top();	query_stack.pop();
				Query q2 = query_stack.top();	query_stack.pop();
				query_stack.push(q2 | q1);
				break;
			}
		case '&':
			{
				Query q1 = query_stack.top();	query_stack.pop();
				Query q2 = query_stack.top();	query_stack.pop();
				query_stack.push(q2 & q1);
				break;
			}
	}
}

void init(string &s)
{
	string target = "~&|()";
	string::size_type pos = 0;
	while ((pos = s.find_first_of(target, pos)) != string::npos)
	{
		auto ins = inserter(s, s.begin() + pos);
		*ins = ' ';
		ins = inserter(s, s.begin() + pos + 2);
		*ins = ' ';  
		pos += 2;
	}
}
void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	stack<Query> query_stack;
	stack<string> symbol_stack;
	while (true)
	{
		cout << "Executing Query for ('q' for quit): ";
		string s, word;
		getline(cin, s);
		if (s == "q") break;
		init(s);
		istringstream is(s);
		while (is >> word)
		{
			if (word == "&" || word == "|" || word == "~" || word == "(")
				symbol_stack.push(word);
			else if (word == ")")	//处理右括号
			{
				while (symbol_stack.top() != "(")
				{
					char sym = symbol_stack.top()[0];
					symbol_stack.pop();
					calc(sym, query_stack);
				}
				symbol_stack.pop();
			}
			else	// 处理单词
			{
				query_stack.push(Query(word));
				if (symbol_stack.empty() || symbol_stack.top() == "(")
					continue;
				char sym = symbol_stack.top()[0];
				symbol_stack.pop();
				calc(sym, query_stack);
			}
		}

		while (!symbol_stack.empty())
		{
			char sym = symbol_stack.top()[0];
			symbol_stack.pop();
			calc(sym, query_stack);
		}
		Query q = query_stack.top();
		auto ans = q.eval(tq);
		print(cout, ans);
		query_stack.pop();
	}
}

int main()
{
	ifstream is("in");
	runQueries(is);
	/* TextQuery tq(is);
	 * Query q = Query("fiery") & Query("bird");
	 * q = q | Query("wind");
	 * auto ans = q.eval(tq);
	 * print(cout, ans) << endl; */
	return 0;	 
}
