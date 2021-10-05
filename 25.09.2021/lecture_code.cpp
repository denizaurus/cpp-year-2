#include <iostream>
#include <string>
#include <vector>
//
//struct Person
//{
//	std::string name = "ABC";
//	double salary = 0.0;
//};
//
//
//int main() // STRUCTURES
//{
//	Person p = { "Jens", 123.0 }; // aggregate init, 3)
//	p.name = "Jens"; // 1)
//
//	Person * ptr = &p;
//	(*ptr).salary = 100.0;
//	// OR
//	ptr->salary = 42.0; // -> = * + .   2)
//
//	system("pause");
//	return 0;
//}



struct Person
{
	Person() : name("Jens"), salary(42.0) // default constructor. do not mix with default fields
	{}

	Person(const std::string & n, double s) :// no return type
		name(n), salary(s) // список инициализации
	{
		/*name = n;    присваивание
		salary = s;*/

		std::cout << "CTOR\n";
	}

	~Person() 
	{
		std::cout << "DTOR\n";
	} // destructor

	std::string name;
	double salary;
};

int main()
{
	Person p("Jens", 42.0);
	Person p; //default constructor
	Person p(); // function definition!

	{
		Person l("Jens", 42.0); // создаем лок область видимости, вне нее деструктор удаляет
	}
	
}


struct RAII_Tracer
{
	RAII_Tracer(const std::string & n) : name(n)
	{
		std::cout << name << "launched.\n";

	}

	~RAII_Tracer()
	{
		std::cout << name << "finished.\n";
	}

	void error(const std::string & message)
	{
		std::cerr << name << " detected: " << message << '\n';
	}

	std::string name;
};


void g()
{
	RAII_Tracer t("g");
	RAII_Tracer t(__FUNCSIG__); // or __FUNCTION__ - вся инф о функции, и имя и типы

	t.error("what happened");
}

void f()
{
	RAII_Tracer t("f");
	g();
}



struct Field // битовое поле
{
	int a : 3; // сколько БИТ на данный инт
	int b : 11;
	int c : 17;
	int d : 1;

};


union U
{
	char c;
	short s;
	int i;
	long long l;
};


enum class Color // с обл видимости
{
	red, // константы перечисления
	green, 
	blue
};

enum Color_w // без обл видимости
{
	red
};


int main()
{
	Color c = Color::red;
	Color_w c1 = red; // не нужно ::

	int x = 5 + c1; // конвертируется в int, т.к. без обл

	switch (c)
	{
	case Color::red:
		std::cout << "R";
		break;
	case Color::green:
		std::cout << "G";
		break;
	case Color::blue:
		break;
	default:
		break;
	}

}