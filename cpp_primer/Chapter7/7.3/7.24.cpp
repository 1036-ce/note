#include <iostream>
#include <string>

class Screen {
	public:
		typedef std::string::size_type pos;
		Screen() = default;
		Screen(pos wd, pos ht): width(wd), height(ht), contents(wd * ht, ' ') {}
		Screen(pos wd, pos ht, char c): width(wd), height(ht), contents(wd * ht, c) {}
	private:
		pos cursor = 0;
		pos width = 0, height = 0;
		std::string contents;
};
int main(void)
{
	
	return 0;
}
