#pragma once
#include <thread>
#include <future>
#include <functional>

class SuspendThread {

private:
	
	std::thread task;
	std::promise<void> Psuspend;
public:

	template<typename FN_, typename ... Arguments>
	SuspendThread(FN_ func, Arguments&& ... args)
	{
		using function_bind = typename std::function<void()>;
		function_bind bFunc = std::bind(func, std::forward<Arguments>(args)...);

		auto l = [this](function_bind fc) 
		{
			auto fut = this->Psuspend.get_future();
			fut.wait();
			fc();
		};

		std::thread it(l, std::move(bFunc));
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
