#include "SuspendThread.hpp"
#include <iostream>
using namespace std;

int main()
{
	SuspendThread t([](int a, int b) {cout << a << " " << b << endl; }, 3, 4);
	t.run();
}