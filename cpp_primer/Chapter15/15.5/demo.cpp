#include <iostream>

using namespace std;

class Base {
public:
	void pub_mem();
protected:
	int prot_mem;
private:
	char priv_mem;
};

struct Pub_Derv : public Base {
	int f() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv : private Base {
	int f1() const { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

struct Prot_Derv : protected Base {
	int f2() const { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv {
	int use_base() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Private : public Priv_Derv {
	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Protected : public Prot_Derv {
	void memfcn(Base &b) { b = *this; }
};

int main(void)
{
	return 0;
}
