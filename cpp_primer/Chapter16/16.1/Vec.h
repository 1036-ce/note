#include <memory>

template <typename T> class Vec;
template <typename T> bool operator==(const Vec<T>&, const Vec<T>&);
template <typename T> bool operator!=(const Vec<T>&, const Vec<T>&);
template <typename T> bool operator<(const Vec<T>&, const Vec<T>&);

template <typename T> class Vec {
public:
	friend bool operator== <T>(const Vec<T>&, const Vec<T>&);
	friend bool operator!= <T>(const Vec<T>&, const Vec<T>&);
	friend bool operator< <T>(const Vec<T>&, const Vec<T>&);
	Vec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
	Vec(std::initializer_list<T>);
	Vec(const Vec&);
	Vec& operator=(const Vec&);
	T& operator[](std::size_t);
	const T& operator[](std::size_t) const;

	Vec(Vec &&) noexcept;
	Vec &operator=(Vec&&) noexcept;
	Vec &operator=(std::initializer_list<T>);

	~Vec();
	void push_back(const T&);
	void push_back(T&&);

	std::size_t size() const { return first_free - elements; }
	std::size_t capacity() const { return cap - elements; }
	void reserve(std::size_t);
	void resize(std::size_t, const T&);

	T *begin() const { return elements; }
	T *end() const { return first_free; }
private:
	/* static std::allocator<T> alloc; */
	std::allocator<T> alloc;

	void chk_n_alloc() { if (size() == capacity()) reallocate(); }

	std::pair<T*, T*> alloc_n_copy(const T*, const T*);
	void free();
	void reallocate();
	T *elements;
	T *first_free;
	T *cap;
};

/* template <typename T> std::allocator<T> Vec<T>::alloc; */

template <typename T>
void Vec<T>::push_back(const T &t)
{
	chk_n_alloc();
    alloc.construct(first_free++, t);
}

template <typename T>
void Vec<T>::push_back(T &&t)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::move(t));
}

template <typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
	auto data = alloc.allocate(e- b);
	return { data, std::uninitialized_copy(b, e, data) };
}

template <typename T>
void Vec<T>::free()
{
	if (elements)
	{
		for (auto p = first_free; p != elements; )
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);	
	}
}

template <typename T>
Vec<T>::Vec(const Vec &t)
{
	auto newdata = alloc_n_copy(t.begin(), t.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template <typename T>
Vec<T>::Vec(std::initializer_list <T> il)
{
    auto p = alloc_n_copy(il.begin(), il.end());
    elements = p.first;
    first_free = p.second;
    cap = elements + il.size();
}

template <typename T>
Vec<T>::~Vec<T>()
{
    free();
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec<T> &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template <typename T>
void Vec<T>::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (std::size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

template <typename T>
void Vec<T>::reserve(std::size_t n) {
    if (n <= capacity())
        return;
    auto newdata = alloc.allocate(n);
    auto dest = newdata;
    auto elem = elements;
    for (std::size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    elements = newdata;
    first_free = dest;
    cap = elements + n;
}

template <typename T>
void Vec<T>::resize(std::size_t n, const T &t) {
    if (n <= size())
        while (first_free != elements + n)
            alloc.destroy(--first_free);
    else if (n <= capacity())
        while (first_free != elements + n)
            alloc.construct(first_free++, t);
    else
    {
        auto newdata = alloc.allocate(n);
        auto elem = elements;
        auto dest = newdata;

        for (std::size_t i = 0; i != size(); ++i)
            alloc.construct(dest++, std::move(*elem++));
        elements = newdata;
        first_free = dest;
        cap = elements + n;

        while (first_free != elements + n)
            alloc.construct(first_free++, t);
    }
}

template <typename T>
Vec<T>::Vec(Vec &&t) noexcept 
	:elements(t.elements), first_free(t.first_free), cap(t.cap)
{
	t.elements = t.first_free = t.cap = nullptr;
}

template <typename T>
Vec<T>& Vec<T>::operator=(Vec &&rhs) noexcept
{
	if (this != rhs)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
	}
	return *this;
}

template <typename T>
bool operator==(const Vec<T> t1, const Vec<T> t2)
{
	auto it1 = t1.elements, it2 = t2.elements;
	while (it1 != t1.first_free && it2 != t2.first_free)
	{
		if (*it1 != *it2)
			return false;
		++it1, ++it2;
	}

	if (it1 == t1.first_free && it2 == t2.first_free)
		return true;
	return false;
}

template <typename T>
bool operator!=(const Vec<T> t1, const Vec<T> t2)
{
	return !(t1 == t2);
}

template <typename T>
bool operator<(const Vec<T> t1, const Vec<T> t2)
{
	auto it1 = t1.elements, it2 = t2.elements;
	while (it1 != t1.first_free && it2 != t2.first_free)
	{
		if (*it1 >= *it2)
			return false;
		++it1, ++it2;
	}

	return it1 == t1.first_free;
}

template <typename T>
Vec<T>& Vec<T>::operator=(std::initializer_list<T> il)
{
	auto it = il.begin();
	while (it != il.end())
	{
		this->push_back(*it);
		++it;
	}
	return *this;
}

template <typename T>
T& Vec<T>::operator[](std::size_t n)
{
	return *(elements + n);
}

template <typename T>
const T& Vec<T>::operator[](std::size_t n) const
{
	return *(elements + n);
}
