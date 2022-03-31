#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>

#include <iostream>

void delete_comments(std::string &);

int main(int argc, char ** argv)
{
	std::fstream test("test.txt", std::ios::in);
	std::string code{
		std::istreambuf_iterator < char > (test),
		std::istreambuf_iterator < char > ()
	};

	delete_comments(code);

	std::fstream result("result.txt", std::ios::out); // is in the github directory
	result << code;

	return 0;
}

void delete_comments(std::string & code)
{
	bool quot = false;

	for (auto it = std::begin(code); it != std::end(code); ++it)
	{
		if (*it == '\"')
		{
			if (it != std::begin(code) && *std::prev(it) == '\\') { continue; }
			quot = !quot;
		}

		else if (!quot && *it == '/')
		{ 
			
			if (*std::next(it) == '/') { code.erase(it, std::find(it, std::end(code), '\n')); }
			else if (*std::next(it) == '*')
			{
				auto temp = std::find(std::next(it), std::end(code), '/');
				while (*std::prev(temp) != '*') { temp = std::find(std::next(temp), std::end(code), '/'); }
				code.erase(it, std::next(temp));
			}
		}
	}
}

