/*
 * FuncitonalFactorial.cpp
 *
 *  Created on: 13-Nov-2016
 *      Author: maran
 */
#include <iostream>

template <int N>
struct fact {
	static int const value = N * fact<N - 1>::value;
};

template <>
struct fact<1> {
	static int const value = 1;
};

int main() {
	std::cout << fact<5>::value << std::endl;
}
