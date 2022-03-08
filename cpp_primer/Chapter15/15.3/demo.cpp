#include <iostream>
#include <ostream>
#include <string>

using namespace std;

class base {
public:
	string name() {cout << "1" ; return basename; }
	virtual void print(ostream &os) { os << basename; os << "base" << endl;}
private:
	string basename;
};

class derived : public base {
public:
	void print(ostream &os) override { base::print(os); os << " " << i; os << "derived" << endl;} 
private:
	int i;
};

int main(void)
{
	base bobj;
	base *bp1 = &bobj;
	base &br1 = bobj;
	derived dobj;
	base *bp2 = &dobj;
	base &br2 = dobj;
	/* bobj.print(cout);
	 * dobj.print(cout);
	 * bp1->name(); 
	 * bp2->name(); */
	// br1.print(cout);
	br2.print(cout); 
	return 0;
}
