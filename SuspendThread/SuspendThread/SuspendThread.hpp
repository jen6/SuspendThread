#pragma once
#include <thread>
#include <future>
#include <iostream>

class SuspendThread {
private:
	std::thread task;
	std::promise<void> Psuspend;
public:
	template<typename FN_>
	SuspendThread(FN_&& func)
	{
		auto fut_suspend = Psuspend.get_future();
		std::thread it(
			[fut = std::move(fut_suspend), func]()
		{
			fut.wait();
			func();
		});
		task.swap(it);
	}

	template<typename FN_, typename ... Arguments>
	SuspendThread(FN_ func, Arguments&& ... args)
	{
		auto fut_suspend = Psuspend.get_future();
		std::thread it(
			[fut = std::move(fut_suspend), func, args ...]()
		{
			fut.wait();
			func(std::forward<Arguments>(args)...);
		});
		task.swap(it);
	}

	~SuspendThread()
	{
		task.join();
	}
	void run() noexcept
	{
		Psuspend.set_value();
	}
};
