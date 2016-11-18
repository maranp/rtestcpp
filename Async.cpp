/*
 * Async.cpp
 *
 *  Created on: 13-Nov-2016
 *      Author: maran
 */

#include <future>
#include <iostream>
#include <typeinfo>

std::string const futFunction(std::string const & s) {
	return "call from " + s;
}

struct FunctionObject {
	std::string const operator() (std::string const &s) const {
		return "call from " + s;
	}
};

int main() {
	auto futureLambda = std::async([](std::string const &s) {
		return "call from " + s;
	}, "lambda function");
	std::cout << futureLambda.get() << std::endl;

	auto futureFunction = std::async(futFunction, "function call");
	std::cout << futureFunction.get() << std::endl;

	auto futureFunctionObject = std::async(FunctionObject(), "function object");
	std::cout << futureFunctionObject.get() << std::endl;

	auto begin = std::chrono::system_clock::now();

	auto futureEager = std::async(std::launch::async, [] { return std::chrono::system_clock::now();});
	auto futureLazy = std::async(std::launch::deferred, [] { return std::chrono::system_clock::now();});

	std::this_thread::sleep_for(std::chrono::seconds(1));

	auto eagerTime = futureEager.get() - begin;
	auto lazyTime = futureLazy.get() - begin;

	auto eagerSecs = std::chrono::duration<double>(eagerTime).count();
	auto lazySecs = std::chrono::duration<double>(lazyTime).count();

	std::cout << "eagerSecs " << eagerSecs << std::endl;
	std::cout << "lazySecs " << lazySecs << std::endl;




}

template <typename T, typename ... Ts>
std::unique_ptr<T> make_unique(Ts&& ... args) {
	return std::unique_ptr<T>(new T(std::forward<Ts>(args)...));
}

struct Base {
	virtual ~Base() = default;
};

struct Derived : public Base {

};

std::unique_ptr<Derived> d = ::make_unique<Derived>();
std::unique_ptr<Base> b(std::move(d));

