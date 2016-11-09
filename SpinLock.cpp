/*
 * SpinLock.cpp
 *
 *  Created on: 09-Nov-2016
 *      Author: maran
 */

#include <atomic>
#include <thread>
#include <mutex>

class SpinLock {
	std::atomic_flag flag;

public:
	SpinLock() : flag { ATOMIC_FLAG_INIT } {}

	void lock() {
		while(flag.test_and_set());
	}

	void unlock() {
		flag.clear();
	}
};

SpinLock spin;

void spinLockSection() {
	spin.lock();
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	spin.unlock();
}

std::mutex mutex;

void mutexSection() {
	mutex.lock();
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	mutex.unlock();
}

int main() {
	//std::thread t1 {spinLockSection};
	//std::thread t2 {spinLockSection};

	std::thread t1 {mutexSection};
	std::thread t2 {mutexSection};

	t1.join();
	t2.join();
}


