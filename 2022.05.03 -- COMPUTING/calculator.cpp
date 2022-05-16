#include "calculator.hpp"
#include <iostream>

#include <boost/compute/event.hpp>
#include <boost/compute/system.hpp>
#include <boost/compute/function.hpp>

#include <boost/compute/algorithm/copy.hpp>
#include <boost/compute/algorithm/transform.hpp>

#include <boost/compute/container/vector.hpp>

#include <boost/compute/functional/math.hpp>
#include <boost/compute/functional/operator.hpp>
#include <boost/compute/async/future.hpp>

BOOST_COMPUTE_FUNCTION(int, complex_calc, (float real, float imag),
	{
		float x_origin = 0.2f;
		float y_origin = 0.3f;
		int iterations = 0;

		float x = real;
		float y = imag;

		while(x*x + y*y < 4.0f && iterations < 1000)
		{
			float tmp = x*x - y*y + x_origin;
			y = 2*x*y + y_origin;
			x = tmp;
			++iterations;
		}

		return iterations;
	}
);

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
	compute::device device = compute::system::default_device();
	compute::context context(device);
	compute::command_queue queue(context, device);

	const auto dx = width / m_width;
	const auto dy = height / m_height;

	std::vector < float > r_prep(m_width * m_height, 0); //real
	std::vector < float > i_prep(m_width * m_height, 0); //imag

	compute::vector < float > r_cpt(m_width * m_height, context);
	compute::vector < float > i_cpt(m_width * m_height, context);

	compute::vector < int > iterations(m_width * m_height, context);

	for (auto y = 0; y < m_height; ++y)
	{
		for (auto x = 0U; x < m_width; ++x)
		{
			auto index = x + m_width * y;

			r_prep[index] = center.x - width / 2.0f + dx * x;
			i_prep[index] = center.y - height / 2.0f + dy * y;
		}
	}

	compute::future<void> f = compute::copy_async(r_prep.begin(), r_prep.end(), r_cpt.begin(), queue);
	compute::copy(i_prep.begin(), i_prep.end(), i_cpt.begin(), queue);
	f.wait();

	compute::transform(r_cpt.begin(), r_cpt.end(), i_cpt.begin(),
		iterations.begin(), complex_calc, queue);

	for (auto y = 0; y < m_height; ++y)
	{
		auto first = iterations.begin() + m_width * y;
		auto last = first + m_width;
		
		compute::copy(first, last, std::begin(m_field[y]), queue);
	}		
};