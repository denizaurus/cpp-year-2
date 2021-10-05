#pragma once

#include <string>

class Person
{
public:
	Person(const std::string & name) :
		m_name(name) {}

public:
	void f();

private:
	std::string m_name;
};
