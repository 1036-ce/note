#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

template <typename elemType> class ListItem;

/* template <typename elemType> class List {
 * public:
 *     List<elemType>();
 *     List<elemType>(const List<elemType> &);
 *     List<elemType>& operator=(const List<elemType> &);
 *     ~List();
 *     void insert(ListItem *ptr, elemType value);
 * private:
 *     ListItem *front, *end;
 * };
 *  */

template <typename elemType> class List {
public:
	List();
	List(const List<elemType> &);
	List& operator=(const List<elemType> &);
	~List();
	void insert(ListItem<elemType> *ptr, elemType value);
private:
	ListItem<elemType> *front, *end;
};


int main(void)
{
	
	return 0;
}
