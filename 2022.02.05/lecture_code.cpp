#include <chrono>
#include <iostream>

class Timer
{
public:
	using clock_t = std::chrono::steady_clock;
	using time_point_t = clock_t::time_point;

	Timer() : m_begin(clock_t::now()) {}

	~Timer() noexcept
	{
		std::cout << std::chrono::duration_cast <
			std::chrono::microseconds > (clock_t::now() - m_begin).count() << " microseconds." << std::endl;
	}
private:
	time_point_t m_begin;
};

/*
	std::chrono::duration < int > a(20); // default ration= 1:1 - this is 20 secs
	std::chrono::duration < double, std::ratio < 60 > > b(0.5); // 30 secs
	std::chrono::duration < long, std::ratio < 1, 1000 > > c(42); // 42 millisecs

	std::chrono::seconds a(20);
	std::chrono::hours b(24);
	std::chrono::milliseconds c(17);

	c += a - b;
	--c;
	c *= 2;

	std::cout << c.count() << std::endl; // returns in c's measurements, so, milliseconds
	std::cout << std::chrono::duration_cast <std::chrono::minutes> (c).count() << std::endl;
	*/

	// DEVELOPING A CHRONOMETER

int main(int argc, char ** argv)
{
	{
		Timer t;
		auto c = 1.0;
		for (auto i = 0; i < 10000000; ++i)
		{
			c += 1.23;
		}
		std::cout << c << std::endl;

	}

	
	system("pause");
	return EXIT_SUCCESS;
}