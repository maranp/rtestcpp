/*
 * calculateWithAtomic.cpp
 *
 *  Created on: 25-Oct-2016
 *      Author: maran
 */

#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include <atomic>

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

	std::atomic<unsigned long long> add {};
	std::cout << std::boolalpha << "atomic is lock free: " << add.is_lock_free() << std::endl;

	auto start = std::chrono::system_clock::now();
	for (auto i : randValues) {
		add += i;
	}

	std::chrono::duration<double> dur = std::chrono::system_clock::now() - start;
	std::cout << "time for addition: " << dur.count() << std::endl;
	std::cout << "result of addition: " << add << std::endl;

	start = std::chrono::system_clock::now();
	for (auto i : randValues) {
		add.fetch_add(i, std::memory_order_relaxed);
	}
	dur = std::chrono::system_clock::now() - start;
	std::cout << "time for addition: " << dur.count() << std::endl;
	std::cout << "result of addition: " << add << std::endl;

}


