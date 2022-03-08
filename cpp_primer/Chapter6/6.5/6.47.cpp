#include <iostream>
#include <vector>

using namespace std;

void show_vector(vector<int>::iterator beg, vector<int>::iterator end )
{
#ifndef NDEBUG
	cout<<"size:"<<end - beg<<endl;
#endif
	if (beg == end) 
		return;
	cout<<*beg<<endl;
	show_vector(beg + 1,end);
}
int main(void)
{
	vector<int> vi{1,2,3,4,5,6};
	for(auto i : vi)
		cout<<i<<endl;
	show_vector(vi.begin(), vi.end());
	return 0;
}
