/*
 * functional.cpp
 *
 *  Created on: 23-Oct-2016
 *      Author: maran
 */

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

template <typename T>
class GetType;

int main() {
	std::vector<int> vi {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<std::string> vstr {"programming", "in", "a", "functional", "style"};

	for(auto s : vstr) {
		std::cout << s << " ";
	}
	std::cout << std::endl;

	for(auto i : vi) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	std::transform(std::begin(vi), std::end(vi), std::begin(vi), [] (int i) {
		return i * i;
	});

	for(auto i : vi) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	std::vector<size_t> lenvec;

	std::transform(vstr.begin(), vstr.end(), std::back_inserter(lenvec), [] (std::string const & s) {
		return s.length();
	});

	for(auto i : lenvec) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	auto it = std::remove_if(vstr.begin(), vstr.end(), [] (std::string const & s) {
		return s.length() > 5;
	});

	//while(it !=) {
		std::cout << *it << " ";
		it++;
	//}
		std::cout << *it << " ";
		it++;
//		std::cout << *it << " ";
//				it++;
	std::cout << std::endl;

	//	GetType<decltype(it)> g;
//	//std::cout << decltype(it) << std::endl;

	for(auto s : vstr) {
		std::cout << s << " ";
	}
	std::cout << std::endl;

}



