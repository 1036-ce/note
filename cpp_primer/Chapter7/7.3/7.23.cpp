#include <iostream>
#include <string>

class Screen {
	public:
		typedef std::string::size_type pos;
	private:
		pos cursor = 0;
		pos width = 0, height = 0;
		std::string contents;
};
int main(void)
{
	
	return 0;
}
