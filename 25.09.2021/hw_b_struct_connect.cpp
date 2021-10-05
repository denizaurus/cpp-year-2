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

void enroll(std::vector < std::string > & input, // wanted to do with std::visit but couldn't figure out how
	std::vector < Lesson > & linked, Student & self)
{
	for (Lesson & lesson : linked)
	{
		auto temp = std::find(std::begin(input), std::end(input), lesson.course);

		if (temp != std::end(input))
		{
			self.v.push_back(&lesson);
			lesson.v.push_back(&self);
			std::cout << "Enrolling student " << lesson.v.back()->name << " at course " << lesson.course << std::endl;
		}
	}
}

int main()
{
	auto t = std::chrono::system_clock::now().time_since_epoch().count();
	const std::vector < std::string > e = { "Jane Doe", "Mary Sue", "Gary Stu", "John Smith" };
	std::vector < std::string > s = { "English", "Geography", "Quantum Chemistry", "Art" };
	std::vector < std::string > desired(4, "");

	std::vector < Student > students = {};
	std::vector < Lesson > lessons = {};



	for (auto i = 0U; i < 4; ++i)
	{
		students.push_back(Student(e[i]));
		lessons.push_back(Lesson(s[i]));
	}

	for (auto & f : students)
	{
		std::shuffle(std::begin(s), std::end(s), std::default_random_engine(t));
		desired = { s[0], s[1] };

		enroll(desired, lessons, f);
	}

	// SYSTEM OUTPUT

	for (auto & l : lessons)
	{
		std::cout << "-----------------------" << l.course << "-----------------------" << std::endl;
		for (auto & f : l.v)
		{
			std::cout << l.course << std::endl;
			std::cout << ' ' << f->name << ' ' << std::endl; // attempts to monitor memory location
		}
	}

	system("pause");
	return 0;
}