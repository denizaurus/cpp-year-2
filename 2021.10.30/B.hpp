#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <exception>

template < typename T >
class Vector
{
public:

	using pointer = T *;
	using const_pointer = const T *;
	using ref = T &;
	using const_ref = const T &;

	using iterator = pointer;
	using const_iterator = const_pointer;

public:

	Vector() = default;

	explicit Vector(size_t size);
	explicit Vector(size_t size, const T & initial); // = {10,10} -> (10,10)

	Vector & operator=(const Vector &);
	Vector & operator=(Vector &&);

	Vector(const Vector & other);
	Vector(Vector && other);

	~Vector() noexcept
	{
		delete[] m_data;
	}

public:

	ref operator[] (size_t index)
	{
		if (index > m_size)
			throw std::out_of_range("Out-of-range error.");

		return m_data[index];
	}
	const_ref operator[](size_t index) const
	{
		if (index > m_size)
			throw std::out_of_range("Out-of-range error.");

		return m_data[index];
	}

	ref front()
	{
		if (m_size == 0)
			throw std::length_error("The array is empty.");

		return m_data[0];
	}
	ref back()
	{
		if (m_size == 0)
			throw std::length_error("The array is empty.");

		return m_data[m_size - 1];
	}

	const_ref front() const
	{
		return m_data[0];
	}
	const_ref back() const
	{
		return m_data[m_size - 1];
	}

	iterator begin() noexcept
	{
		return m_data;
	}
	iterator end() noexcept
	{
		return m_data + m_size; // на элемент следующий за последним
	}

	const_iterator begin() const noexcept
	{
		return m_data;
	}
	const_iterator end() const noexcept
	{
		return m_data + m_size;
	}

	size_t size() const noexcept
	{
		return m_size;
	}
	size_t capacity() const noexcept
	{
		return m_capacity;
	}

	void push_back(const T & value);
	void resize(size_t);
	void swap(Vector < T > & other);
	void pop_back()
	{
		m_size--;
	}

private:

	pointer m_data{ nullptr };
	size_t m_size{ 0 };
	size_t m_capacity{ 0 };
};


// BASE CONSTRUCTORS

template < typename T >
Vector < T > ::Vector(size_t size) :
	m_size(size), m_capacity(size)
{
	m_data = new T[m_size];
}

template < typename T >
Vector < T > ::Vector(size_t size, const T & initial) :
	m_size(size), m_capacity(size)
{
	m_data = new T[m_size];
	for (size_t i = 0; i < m_size; ++i)
		m_data[i] = initial;
}

// COPY AND MOVE CONSTRUCTORS

template < typename T >
Vector < T >::Vector(const Vector < T > & other) :
	m_size(other.m_size), m_capacity(other.m_capacity)
{
	m_data = new T[m_size];
	std::copy(other.begin(), other.end(), m_data);
}

template < typename T >
Vector< T >::Vector(Vector < T > && other) :
	m_size(other.m_size), m_capacity(other.m_capacity), m_data(other.m_data)
{
	other.m_data = nullptr;
	other.m_size = 0;
	other.m_capacity = 0;
}

// COPY AND MOVE ASSIGNMENT OPERATORS

template < typename T >
Vector < T > & Vector < T > ::operator= (const Vector < T > & other)
{
	if (this == &other) return *this;
	delete[] m_data;

	m_size = other.m_size;
	m_capacity = other.m_other;
	m_data = new T[m_size];

	std::copy(other.begin(), other.end(), m_data);
	return *this;
}

template < typename T >
Vector < T > & Vector < T > ::operator= (Vector < T > && other)
{
	m_data = other.m_data;
	m_size = other.m_size;
	m_capacity = other.m_capacity;

	other.m_data = nullptr;
	other.m_size = 0;
	other.m_capacity = 0;

	return *this;
}

// MEMBER FUNCTIONS

template < typename T >
void Vector < T >::push_back(const T & value)
{
	if (m_size >= m_capacity)
	{
		auto new_capacity = m_capacity == 0 ? 1 : 2 * m_capacity;
		auto new_data = new T[new_capacity];
		std::copy(this->begin(), this->end(), new_data);
		delete[] m_data;
		m_data = new_data;
		m_capacity = new_capacity;
	}
	m_data[m_size++] = value;
}

template < typename T >
void Vector < T > ::resize(size_t n_size)
{
	if (n_size < 0 || n_size > UINT_MAX)
		throw std::bad_array_new_length("Invalid array size.");

	auto new_capacity = n_size;
	auto new_size = (new_capacity >= m_size)
		? m_size : new_capacity;

	auto new_data = new T[new_capacity];
	std::copy(
		this->begin(), this->begin() + new_size, new_data
	);
	m_data = new_data;
	m_capacity = new_capacity;
	m_size = new_size;
}


template < typename T >
void Vector < T > ::swap(Vector < T > & other)
{
	std::swap(m_capacity, other.m_capacity);
	std::swap(m_size, other.m_size);
	std::swap(m_data, other.m_data);
}

