/*
 * calculateWithStd.cpp
 *
 *  Created on: 25-Oct-2016
 *      Author: maran
 */

#include <chrono>
#include <iostream>
#include <random>
#include <vector>

constexpr long long size = 100000000;

int main() {
	std::vector<int> randValues;
	randValues.reserve(size);

	std::random_device seed;
	std::mt19937 engine(seed());

	std::uniform_int_distribution<> uniformDist(1, 10);

	for(long long i = 0; i < size; i++) {
		randValues.push_back(uniformDist(engine));
	}

	auto start = std::chrono::system_clock::now();
	unsigned long long add {};

	add = std::accumulate(std::begin(randValues), std::end(randValues), 0);

	std::chrono::duration<double> dur = std::chrono::system_clock::now() - start;
	std::cout << "time for addition: " << dur.count() << std::endl;
	std::cout << "result of addition: " << add << std::endl;

}






