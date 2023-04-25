#include <iostream>

class A {
public:
};

class B {
public:
};

int main()
{
	auto a = new A;
	auto b = new B;
	if (*a == *b) // here is an error
		std::cout << "ture";
	delete a, b;
}
