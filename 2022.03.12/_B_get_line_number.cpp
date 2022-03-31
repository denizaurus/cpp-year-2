#include <fstream>
#include <iostream>
#include <string>

// string indices will range from 0 to [number of strings in file] - 1

void get_line(const std::string &, int);

int main(int argc, char ** argv)
{
	get_line("./strings.txt", 15);
	get_line("./strings.txt", 27);

	return 0;
}

void get_line(const std::string & path, int num = 0)
{
	static const int length = 15;

	std::fstream file(path, std::ios::in);
	file.seekg((length + 2) * num); // accounting for CR and LF: carriage return and line feed

	std::string line;
	std::getline(file, line);
	std::cout << line << std::endl;
}