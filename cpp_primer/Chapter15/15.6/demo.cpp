#include <iostream>
#include <vector>

using namespace std;

class Base {
public:
	virtual int fcn()
	{
		cout << "Base::fcn" << endl;
		return 1;
	}
};

class D1 : public Base {
public:
	int fcn()
	{
		cout << "D1::fcn" << endl;
		return 1;
	}
	virtual void f2()
	{
		cout << "D1::f2" << endl;
	}
};

class D2 : public D1 {
public:
	int fcn(int) { return 1; }
	int fcn()
	{
		cout << "D2::fcn" << endl;
		return 1;
	}
	void f2(){
		cout << "D2::f2" << endl;
	}
};
int main(void)
{
	Base bobj;
	D1 d1obj;
	D2 d2obj;
	Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
	bp1->fcn();
	bp2->fcn();
	bp3->fcn();

	D1 *d1p = &d1obj;
	D2 *d2p = &d2obj;
	// bp2->f2();
	d1p->f2();
	d2p->f2();
	return 0;
}
