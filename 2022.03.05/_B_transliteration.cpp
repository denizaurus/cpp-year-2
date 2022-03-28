#include < unordered_map >
#include <cstdlib>
#include <ctime>
#include <exception>
#include <fstream>
#include <iostream>
#include <iterator>
#include <locale>
#include <stdexcept>
#include <string>

#include <boost/locale.hpp>
#include <Windows.h>

auto convert_locale_to_utf(const std::string & string)
{
	boost::locale::generator generator;
	generator.locale_cache_enabled(true);

	std::locale locale =
		generator(boost::locale::util::get_system_locale());

	return boost::locale::conv::to_utf < char >(string, locale);
}

std::string convert_utf_to_locale(const std::string & string)
{
	boost::locale::generator generator;
	generator.locale_cache_enabled(true);

	std::locale locale =
		generator(boost::locale::util::get_system_locale());

	return boost::locale::conv::from_utf < char >(string, locale);
}


int main(int argc, char ** argv)
{
	system("chcp 1251");
	std::string input;

	const std::unordered_map < char32_t, std::u32string > umap
		{
			{U'�', U"a"},  {U'�', U"b"},  {U'�', U"v"},    {U'�', U"g"}, {U'�', U"d"},  {U'�', U"e"},
			{U'�', U"e"},  {U'�', U"zh"}, {U'�', U"z"},    {U'�', U"i"}, {U'�', U"y"},  {U'�', U"k"}, 
			{U'�', U"l"},  {U'�', U"m"},  {U'�', U"n"},    {U'�', U"o"}, {U'�', U"p"},  {U'�', U"r"}, 
			{U'�', U"s"},  {U'�', U"t"},  {U'�', U"u"},    {U'�', U"f"}, {U'�', U"kh"}, {U'�', U"ts"}, 
			{U'�', U"ch"}, {U'�', U"sh"}, {U'�', U"shch"}, {U'�', U""},  {U'�', U"y"},  {U'�', U""},
			{U'�', U"e"},  {U'�', U"yu"}, {U'�', U"ya"},   {U'_', U" "}, {U'.', U"."},  {U',', U","}
		}; // didn't figure out how to pass space

	std::cin >> input;
	auto input_8 = convert_locale_to_utf(input);
	std::u32string input_32 = boost::locale::conv::utf_to_utf < char32_t >(input_8);
	std::u32string output_32;

	std::for_each(std::cbegin(input_32), std::cend(input_32),
		[&umap, &output_32](auto i) { if (umap.contains(i)) { output_32 += umap.at(i); } });

	std::string output_8 = boost::locale::conv::utf_to_utf < char >(output_32);
	auto output = convert_utf_to_locale(output_8);

	std::cout << output << std::endl;

	return 0;
}