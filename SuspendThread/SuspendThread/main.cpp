#include "SuspendThread.hpp"
#include <iostream>
using namespace std;
int main()
{
	SuspendThread t1([]() {cout << "googler " << endl; });
	t1.run();
	SuspendThread t([](int a, int b) {cout << a << b << endl; }, 3 ,1);
	t.run();
}