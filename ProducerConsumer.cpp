/*
 * ProducerConsumer.cpp
 *
 *  Created on: 12-Nov-2016
 *      Author: maran
 */

#include <atomic>
#include <iostream>
#include <thread>

std::string message;
std::atomic<bool> ready {false};

void consumer() {
	while (!ready.load());
	std::cout << "message: " << message << std::endl;
}

void producer() {
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	message = "done";
	ready = true;
}

int main() {
	std::thread t1(producer);
	std::thread t2(consumer);

	t1.join();
	t2.join();
}



