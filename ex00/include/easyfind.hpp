#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class not_found : public std::exception {
   public:
	not_found(const int value) : _value(value) {}
	const char* what() const throw() { return "Value not found in container"; }
	int value() const { return _value; }

   private:
	const int _value;
};

template <typename C>
typename C::iterator easyfind(C& container, int value) {
	typename C::iterator it =
	    std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw not_found(value);
	return it;
}

template <typename C>
typename C::const_iterator easyfind(const C& container, int value) {
	typename C::const_iterator it =
	    std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw not_found(value);
	return it;
}

#endif
