#include <iostream>
#include <string>

using namespace std;

class Base1 {
public:
	virtual void print() { cout << "Base1" << endl; }
	virtual ~Base1() {
		cout << "~Base1" << endl;
	}
};

class Base2 {
public:
	virtual void print() { cout << "Base2" << endl; }
	virtual ~Base2() { 
		cout << "~Base2" << endl;
	}
};

class D1: public Base1 {
public:
	void print() override
	{ cout << "D1" << endl; }
	~D1() {  
		cout << "~D1" << endl;
	}
};

class D2: public Base2 {
public:
	void print() override 
	{ cout << "D2" << endl; }
	~D2() {  
		cout << "~D2" << endl;
	}
};

class MI: public D1, public D2 {
public:
	void print() override
	{ cout << "MI" << endl; }
	~MI() {  
		cout << "~MI" << endl;
	}
};

int main(void)
{
	Base1 *pb1 = new MI;
	Base2 *pb2 = new MI;
	D1 *pd1 = new MI;
	D2 *pd2 = new MI;
	pb1->print();
	pd1->print();
	pd2->print();
	cout << endl;
	delete pb2;
	cout << endl;
	delete pd1;
	cout << endl;
	delete pd2;
	cout << endl;
	return 0;
}
