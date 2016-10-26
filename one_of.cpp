/*
 * one_of.cpp
 *
 *  Created on: 26-Oct-2016
 *      Author: maran
 */

#include <initializer_list>
#include <iostream>

template <typename U, typename... T>
bool one_of(U &&u, T && ...t) {
	bool match = false;
	std::initializer_list<bool> { (match = match || u == t)... };
	return match;
}

template <typename U, typename... T>
bool one_of1(U && u, T && ... t) {
	bool match = false;
	std::initializer_list<bool> {(match = match || u == t)...};
	return match;
}

//{ (match = match || u == t) ... }

// not working
template <typename U, typename ... T>
bool one_of_2(U && u, T && ... t) {
	bool match = false;
	std::initializer_list<bool> {(match = match || u == t) ...};
	return match;
}

int main() {
	int x= 5;
	std::cout << "maran" << std::boolalpha << std::endl;
	std::cout << one_of(x, 1, 2, 4, 5) << std::endl;
	std::cout << one_of1(x, 1, 2, 3, 4) << std::endl;
	std::cout << one_of_2(x, 1, 2, 4, 5, 6) << std::endl;
	std::cout << "maran" << std::endl;

}
