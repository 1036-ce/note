#include <iostream>
#include <string>


struct Sales_data {
	std::string isbn() const { return bookNo; }
	Sales_data& combine (const Sales_data&);


	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data& rhs) 
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
int main(void)
{
	Sales_data sd1;
	Sales_data sd2;
	sd2.combine(sd1);
	return 0;
}
