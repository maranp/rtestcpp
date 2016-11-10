/*
 * inline.cpp
 *
 *  Created on: 09-Nov-2016
 *      Author: maran
 */
#include <iostream>
#include <typeinfo>
#include <cstddef>

#define absMacro(i) ((i) > 0 ? (i) : -(i))

inline int absFunction(int i) {
	return i > 0 ? i : -i;
}

class Inliner {
public:
	void implictInline() {}
	void explicitInline();
	inline void notInline();
};

inline void Inliner::explicitInline() {}

void Inliner::notInline() {

}

class Empty {
	void f() {
		std::cout << "empty f" << std::endl;
	}
};

class NotEmpty {
	virtual void f() {
		std::cout << "non empty f" << std::endl;
	}
};

int main() {
	int i {0};
	std::cout << absMacro(++i) << std::endl;
	i = 0;
	std::cout << absFunction(++i) << std::endl;
	Inliner in;
	in.implictInline();
	in.explicitInline();
	in.notInline();

	auto c {0};
	int *b {0};
	std::cout << "type of c: " << typeid(c).name() << std::endl;

	auto res = b + c;
	std::cout << "type of res: " << typeid(res).name() << std::endl;

	std::cout << "sizeof empty: " << sizeof(Empty) << std::endl;
	std::cout << "sizeof empty: " << sizeof(NotEmpty) << std::endl;
}
