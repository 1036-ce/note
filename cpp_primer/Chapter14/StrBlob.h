#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <vector>

class StrBlobPtr;

class StrBlob {
public:
	friend class StrBlobPtr;
	friend bool operator==(const StrBlob&, const StrBlob&);
	friend bool operator!=(const StrBlob&, const StrBlob&);
	friend bool operator<(const StrBlob&, const StrBlob&);
	typedef std::vector<std::string>::size_type size_type;

	StrBlob(): data(std::make_shared<std::vector<std::string>>()) {};
	StrBlob(std::initializer_list<std::string> il): 
		data(std::make_shared<std::vector<std::string>>(il)) {};

	std::string& operator[](std::size_t);
	const std::string& operator[](std::size_t) const;

	StrBlobPtr begin();
	StrBlobPtr end();

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const std::string &t) { data->push_back(t); }
	void pop_back();

	std::string &front();
	std::string &front() const;
	std::string &back();
	std::string &back() const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr {
public:
	friend bool operator==(const StrBlobPtr&,const StrBlobPtr&);
	friend bool operator!=(const StrBlobPtr&,const StrBlobPtr&);
	friend bool operator<(const StrBlobPtr&,const StrBlobPtr&);
	friend StrBlobPtr& operator+(StrBlobPtr&, int);
	friend StrBlobPtr& operator-(StrBlobPtr&, int);
	StrBlobPtr(): curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}

	char& operator[](std::size_t);
	const char& operator[](std::size_t) const;
	StrBlobPtr& operator++();
	StrBlobPtr operator++(int);
	StrBlobPtr& operator--();
	StrBlobPtr operator--(int);
	StrBlobPtr& operator+=(int);
	StrBlobPtr& operator-=(int);
	std::string& operator*() const;
	std::string* operator->() const;

	std::string& deref() const;
	StrBlobPtr& incr();

	bool equal(StrBlobPtr sb)
	{
		if (sb.wptr.lock() == this->wptr.lock() && sb.curr == this->curr)
			return true;
		return false;
	}
private:
	std::shared_ptr<std::vector<std::string>> 
		check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
}; 

void StrBlob::check(size_type i, const std::string &msg) const 
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

std::string& StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data ->front();
}

std::string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

std::string& StrBlob::back() const 
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}
std::shared_ptr<std::vector<std::string>> 
StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

std::string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() 
{
	check(curr, "increment past end StrBlobPtr");
	++curr;
	return *this;
}

bool operator==(const StrBlob &sb1, const StrBlob &sb2)
{
	auto it1 = sb1.data->begin(), it2 = sb2.data->begin();
	while (it1 != sb1.data->end() && it2 != sb2.data->end())
	{
		if (*it1 != *it2)
			return false;
		++it1, ++it2;
	}
	if (it1 == sb1.data->end() && it2 == sb2.data->end())
		return true;
	return false;
}

bool operator!=(const StrBlob &sb1, const StrBlob &sb2)
{
	return !(sb1 == sb2);
}

bool operator==(const StrBlobPtr &sbp1, const StrBlobPtr &sbp2)
{
	if (sbp1.wptr.lock() == sbp2.wptr.lock() && sbp1.curr == sbp2.curr)
		return true;
	return false;
}

bool operator!=(const StrBlobPtr &sbp1, const StrBlobPtr &sbp2)
{
	return !(sbp1 == sbp2);
}

bool operator<(const StrBlob &sb1, const StrBlob &sb2)
{
	auto it1 = sb1.data->begin(), it2 = sb2.data->begin();
	while (it1 != sb1.data->end() && it2 != sb2.data->end())
	{
		if (*it1 >= *it2)
			return false;
		++it1, ++it2;
	}

	return it1 == sb1.data->end();
}

bool operator<(const StrBlobPtr &sbp1, const StrBlobPtr &sbp2)
{
	if (sbp1.wptr.lock() == sbp2.wptr.lock() && sbp1.curr < sbp2.curr)
		return true;
	return false;
}

std::string& StrBlob::operator[](std::size_t n)
{
	return (*data)[n];
} 

const std::string& StrBlob::operator[](std::size_t n) const
{
	return (*data)[n];
}

char& StrBlobPtr::operator[](std::size_t n)
{
	return deref()[n];
}

const char& StrBlobPtr::operator[](std::size_t n) const
{
	return deref()[n];
}

StrBlobPtr& StrBlobPtr::operator++()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
	StrBlobPtr ret = *this;
	++*this;
	return ret;
}

StrBlobPtr& StrBlobPtr::operator--()
{
	--curr;
	check(curr, "increment past end of StrBlobPtr");
	return *this;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
	StrBlobPtr ret = *this;
	--*this;
	return ret;
}

StrBlobPtr& operator+(StrBlobPtr& sbp, int n)
{
	sbp.curr += n;
	sbp.check(sbp.curr, "increment past end StrBlobPtr");
	return sbp;
}

StrBlobPtr& operator-(StrBlobPtr& sbp, int n)
{
	sbp.curr -= n;
	sbp.check(sbp.curr, "increment past end of StrBlobPtr");
	return sbp;
}

inline
StrBlobPtr& StrBlobPtr::operator+=(int n)
{
	return *this + n;
}

inline
StrBlobPtr& StrBlobPtr::operator-=(int n)
{
	return *this - n;
}

inline
std::string& StrBlobPtr::operator*() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

inline
std::string* StrBlobPtr::operator->() const
{
	return & this->operator*();
}
