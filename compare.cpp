/*
 * compare.cpp
 *
 *  Created on: 23-Oct-2016
 *      Author: maran
 */
#include <type_traits>
#include <iostream>

class Base {};
class Derived : public Base {};

namespace maran {
template <typename T, typename U>
struct is_same : std::false_type {};

template <typename T>
struct is_same<T, T> : std::true_type {};

template <typename T>
struct remove_const {
	typedef T type;
};

template <typename T>
struct remove_const<const T> {
	//typedef T type;
	using type = T;
};

}

int main() {
	std::cout << std::boolalpha;
	std::cout << std::is_base_of<Base, Derived>::value << std::endl;
	std::cout << std::is_base_of<Derived, Base>::value << std::endl;
	std::cout << std::is_convertible<Derived *, Base *>::value << std::endl;

	std::cout << std::is_same<int, std::remove_reference<int &>::type>::value << std::endl;
	std::cout << std::is_same<int, std::remove_reference<const int &>::type>::value << std::endl;
	std::cout << std::is_same<int, std::remove_const<std::remove_reference<const int &>::type>::type>::value << std::endl;

	std::cout << std::is_same<int, std::remove_const<const int>::type>::value << std::endl;
	std::cout << maran::is_same<int, maran::remove_const<const int>::type>::value << std::endl;

}


