/*
 * ParseResolved.cpp
 *
 *  Created on: 22-Oct-2016
 *      Author: maran
 */

#include <iostream>
#include <typeinfo>

struct MyInt {
	MyInt(int i) : _i {i} {};
	MyInt() : _i {0} {};
	int _i;
};

int main() {
	MyInt myint(2011);
	std::cout << myint._i << std::endl;

	MyInt myint2(int, MyInt);
	std::cout << typeid(myint2).name() << std::endl;

	char c1(999);
	//char c2 {999};
}



