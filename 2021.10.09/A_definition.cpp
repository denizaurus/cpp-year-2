#include "A_header.hpp"

Storage::Storage() : m_arr(nullptr), m_length(0), m_v({}) {};

Storage::Storage(int * first, int len, std::vector < int > vec) :
	m_arr(nullptr), m_length(len), m_v(vec) 
{
	m_arr = new int[m_length];
	for (auto i = 0U; i < m_length; ++i)
	{
		m_arr[i] = first[i];
	}
}

Storage::Storage(int * first, int len) :
	m_arr(nullptr), m_length(len), m_v({}) 
{
	m_arr = new int[m_length];
	for (auto i = 0U; i < m_length; ++i)
	{
		m_arr[i] = first[i];
	}
}

Storage::Storage(std::vector < int > vec) :
	m_arr(nullptr), m_length(0), m_v(vec) {}

Storage::Storage(const Storage & s) :
	m_arr(nullptr), m_length(s.m_length), m_v(s.m_v) 
{
	m_arr = new int[m_length];
	for (auto i = 0U; i < m_length; ++i)
	{
		m_arr[i] = s.m_arr[i];
	}
}

Storage::Storage(Storage && s) noexcept:
	m_arr(s.m_arr), m_length(s.m_length), m_v(std::move(s.m_v))
{
	s.m_arr = nullptr;
	s.m_length = 0;
	s.m_v = {};
}

Storage::~Storage()
{
	if (m_arr)
	{
		delete[] m_arr;
	}
	if (std::size(m_v))
	{
		m_v.~vector();
	}
}

Storage & Storage::operator= (const Storage & other)
{
	if (this == &other) { return *this; };

	m_length = other.m_length;
	m_v = other.m_v;

	if (m_arr) { delete[] m_arr; };

	m_arr = new int[m_length];

	for (auto i = 0U; i < m_length; ++i)
	{
		m_arr[i] = other.m_arr[i];
	}

	return *this;
}

Storage & Storage::operator= (Storage && other) noexcept
{

	m_arr = other.m_arr;
	m_length = other.m_length;
	m_v = std::move(other.m_v);

	other.m_arr = nullptr;
	other.m_length = 0;
	other.m_v = {};

	return *this;

}

std::ostream & operator<< (std::ostream & stream, const Storage & s)
{
	stream << "Array: ";

	for (auto i = 0U; i < s.m_length; ++i)
	{
		stream << s.m_arr[i] << " ";
	}

	stream << "\nVector: ";

	for (int element : s.m_v)
	{
		stream << element << " ";
	}

	return stream;
}