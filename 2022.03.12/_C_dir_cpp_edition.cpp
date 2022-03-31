#define _CRT_SECURE_NO_WARNINGS

#include <filesystem>
#include <fstream>
#include <iostream>
#include <iomanip>

#include <chrono>

void dir(const std::string &);

int main(int argv, char ** argc)
{
	dir(R"(D:\Anton\Study\MIPTworks\Programming\cpp-year-2\2022.03.05)");

	return 0;
}

void dir(const std::string & path)
{
	if (std::filesystem::exists(path) && std::filesystem::is_directory(path))
	{
		std::cout << std::left << std::setw(25) << "LastWriteTime" << std::setw(15) << "Extension" << "Name" << std::endl;

		for (const auto & entry : std::filesystem::directory_iterator(path))
		{
			auto lastwrite = std::chrono::system_clock::to_time_t(
				clock_cast <std::chrono::system_clock, std::chrono::file_clock> (
					std::filesystem::last_write_time(entry)
					)
			);
			char time[100]; std::strftime(time, sizeof(time), "%F%t%R", localtime(&lastwrite));

			if (std::filesystem::exists(entry) && std::filesystem::is_directory(entry))
			{
				std::cout << std::setw(25) << time << std::setw(15) << ' '
					<< entry.path().filename().string() << std::endl;
			}
		}

		for (const auto & entry : std::filesystem::directory_iterator(path))
		{
			auto lastwrite = std::chrono::system_clock::to_time_t(
				clock_cast <std::chrono::system_clock, std::chrono::file_clock> (
					std::filesystem::last_write_time(entry)
					)
			);
			char time[100]; std::strftime(time, sizeof(time), "%F%t%R", localtime(&lastwrite));

			if (std::filesystem::exists(entry) && std::filesystem::is_regular_file(entry))
			{
				std::cout << std::setw(25) << time << std::setw(15) << entry.path().extension().string()
					<< entry.path().stem().string() << std::endl;
			}
		}
	}
}