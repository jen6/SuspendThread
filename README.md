#SuspendThread
SuspendThread v0.1.0

Just For Fun

`std::thread` launch itself when constructed.

It may hard to use std::thead then underlying thread(like Windows Thread or Pthread).

but using SuspendThread thread help control your threads

##How to Use
```cpp
#include <iostream>
#include "SuspendThread.hpp"


int main()
{
  SuspendThread t([](){ std::cout << "Oh I'm suspended!" << std::endl;});
  //make thread suspended state
  t.run(); 
  //now it run
  
  SuspendThread t1([](int a){std::cout << a << std::endl;}, 3);
  //use argvs
  t1.run()
}
```
