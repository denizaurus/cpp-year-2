#include <chrono>
#include <iostream>

class Timer
{
public:
	using clock_t = std::chrono::steady_clock;
	using time_point_t = clock_t::time_point;
	using duration_t = clock_t::duration;

	Timer() : m_start(m_start.time_since_epoch()),
		m_stored(m_stored.zero()), timer_active(false) {}

	void start() 

	{ 
		m_start = clock_t::now(); 
		timer_active = true; 
	}

	void pause() 
	{ 
		m_stored += clock_t::now() - m_start; 
		timer_active = false;
	}

	void end()
	{
		if (timer_active)
		{
			pause();
		}

		std::cout << std::chrono::duration_cast <
			std::chrono::microseconds > (m_stored).count() << " microseconds." << std::endl;

		m_stored = m_stored.zero();
	}

private:
	time_point_t m_start;
	duration_t m_stored;
	bool timer_active;
};

// TESTING
int main()
{

	Timer t;
	Timer g;

	t.start();
	g.start();

	auto a = 0U;
	for (auto i = 0U; i < 1000000; ++i)
	{
		a += i;
	}
	std::cout << "a: " << a << std::endl;

	t.pause();
	std::cout << "THE RESULT OF G:" << std::endl;
	g.end();

	t.start();

	auto b = 0U;
	for (auto i = 0U; i < 1000000; ++i)
	{
		b += i;
	}
	std::cout << "b: " << b << std::endl;

	std::cout << "THE RESULT OF T:" << std::endl;
	t.end();
}

