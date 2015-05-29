#include "SuspendThread.hpp"
#include <iostream>
using namespace std;\

void func(int a)
{
	cout << "aas"<< a << endl;
}

int main()
{
	//SuspendThread t([](int a, int b) {cout << a << " " << b << endl; }, 3, 4);
	SuspendThread t(func, 10);
	t.run();
	//auto f = []() {};
	//func(f);

	//std::function<void(void)> f = std::bind(func, 3);
	//f();
}