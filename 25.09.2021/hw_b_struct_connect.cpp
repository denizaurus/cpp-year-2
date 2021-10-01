#include <string>
#include <vector>
#include <variant>

#include <iostream>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <random>

struct Student;

struct Lesson
{
	Lesson() : v({}), course("UNDEFINED") {}
	Lesson(std::string n) : v({}), course(n) {}

	std::vector < Student * > v;
	std::string course;
};

struct Student
{
	Student() : v({}), name("TEST") {}
	Student(std::string n) : v({}), name(n) {}

	std::vector < Lesson * > v;
	std::string name;
};

typedef std::variant <Student *, Lesson *> school_struct;

void enroll(std::vector < std::string > & input, // wanted to do with std::visit but couldn't figure out how
	std::vector < school_struct > linked,
	const school_struct self)
{
	
	if (std::holds_alternative < Student *>(self))
	{
		Student * holding = std::get < 0 >(self);

		for (school_struct to_link : linked)
		{
			Lesson * held = std::get < 1 >(to_link);	

			auto temp = std::find(std::begin(input), std::end(input), held->course);

			if (temp != std::end(input))
			{
				holding->v.push_back(held);
				held->v.push_back(holding);
				std::cout << "Enrolling student " << holding->name << " at course " << held->course << std::endl;
			}
		}
	}
	else
	{
		Lesson * holding = std::get < 1 >(self);

		for (school_struct to_link : linked)
		{
			Student * held = std::get < 0 >(to_link);

			auto temp = std::find(std::begin(input), std::end(input), held->name);

			if (temp != std::end(input))
			{
				holding->v.push_back(held);
				held->v.push_back(holding);
				std::cout << "Enrolling student " << held->name << " at course " << holding->course << std::endl;
			}
		}
	}
	

}

int main()
{
	std::time_t t = std::chrono::system_clock::to_time_t(
		std::chrono::system_clock::now());

	const std::vector < std::string > s = { "English", "Geography", "Quantum Chemistry", "Art" };
	const std::vector < std::string > e = { "Jane Doe", "Mary Sue", "Gary Stu", "John Smith" };
	std::vector < std::string > desired(4, "");

	std::vector < school_struct > students(4);
	std::vector < school_struct > lessons(4);

	for (auto i = 0U; i < 4; ++i)
	{
		// i do not know what to put here so it compiles
	}

	for (school_struct f : students)
	{
		std::shuffle(std::begin(s), std::end(s), std::default_random_engine(t));
		desired = { s[0], s[1] };

		enroll(desired, lessons, f);
	}

	// SYSTEM OUTPUT

	for (school_struct l : lessons)
	{
		Lesson * k = std::get < 1 >(l);
		std::cout << "-----------------------" << k->course << "-----------------------" << std::endl;
		for (school_struct f : k->v)
		{
			Student * g = std::get < 0 >(f);
			std::cout << k->course << ' ' << g->name << ' ' << &(g->name) << std::endl; // attempts to monitor memory location
		}
	}

	system("pause");
	return 0;
}