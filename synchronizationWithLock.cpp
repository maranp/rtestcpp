/*
 * synchronizationWithLock.cpp
 *
 *  Created on: 25-Oct-2016
 *      Author: maran
 */

#include <chrono>
#include <mutex>
#include <iostream>
#include <thread>
#include <vector>
#include <random>

constexpr long long firCount = 0;
constexpr long long secCount = 25000000;
constexpr long long thiCount = 50000000;
constexpr long long forCount = 75000000;
constexpr long long size =    100000000;

std::mutex mymutex;

void sumUp(unsigned long long &sum, std::vector<int> &rV, long long beg, long long end) {
	for (auto i = beg; i < end; i++) {
		std::lock_guard<std::mutex> myguard(mymutex);
		sum += rV[i];
	}
}

int main() {
	//std::random_device seed;
	std::mt19937 engine; //(seed());
	std::uniform_int_distribution<> uniDist(1, 10);
	std::vector<int> randValues;
	randValues.reserve(size);

	for (auto i = 0; i < size; i++) {
		randValues.push_back(uniDist(engine));
	}

	unsigned long long sum {};
	auto start = std::chrono::system_clock::now();

	std::thread thread1(sumUp, std::ref(sum), std::ref(randValues), firCount, secCount);
	std::thread thread2(sumUp, std::ref(sum), std::ref(randValues), secCount, thiCount);
	std::thread thread3(sumUp, std::ref(sum), std::ref(randValues), thiCount, forCount);
	std::thread thread4(sumUp, std::ref(sum), std::ref(randValues), forCount, size);

	thread1.join();
	thread2.join();
	thread3.join();
	thread4.join();

	std::chrono::duration<double> dur = std::chrono::system_clock::now() - start;

	std::cout << "time taken: " << dur.count() << std::endl;
	std::cout << "Result: " << sum << std::endl;

}



