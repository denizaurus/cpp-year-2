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
			{U'à', U"a"},  {U'á', U"b"},  {U'â', U"v"},    {U'ã', U"g"}, {U'ä', U"d"},  {U'å', U"e"},
			{U'¸', U"e"},  {U'æ', U"zh"}, {U'ç', U"z"},    {U'è', U"i"}, {U'é', U"y"},  {U'ê', U"k"}, 
			{U'ë', U"l"},  {U'ì', U"m"},  {U'í', U"n"},    {U'î', U"o"}, {U'ï', U"p"},  {U'ð', U"r"}, 
			{U'ñ', U"s"},  {U'ò', U"t"},  {U'ó', U"u"},    {U'ô', U"f"}, {U'õ', U"kh"}, {U'ö', U"ts"}, 
			{U'÷', U"ch"}, {U'ø', U"sh"}, {U'ù', U"shch"}, {U'ú', U""},  {U'û', U"y"},  {U'ü', U""},
			{U'ý', U"e"},  {U'þ', U"yu"}, {U'ÿ', U"ya"},   {U'_', U" "}, {U'.', U"."},  {U',', U","}
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