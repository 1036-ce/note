#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date {
	public:
		Date(const string &s)
		{
			string target("0123456789");
			int num   = s.find_last_of(target);
			num   = s.find_last_not_of(target, num);
			year  = stoul(s.substr(num + 1));

			num   = s.find_last_of(target, num);
			num   = s.find_last_not_of(target, num);
			day = stoul(s.substr(num + 1));

			num   = s.find_last_of(target, num);
			if (num == string::npos) 
			{
				string t1("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
				num = s.find_first_of(t1);
				string subs = s.substr(num, 3);
				if (subs == "Jan") month = 1;
				else if (subs == "Feb") month = 2;
				else if (subs == "Mar") month = 3;
				else if (subs == "Apr") month = 4;
				else if (subs == "May") month = 5;
				else if (subs == "Jun") month = 6;
				else if (subs == "Jul") month = 7;
				else if (subs == "Aug") month = 8;
				else if (subs == "Sep") month = 9;
				else if (subs == "Oct") month = 10;
				else if (subs == "Nov") month = 11;
				else if (subs == "Dec") month = 12;
			}
			else 
			{
				num = s.find_last_not_of(target, num);
				month = stoul(s.substr(num + 1));
			}
		}
		void show()
		{
			cout << day << " " << month << " " << year << endl;
		}
		Date(): day(0), month(0), year(0) {}
	private:
		unsigned day, month, year;
};

int main(void)
{
	Date d("Jan 1 1900");
	d.show();
	Date d1("1/1/1900");
	d1.show();
	Date d2("January 1, 1900");
	d2.show();
	return 0;
}
