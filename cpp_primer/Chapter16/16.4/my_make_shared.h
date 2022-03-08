#ifndef MY_MAKE_SHARED_H
#define MY_MAKE_SHARED_H

#include <memory>
#include <utility>

template <typename T, typename... Args>
std::shared_ptr<T> my_make_shared(Args&&... args)
{
	T* t = new T(std::forward<Args>(args)...);
	return std::shared_ptr<T>(t);
}

#endif 
