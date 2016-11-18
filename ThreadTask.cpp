/*
 * ThreadTask.cpp
 *
 *  Created on: 13-Nov-2016
 *      Author: maran
 */

#include <thread>
#include <future>
#include <iostream>

int main() {
	int res;
	std::thread t([&] { res = 3 + 4;});
	t.join();
	std::cout << "result: " << res << std::endl;
	auto fut = std::async([] { return 3 + 4;});
	std::cout << "result: " << fut.get() << std::endl;

}



