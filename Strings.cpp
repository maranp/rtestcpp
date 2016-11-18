/*
 * Strings.cpp
 *
 *  Created on: 13-Nov-2016
 *      Author: maran
 */

#include <string>
#include <iostream>

void * operator new(std::size_t n) {
	std::cout << "allocating bytes: " << n << std::endl;
	return malloc(n);
}

void operator delete(void *p) {
	free(p);
}

int main() {
	for(auto i = 0; i < 20; i++) {
		std::cout << std::string(i, '#') << std::endl;
	}
}



