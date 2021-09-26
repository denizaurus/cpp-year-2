#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

struct Student;

struct Lesson
{
	Lesson() : students({}), course("UNDEFINED") {}
	Lesson(std::string n) : students({}), course(n) {}

	std::vector < Student > students;
	std::string course;
};

struct Student
{
	Student() : lessons({}), name("TEST") {}
	Student(std::string n) : lessons({}), name(n) {}

	std::vector < Lesson > lessons;
	std::string name;

	void enroll(std::vector < std::string > & d, // asymptotics: O(N*M)
		std::vector < Lesson > & l, const Student & self) 
	{
		for (Lesson & lesson : l)
		{
			auto temp = std::find(std::begin(d), std::end(d), lesson.course);
			if ( temp != std::end(d) )
			{

				lessons.push_back(lesson);
				lesson.students.push_back(self);
				std::cout << "Enrolling student " << name << " at " << lesson.course << std::endl;
			}
		}
	}
};

int main()
{
	// INFO TO PUT IN

	std::vector < std::string > s = { "English", "Geography", "Quantum Chemistry", "Art" };
	std::vector < std::string > s1 = { "English", "Geography"};
	std::vector < std::string > enrolled = { "Jane Doe", "Mary Sue", "Gary Stu", "John Smith" };
	std::vector < std::string> desired(4, "");

	// VECTOR INITIALISATION

	std::vector < Student > students;
	std::vector < Lesson > lessons;

	for (auto i = 0U; i < 4; ++i)
	{
		students.push_back(Student(enrolled[i]));
		lessons.push_back(Lesson(s[i]));
	}

	for (Student f : students)
	{
		std::shuffle(std::begin(s), std::end(s), 
			std::default_random_engine(19)); // shuffle to get different results, needs seed changing pre-compilation
		desired = { s[0], s[1], s[2] };

		f.enroll(desired, lessons, f);
	}

	// SYSTEM OUTPUT

	for (Lesson l : lessons)
	{
		std::cout << "-----------------------" << l.course << "-----------------------" << std::endl;
		for (Student f : l.students)
		{
			std::cout << l.course << ' ' << f.name << ' ' << &(f.name) << std::endl; // attempts to monitor memory location
			for (Lesson g : f.lessons)
			{
				std::cout << '\t' << g.course << ' ' << &g << std::endl;
			}
		}
	}


	system("pause");
	return 0;
}