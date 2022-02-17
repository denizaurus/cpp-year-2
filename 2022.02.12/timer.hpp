#pragma once
#include < chrono >
#include < iostream >

template < typename T = std::chrono::microseconds >
class Timer
{
public:
	using clock_t = std::chrono::steady_clock;
	using time_point_t = clock_t::time_point;
	using duration_t = std::chrono::nanoseconds;


	explicit Timer(int mode, const std::string & name) : m_start(clock_t::now()),
		m_stored(duration_t::zero()), m_name(name), timer_active(false)
	{
		start(mode);
	}

	explicit Timer(const std::string & name) : m_start(clock_t::now()),
		m_stored(duration_t::zero()), m_name(name), timer_active(false) {}

	explicit Timer(int mode) : m_start(clock_t::now()),
		m_stored(duration_t::zero()), m_name("Unnamed"), timer_active(false)
	{
		start(mode);
	}

	Timer() : m_start(clock_t::now()),
		m_stored(duration_t::zero()), m_name("Unnamed"), timer_active(false) {}

	~Timer() noexcept
	{
		try { end(true); }
		catch (...) { std::cout << "Exception thrown."; };
	}


	void start(int mode = 1, int res = 0)

	{
		if (res) { reset(); }

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
		reset();
	}

	void end(bool destr = false)
	{
		if (timer_active) { pause(); output(); }
		else if (!timer_active && destr) { pause(); }
		else { output(); }
	}

	void reset() { m_stored = duration_t::zero(); }

	int extract() 
	{ 
		pause();
		return static_cast < int > 
			(std::chrono::duration_cast <T> (m_stored).count());
	}

private:
	time_point_t m_start;
	duration_t m_stored;
	std::string m_name;
	bool timer_active;
};