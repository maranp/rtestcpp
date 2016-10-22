/*
 * uniformInitialization.cpp
 *
 *  Created on: 22-Oct-2016
 *      Author: maran
 */

#include <map>
#include <vector>
#include <string>
#include <iostream>

class Array {
	Array() : myData{1, 2, 3, 4, 5,} {}
private:
	int myData[5];
};

class MyClass {
public:
	int x;
	double y;
};

class MyClass2 {
public:
	MyClass2(int first, double second) : x{first}, y{second} {};
private:
	int x;
	double y;
};
int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	std::vector<int> intArray2 {1, 2, 3, 4, 5};
	std::map<std::string, int> myMap {{"maran", 83}, {"raji", 88}};

	for(auto idx : intArray2) {
		std::cout << idx << std::endl;
	}

	float const * pData = new const float[2] {3.2, 4.2};
	MyClass myclass {10, 2016};
	MyClass2 myclass2 {11, 2017};

}



