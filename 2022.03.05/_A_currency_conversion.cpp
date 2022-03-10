#include <iomanip>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>

#include <Windows.h> 

void convert(bool out)
{
	std::string eur;
	
    std::cin.imbue(std::locale("de_DE.UTF-8"));
    std::cout << "Input sum here: ";
    std::cin >> std::get_money(eur);

    auto rub = std::stold(eur) * 150;

    std::cout.imbue(std::locale("ru_RU.UTF-8"));
	std::cout << std::showbase << std::put_money(rub, out) << std::endl;
}

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	convert(true);
	return 0;
}