/*
 * auto.cpp
 *
 *  Created on: 22-Oct-2016
 *      Author: maran
 */

int myAdd(int a, int b) { return a + b; }

template <typename T>
class GetType;

int main() {
	int (*add)(int, int) = myAdd;
	auto add2 = myAdd;

	const int a = 5;
	const int &b = a;
	auto a1 = a;
	auto b1 = b;

//	GetType<decltype(add2)> g;
//
//	GetType<decltype(a)> g1;
//	GetType<decltype(a1)> g2;
//	GetType<decltype(b)> g3;
//	GetType<decltype(b1)> g4;

}



