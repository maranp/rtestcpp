/*
 * DispatchTable.cpp
 *
 *  Created on: 24-Oct-2016
 *      Author: maran
 */

#include <cmath>
#include <functional>
#include <iostream>
#include <map>

int main() {
	std::map<const char, std::function<double (double, double)>> dispTable;

	dispTable.insert(std::make_pair('+', [](double a, double b) {
		return a + b;
	}));
	dispTable.insert(std::make_pair('-', [](double a, double b) {
		return a - b;
	}));
	dispTable.insert(std::make_pair('*', [](double a, double b) {
		return a * b;
	}));
	dispTable.insert(std::make_pair('/', [](double a, double b) {
		return a / b;
	}));

	std::cout << "3.5 + 4.5 = " << dispTable['+'](3.5, 4.5) << std::endl;

	dispTable.insert(std::make_pair('^', [](double a, double b) {
		return std::pow(a, b);
	}));

	std::cout << "3.5 ^ 4.5 = " << dispTable['^'](3.5, 4.5) << std::endl;
}




