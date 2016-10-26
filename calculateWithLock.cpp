/*
 * calculateWithLock.cpp
 *
 *  Created on: 25-Oct-2016
 *      Author: maran
 */

#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include <mutex>

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

	std::mutex lockMutex;

	auto start = std::chrono::system_clock::now();
	unsigned long long add {};

	for (auto i : randValues) {
		std::lock_guard<std::mutex> guard(lockMutex);
		add += i;
	}

	std::chrono::duration<double> dur = std::chrono::system_clock::now() - start;
	std::cout << "time for addition: " << dur.count() << std::endl;
	std::cout << "result of addition: " << add << std::endl;

}


