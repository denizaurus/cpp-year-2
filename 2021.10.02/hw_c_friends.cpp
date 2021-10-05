#include <iostream>
#include <string>
#include <string>
#include <iostream>


class Key_A
{
	friend class Access_A;
	Key_A() {};	
};

class Key_B
{
	friend class Access_B;
	Key_B() {};
};

class Info
{
	std::string dataset_1 = "You accessed dataset_1.\n";
	std::string dataset_2 = "You accessed dataset_2.\n";

public: 

	void access_1(Key_A)
	{
		std::cout << dataset_1;
	}

	void access_1()
	{
		std::cout << "Lacking Key.\n";
	}

	void access_2(Key_B)
	{
		std::cout << dataset_2;
	}

	void access_2()
	{
		std::cout << "Lacking Key.\n";
	}
};

class Access_A
{
public:
	void access(Info & info)
	{
		std::cout << "Beginning Access_A. . .\n";
		info.access_1({});
		std::cout << "Ending Access_A. . .\n";
	}
};

class Access_B
{
public:
	void access(Info & info)
	{
		std::cout << "Beginning Access_B. . .\n";
		info.access_2({});
		std::cout << "Ending Access_B. . .\n";
	}
};

class Access_C
{
public:
	void access(Info & info)
	{
		std::cout << "Beginning Access_C. . .\n";
		// info.access_1({});// will not compile due to lacking key
		// info.access_2({}); // will not compile due to lacking key
		std::cout << "Ending Access_C. . .\n";
	}
};

int main()
{
	Access_A a;
	Access_B b;
	Access_C c;
	Info info;

	a.access(info);
	b.access(info);
	c.access(info);

	return 0;
}