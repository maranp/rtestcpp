/*
 * nowr.cpp
 *
 *  Created on: 22-Oct-2016
 *      Author: maran
 */
#include <chrono>
#include <iostream>

template <typename T>
void durationSinceEpoch(T dur) {
	std::cout << "count since epoch " << dur.count() << std::endl;


}

int main() {
	std::cout << std::endl;

	std::chrono::system_clock::time_point timeNowSysClock = std::chrono::system_clock::now();
	std::chrono::system_clock::duration timeDurSysClock = timeNowSysClock.time_since_epoch();

	durationSinceEpoch(timeDurSysClock);

	std::cout << "std::chrono::system_clock" << std::endl;

}



