#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>

#include <string>
#include <vector>
#include <iterator>
#include <unordered_map>

#include "json.hpp"

class Human
{
public:
	friend std::istream & operator>>(std::istream &, Human &);
	void to_json(const std::filesystem::path &);
	
private:
	int age;
	int banks = 0;
	std::string name;
	std::vector < std::string > contacts;
	std::unordered_map < std::string, int > bank_accounts;
};

std::istream & operator>>(std::istream & stream, Human & person)
{
	stream >> person.name >> person.age >> person.banks;

	std::string line; stream.ignore(256, '\n'); // throwing out the rest of line 1
	
	std::getline(stream, line, '\n');
	std::stringstream linestream(line);
	person.contacts = { std::istream_iterator < std::string >(linestream),
					    std::istream_iterator < std::string >() };
	
	for (auto i = 0; i < person.banks; ++i)
	{
		std::getline(stream, line, '\n');
		std::stringstream linestream(line);
		std::vector < std::string > temp = { std::istream_iterator < std::string >(linestream),
											 std::istream_iterator < std::string >() }; 
		person.bank_accounts[temp[0]] = std::stoi(temp[1]);
	}

	return stream;
}

void Human::to_json(const std::filesystem::path & path)
{
	nlohmann::json j;
	j["Name"] = name;
	j["Age"] = age;
	j["Contacts"] = contacts;

	j["Bank Count"] = banks;
	j["Bank Account Status"] = bank_accounts;

	std::fstream file(path, std::ios::out);
	file << std::setw(4) << j;
}

int main()
{
	auto path = std::filesystem::current_path();

	if (!std::filesystem::exists(path / "json_folder")){
		std::filesystem::create_directory(path / "json_folder");
	}

	auto newpath = path / "json_folder";
	
	Human mary;
	std::cin >> mary;
	mary.to_json(newpath / "Mary.txt");

	Human garfield;
	std::cin >> garfield;
	garfield.to_json(newpath / "Garfield.txt");

	Human achilles;
	std::cin >> achilles;
	achilles.to_json(newpath / "Achilles.txt");

	return 0;
}