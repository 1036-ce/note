#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <type_traits>

class Screen {
	public:
		typedef std::string::size_type pos;
		friend class Window_mgr;
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

class Window_mgr {
	public:
		using ScreenIndex = std::vector<Screen>::size_type;
		void clear(ScreenIndex);
	private:
		std::vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i) 
{
	Screen s = screens[i];
	s.contents = std::string(s.width * s.height, ' ');
}

int main(void)
{
	return 0;
}


