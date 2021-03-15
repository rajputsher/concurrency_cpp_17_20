#pragma once

#include <vector>
#include <thread>

class thread_guard {

	std::thread& t; // Thread object 

public:
	explicit thread_guard(std::thread& _t) : t(_t) // Constructor is explicit so that it should not be considered implicit.
	{}

	~thread_guard() // In the delete construct, thread will join if it has not already joined due to the exception thrown before the thread was joined.
	{
		if (t.joinable())
		{
			t.join();
		}
	}

	// Delete copy construct and copy assignment operator
	//thread_guard(thread_guard& const) = delete;
	//thread_guard& operator= (thread_guard& const) = delete;
	thread_guard(const thread_guard& ) = delete;
	thread_guard& operator= (const thread_guard&) = delete;
};

class join_threads {
	std::vector<std::thread>& threads;

public:
	explicit join_threads(std::vector<std::thread>& _threads) :
		threads(_threads)
	{}

	~join_threads()
	{
		for (long i = 0; i < threads.size(); i++)
		{
			if (threads[i].joinable())
				threads[i].join();
		}
	}

};

class function_wrapper {
	struct impl_base {
		virtual void call() = 0;
		virtual ~impl_base() {}
	};

	template<typename F>
	struct impl_type : impl_base
	{
		F f;
		impl_type(F&& f_) : f(std::move(f_)) {}
		void call() { f(); }
	};

	std::unique_ptr<impl_base> impl;

public:
	template<typename F>
	function_wrapper(F&& f) :
		impl(new impl_type<F>(std::move(f)))
	{}

	void operator()() { impl->call(); }

	function_wrapper()
	{}

	function_wrapper(function_wrapper&& other) :
		impl(std::move(other.impl))
	{}

	function_wrapper& operator=(function_wrapper&& other)
	{
		impl = std::move(other.impl);
		return *this;
	}

	function_wrapper(const function_wrapper&) = delete;
	function_wrapper(function_wrapper&) = delete;
};