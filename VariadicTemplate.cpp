/*
 * VariadicTemplate.cpp
 *
 *  Created on: 10-Nov-2016
 *      Author: maran
 */
// http://arne-mertz.de/2016/11/modern-c-features-variadic-templates/
#include <tuple>

template <typename... Args>
int f(int i, Args... args) {
	std::tuple<Args...> tuple {args...};
	return i;
}

int main() {
	f(10, 20, "30", 'c');
}

template <typename... Args>
void testf(int i, Args&&... args) {
	std::tuple<Args...> argTuple {args...};
	std::tuple<Args...> arTup {std::forward<Args>(args)...};
}
