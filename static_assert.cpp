/*
 * static_assert.cpp
 *
 *  Created on: 22-Oct-2016
 *      Author: maran
 */

#include <string>

static_assert(sizeof(void *) == 8, "64 bit addressing needed");
//static_assert(sizeof(void *) == 4, "32 bit addressing needed");

template <typename T, int Line, int Column>
struct Matrix {
	static_assert(Line >= 0, "Line must be non-negative");
	static_assert(Column >= 0, "Column must be non-negative");
	static_assert(Line + Column > 0, "At least one Line or one column is expected");
};

int main() {
	Matrix<int, 2, 3> m1;
	Matrix<int, 1, 0> m2;
	Matrix<std::string, 1, 1> m3;
}



