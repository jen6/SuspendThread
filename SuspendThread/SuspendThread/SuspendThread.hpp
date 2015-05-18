#pragma once
#include <thread>
#include <future>

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

	~SuspendThread()
	{
		task.join();
	}
	void run() noexcept
	{
		Psuspend.set_value();
	}
};
