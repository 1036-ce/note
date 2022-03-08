#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

class Quote {
public:
	Quote() =default;
	Quote(const std::string &book, double sales_price):
		bookNo(book), price(sales_price) {}
	std::string isbn() const { return bookNo; }

	virtual double net_price(std::size_t n) const
		{ return n * price; }
	virtual void debug() const
	{
		std::cout << "bookNo: " << bookNo << std::endl;
		std::cout << "price: " << price << std::endl;
	}
	virtual ~Quote() =default;

private:
	std::string bookNo;
protected:
	double price = 0.0;
};

class Disc_Quote : public Quote {
public:
	Disc_Quote() = default;
	Disc_Quote(const std::string& book, double price,
			std::size_t qty, double disc):
		Quote(book, price), quantity(qty), discount(disc) {  }
	double net_price(std::size_t) const = 0;
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_Quote : public Disc_Quote {
public:
	Bulk_Quote() = default;
	Bulk_Quote(const std::string& book, double price,
			std::size_t qty, double disc):
		Disc_Quote(book, price, qty, disc) {  }
	double net_price(std::size_t) const override;
};

double Bulk_Quote::net_price(std::size_t cnt) const 
{
	if (cnt >= quantity)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}
double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() 
		<< " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}

int main(void)
{
	Bulk_Quote bulk;
	cout << bulk.isbn();
	return 0;
}
