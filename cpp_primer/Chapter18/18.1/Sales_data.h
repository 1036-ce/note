#include <iostream>
#include <istream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <type_traits>


class Sales_data {
friend std::istream &read(std::istream&,Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);
friend std::ostream &operator<<(std::ostream&,const Sales_data&);
friend std::istream &operator>>(std::istream&, Sales_data&);
friend Sales_data operator+(const Sales_data&, const Sales_data&);
friend Sales_data add(const Sales_data&, const Sales_data&);

public:
	Sales_data() = default;
	Sales_data(const std::string &s): bookNo(s) {  }
	// explicit Sales_data(const std::string &s): bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p): 
		bookNo(s), units_sold(n), revenue(n * p) { }
	Sales_data(std::istream&);

	Sales_data &operator=(const std::string &s) { bookNo = s; return *this;}
	Sales_data &operator+=(const Sales_data&);

	std::string isbn() const { return bookNo; }
	Sales_data& combine (const Sales_data&);
private:
	inline double avg_price() const { return revenue / units_sold; }
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

class out_of_stock: public std::runtime_error {
public:
	explicit out_of_stock(const std::string &s): std::runtime_error(s) {  }
};

class isbn_mismatch: public std::logic_error {
public:
	explicit isbn_mismatch(const std::string &s): std::logic_error(s) {  }
	isbn_mismatch(const std::string &s, const std::string &lhs, const std::string &rhs):
		std::logic_error(s), left(lhs), right(rhs) {  }
	const std::string left, right;
};

std::istream &read(std::istream&, Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
Sales_data add(const Sales_data&, const Sales_data&);

Sales_data::Sales_data(std::istream &is) 
{
	read(is,*this);
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

std::istream &read(std::istream &is, Sales_data &item) 
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

Sales_data& Sales_data::combine(const Sales_data& rhs) 
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

std::ostream &operator<<(std::ostream &os,const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

std::istream &operator>>(std::istream &is, Sales_data &item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
		item.revenue = item.units_sold * price;
	else
		item = Sales_data();
	return is;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
	if (isbn() != rhs.isbn())
		throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}
