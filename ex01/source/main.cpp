#include "iter.hpp"

int main() {
	int test[3] = {0, 1, 2};
	const char cs[18] = "this is a c array";

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

	iter(str.c_str(), str.size(), print<char>);
	// iter(&str[0],str.size(), add<char>);
}
