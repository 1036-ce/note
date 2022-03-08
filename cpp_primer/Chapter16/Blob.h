#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

template <typename T> class BlobPtr;
template <typename T> class Blob;
template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator!=(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator<(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob {
public:
	friend class BlobPtr<T>;
	friend bool operator== <T>(const Blob<T>&, const Blob<T>&);
	friend bool operator!= <T>(const Blob<T>&, const Blob<T>&);
	friend bool operator< <T>(const Blob<T>&, const Blob<T>&);

	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	Blob();
	Blob(std::initializer_list<T> il);

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const T &t) { data->push_back(t); }
	void push_back(T &&t) { data->push_back(std::move(t)); }
	
	void pop_back() { data->pop_back(); };

	T& front();
	T& front() const;
	T& back();
	T& back() const;
	T& operator[](size_type);

	BlobPtr<T> begin();
	BlobPtr<T> end();
private:
	std::shared_ptr<std::vector<T>> data;
	void check(size_type i, const std::string &msg) const;
};

template <typename T>
	bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T>
	bool operator!=(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T>
	bool operator<(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T>
	BlobPtr<T>& operator+(BlobPtr<T>&, int);
template <typename T>
	BlobPtr<T>& operator-(BlobPtr<T>&, int);

template <typename T> class BlobPtr {
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	friend bool operator==<T>
		(const BlobPtr<T>&, const BlobPtr<T>&);
	friend bool operator!=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
	friend bool operator< <T>(const BlobPtr<T>&, const BlobPtr<T>&);
	friend BlobPtr<T>& operator+<T>(BlobPtr<T>&, int);
	friend BlobPtr<T>& operator-<T>(BlobPtr<T>&, int);  

	BlobPtr(): curr(0) {  }
	BlobPtr(Blob<T> &a, size_type sz = 0): wptr(a.data), curr(sz) {  }

	BlobPtr& operator++();
	BlobPtr operator++(int);
	BlobPtr& operator--();
	BlobPtr operator--(int);
	BlobPtr& operator+=(int);
	BlobPtr& operator-=(int);

	T& operator*() const;
private:
	std::shared_ptr<std::vector<T>>
		check(size_type, const std::string&) const;
	std::weak_ptr<std::vector<T>> wptr;
	size_type curr;
};
  
template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template <typename T>
T& Blob<T>::front() {
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T>
T& Blob<T>::front() const {
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T>
T& Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
T& Blob<T>::back() const {
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i) {
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()) {  }

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il):
               data(std::make_shared<std::vector<T>>(il)) { }


template <typename T>
std::shared_ptr<std::vector<T>>
BlobPtr<T>::check(size_type i, const std::string& msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound BlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
} 

template <typename T>
bool operator== (const BlobPtr<T> &sbp1, const BlobPtr<T> &sbp2)
{
	if (sbp1.wptr.lock() == sbp2.wptr.lock() && sbp1.curr == sbp2.curr)
		return true;
	return false;
} 
 
template <typename T>
bool operator!=(const BlobPtr<T> &sbp1, const BlobPtr<T> &sbp2)
{
	return !(sbp1 == sbp2);
} 

template <typename T>
bool operator<(const BlobPtr<T> &sbp1, const BlobPtr<T> &sbp2)
{
	if (sbp1.wptr.lock() == sbp2.wptr.lock() && sbp1.curr < sbp2.curr)
		return false;
	return true;
}

template <typename T>
BlobPtr<T>& operator+(BlobPtr<T> &sbp, int n)
{
	sbp.curr += n;
	sbp.check(sbp.curr, "increment past end BlobPtr");
	return sbp;
}

template <typename T>
BlobPtr<T>& operator-(BlobPtr<T> &sbp, int n)
{
	sbp.curr -= n;
	sbp.check(sbp.curr, "increment past end BlobPtr");
	return sbp;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	check(curr, "increment past end of BlobPtr");
	++curr;
	return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	BlobPtr ret = *this;
	++*this;
	return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	check(curr, "increment past end of BlobPtr");
	--curr;
	return *this;
}


template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
	BlobPtr ret = *this;
	--*this;
	return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator+=(int n)
{
	return *this + n;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator-=(int n)
{
	return *this - n;
}

template <typename T>
T& BlobPtr<T>::operator*() const
{
	auto p = check(curr, "derefence past end");
	return (*p)[curr];
}
/* 
 * template <typename T>
 * T* BlobPtr<T>::operator->() const 
 * {
 *     return & this->operator*();
 * } */

template <typename T>
BlobPtr<T> Blob<T>::begin()
{
	return BlobPtr<T>(*this);
}

template <typename T>
BlobPtr<T> Blob<T>::end()
{
	return BlobPtr<T>(*this, data->size());
}

template <typename T>
bool operator==(const Blob<T> &sb1, const Blob<T> &sb2)
{
	auto it1 = sb1.data->begin(), it2 = sb2.data->begin();

	while(it1 != sb1.data->end() && it2 != sb2.data->end())
	{
		if (*it1 != *it2)
			return false;
		++it1, ++it2;
	}

	if (it1 == sb1.data->end() && it2 == sb2.data->end())
		return true;
	return false;
}

template <typename T>
bool operator!=(const Blob<T> &sb1, const Blob<T> &sb2)
{
	return !(sb1 == sb2);
}

template <typename T>
bool operator<(const Blob<T> &sb1, const Blob<T> &sb2)
{
	auto it1 = sb1.data->begin(), it2 = sb2.data->begin();
	while (it1 != sb1.data->end() && it2 != sb2.data->end())
	{
		if (*it1 >= *it2)
			return false;
		return true;
	}
	return it1 == sb1.data->end();
}
