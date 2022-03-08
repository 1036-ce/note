#include <cstddef>
#include <functional>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <type_traits>


class Sales_data {
friend std::istream &read(std::istream&,Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);
friend std::ostream &operator<<(std::ostream&,const Sales_data&);
friend bool operator==(const Sales_data&, const Sales_data&);
friend bool operator!=(const Sales_data&, const Sales_data&);
friend std::istream &operator>>(std::istream&, Sales_data&);
friend Sales_data operator+(const Sales_data&, const Sales_data&);
friend Sales_data add(const Sales_data&, const Sales_data&);
friend class std::hash<Sales_data>;

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

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn() &&
		   lhs.units_sold == rhs.units_sold &&
		   lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
	return !(lhs == rhs);
}
namespace std {
template<>
struct hash<Sales_data>
{
	typedef size_t result_type;
	typedef Sales_data argument_type;
	size_t operator() (const Sales_data& s) const;
};

size_t
hash<Sales_data>::operator() (const Sales_data& s) const
{
	return hash<string>() (s.bookNo) ^
		   hash<unsigned>() (s.units_sold) ^
		   hash<double>() (s.revenue);
}

}


