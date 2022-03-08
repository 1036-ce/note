#include <iostream>
#include <ostream>
#include <string>
#include <type_traits>

class Screen {
	public:
		typedef std::string::size_type pos;
		Screen() = default;
		Screen(pos wd, pos ht): width(wd), height(ht), contents(wd * ht, ' ') {}
		Screen(pos wd, pos ht, char c): width(wd), height(ht), contents(wd * ht, c) {}

		Screen &move(pos row, pos col) 
		{
			cursor = row * width + col;
			return *this;
		}
		Screen &set(char c) 
		{
			contents[cursor] = c;
			return *this;
		}
		Screen &set(pos row, pos col, char c)
		{
			contents[row * width + col] = c;
			return *this;
		}
		Screen &display(std::ostream& os)
		{
			do_display(os);
			return * this;
		}
		const Screen &display(std::ostream& os) const
		{
			do_display(os);
			return * this;
		}
	private:
		void do_display(std::ostream& os) const
		{
			os << contents;
		}
		pos cursor = 0;
		pos width = 0, height = 0;
		std::string contents;
};
int main(void)
{
	Screen myscreen(5, 5, 'X');
	myscreen.move(4,0).set('#').display(std::cout);
	std::cout << "\n";
	myscreen.display(std::cout);
	std::cout << "\n";
	return 0;
}


