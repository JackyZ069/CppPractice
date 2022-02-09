#include<iostream>

class Base
{
public:
	Base() {}
	~Base() {}
};

class Derived : public Base
{
public:
	Derived() {};
	~Derived() {};
};

class AnotherClass: public Base
{
public:
	AnotherClass() {}
	~AnotherClass() {}
};


int main()
{
	Derived* derived = new Derived();

	Base* base = derived;

	AnotherClass* ac = static_cast<AnotherClass*>(base);

	if (ac)
		std::cout << 1 << std::endl;

	std::cin.get();

}