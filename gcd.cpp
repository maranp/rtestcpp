/*
 * gcd.cpp
 *
 *  Created on: 22-Oct-2016
 *      Author: maran
 */

#include <iostream>
#include <type_traits>
#include <typeinfo>

template <typename T, typename std::enable_if<std::is_integral<T>::value, T>::type = 0>
T gcdT(T a, T b) {
	if (b == 0) {
		return a;
	}
	return gcdT(b, a % b);
}

template <typename T1, typename T2>
typename std::conditional<sizeof(T1) < sizeof(T2), T1, T2>::type gcd(T1 a, T2 b) {
//typename std::common_type<T1, T2>::type gcd(T1 a, T2 b) {
	static_assert(std::is_integral<T1>::value , "T must be an integral type");
	static_assert(std::is_integral<T2>::value , "T must be an integral type");
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main() {
	std::cout << gcd(10, 20L) << std::endl;
	std::cout << gcdT(10, 20) << std::endl;
	//std::cout << gcdT("a", "b") << std::endl;
}
