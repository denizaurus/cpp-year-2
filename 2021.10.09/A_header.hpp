#pragma once
#include <vector>
#include <string>
#include <iostream>

class Storage
{

public:

// CONSTRUCTORS


	Storage();
	Storage(int *, int, std::vector < int >);
	Storage(int *, int);
	Storage(std::vector < int >);
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