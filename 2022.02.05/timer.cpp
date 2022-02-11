#include <chrono>
#include <string>
#include <iostream>

template < typename T = std::chrono::microseconds >
class Timer
{
public:
	using clock_t = std::chrono::steady_clock;
	using time_point_t = clock_t::time_point;
	using duration_t = std::chrono::nanoseconds;


	explicit Timer(int mode, std::string & name) : m_start(clock_t::now()),
		m_stored(duration_t::zero()), m_name(name), timer_active(false) 
	{ start(mode); }

	explicit Timer(std::string & name) : m_start(clock_t::now()),
		m_stored(duration_t::zero()), m_name(name), timer_active(false) {}

	explicit Timer(int mode) : m_start(clock_t::now()),
		m_stored(duration_t::zero()), m_name("Unnamed"), timer_active(false) 
	{ start(mode); }

	explicit Timer() : m_start(clock_t::now()),
		m_stored(duration_t::zero()), m_name("Unnamed"), timer_active(false) {}

	~Timer() noexcept { end(true); }


	void start(int mode = 1) 

	{ 
		if (mode)
		{
			if (!timer_active) { m_start = clock_t::now(); }
			timer_active = true;
		}
	}

	void pause() 
	{ 
		if (timer_active) { m_stored += clock_t::now() - m_start; }
		timer_active = false;
	}

	void output()
	{
		std::cout << m_name + ": " << std::chrono::duration_cast <T> (m_stored).count() << " units." << std::endl;
		m_stored = m_stored.zero();
	}

	void end(bool destr = false)
	{
		if (timer_active) { pause(); output();}
		else if (!timer_active && destr) { pause(); }
		else { output(); }
	}

private:
	time_point_t m_start;
	duration_t m_stored;
	std::string m_name;
	bool timer_active;
};

// TESTING
int main()
{
	std::string one = "Microseconds";
	std::string two = "Nanoseconds";


	Timer < std::chrono::microseconds > t(one);
	Timer < std::chrono::nanoseconds > g(two);

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

