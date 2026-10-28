#include <iostream>
#include <vector>

#include "iter.hpp"

template <>
void add(std::string& x) {
	iter(&x[0], x.size(), add<char>);
}

int main() {
	int test[3];
	test[0] = 0;
	test[1] = 1;
	test[2] = 2;
	const char cs[18] = "this is a c array";
	std::vector<int> vec;
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);

	const std::string str = "i am a c++ const string";
	std::string arr[5];
	arr[0] = "we";
	arr[1] = "are";
	arr[2] = "some";
	arr[3] = "different";
	arr[4] = "strings";

	iter(arr, 5, add<std::string>);
	iter(arr, 5, print<std::string>);

	iter(test, 3, add<int>);
	iter(test, 3, print<int>);

	// iter(cs, 17, add<char>);
	iter(cs, 17, print<char>);

	iter(&vec[0], 3, add<int>);
	iter(&vec[0], 3, print<int>);

	iter(str.c_str(), str.size(), print<char>);
	// iter(&str[0],str.size(), add<char>);
}
