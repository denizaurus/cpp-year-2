#include "calculator.hpp"

void Calculator::initialize()
{
	m_field.resize(m_height);

	for (auto & row : m_field)
	{
		row.resize(m_width);
	}
}

void Calculator::calculate(sf::Vector2f center, float width, float height)
{
	auto threads_number = std::thread::hardware_concurrency();

	auto dx = width / m_width;
	auto dy = height / m_height;

	std::vector < std::thread > threads(threads_number);

	auto size = m_height / threads_number;
	auto tail = m_height - threads_number * size;

	auto function = [=] (std::size_t id)
	{
		auto first_y = size * id;
		auto last_y = first_y + size;

		last_y = last_y > m_height ? m_height : last_y;

		for (auto y = first_y; y < last_y; ++y)
		{
			for (auto x = 0U; x < m_width; ++x)
			{
				std::complex < float > z(
					center.x - width / 2.0f + dx * x,
					center.y - height / 2.0f + dy * y
				);
				std::complex < float > c(0.2f, 0.3f);

				auto iteration = 0U;

				for (; iteration < m_max_iterations && std::norm(z) < 4.0f; ++iteration)
				{
					z = z * z + c;
				}

				m_field[y][x] = iteration; // ?
			}
		}
	};

	for (auto i = 0U; i < threads_number; ++i)
	{
		threads[i] = std::thread(function, i);
	}

	if (tail > 0U)
	{
		function(threads_number);
	}

	for (auto i = 0U; i < threads_number; ++i)
	{
		threads[i].join();
	}
}