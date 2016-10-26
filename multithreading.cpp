/*
 * multithreading.cpp
 *
 *  Created on: 26-Oct-2016
 *      Author: maran
 */

#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>

std::mutex mymutex;

struct Worker {
	std::string n;

	Worker(std::string name) : n {name } {}

	void operator () () const {
		std::lock_guard<std::mutex> myguard(mymutex);
		for (int i = 0; i < 30; i++) {
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			std::cout << n << std::endl;
		}
	}
};

int main() {
	std::thread t1(Worker("cat"));
	std::thread t2(Worker("  dog"));
	std::thread t3(Worker("    fox"));

	t1.join();
	t2.join();
	t3.join();
}


//#include <atomic>
//#include <thread>
//#include <iostream>
//
//std::atomic_int x, y;
//int r1, r2;
//
//void writeX() {
//	x.store(1);
//	r1 = y.load();
//}
//
//void writeY() {
//	y.store(1);
//	r2 = x.load();
//}
//
//int main() {
//
//	x = 0;
//	y = 0;
//
//	std::thread t1(writeX);
//	std::thread t2(writeY);
//
//	t1.join();
//	t2.join();
//
//	std::cout << r1 << r2 << std::endl;
//
//}



