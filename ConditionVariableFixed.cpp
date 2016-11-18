/*
 * ConditionVariableFixed.cpp
 *
 *  Created on: 13-Nov-2016
 *      Author: maran
 */
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

std::condition_variable condVar;
std::mutex mut;

bool dataReady;

void doWork() {
	std::cout << "protected resource" << std::endl;
}

void waitingForWork() {
	std::cout << "waiting to do work" << std::endl;
	std::unique_lock<std::mutex> lck(mut);
	condVar.wait(lck, []() {return dataReady;});
	doWork();
	std::cout << "work done" << std::endl;
}

void setDataReady() {
	std::lock_guard<std::mutex> lck(mut);
	dataReady = true;
	std::cout << "signal the other thread to do the work" << std::endl;
	condVar.notify_one();
	std::cout << "signalled" << std::endl;
}

int main() {
	std::thread t1(waitingForWork);
	std::thread t2([]() {
		std::cout << "signal the other thread to do the work" << std::endl;
		condVar.notify_one();
		std::cout << "signalled" << std::endl;
	});

	t1.join();
	t2.join();
}
