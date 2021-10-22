#pragma once
#include <vector>
#include <string>
#include <iostream>

class Storage
{

public:

// CONSTRUCTORS


	explicit Storage();
	explicit Storage(int *, int, const std::vector < int > &);
	explicit Storage(int *, int);
	explicit Storage(const std::vector < int > &);
	Storage(const Storage &);
	Storage(Storage &&) noexcept;
	~Storage();

//OPERATORS

	Storage & operator= (const Storage &);
	Storage & operator= (Storage &&) noexcept;
	friend std::ostream & operator<< (std::ostream &, const Storage &);
	
private:

	int * m_arr;
	size_t m_length;
	std::vector < int > m_v;

};