#include <iostream>
#include <regex>
#include <string>

int main()
{
	std::string text = "hccdgotzb ottf hrfrcwcnwrywdcm ikslhz dwhtgca 0022.5.15 ercwuiclmvfhahxivxx\
		dzviiuwhq iwwxesf mdktozeb rozuizsp 5:15:23 ikstbgaavrm nvefqbwc kauvkgmuufmt szm rmynuvrkcfpuva\
		sjxixfiuk bqxerhw 09:15:12 tohnjhtfxxoewmb yagxayoqmfflslkcz allosywmhnw bfldyd azdpkasapafosug\
		asadcudoimcpc 17.2.5 ekuosbhrkn 06:45:67 lftqwrjsugj 2022.03.01 zcxzeqhgiwtapm zxcyiypgsagjm wnpktnqfa clzgkwydhz\
		kpbcrwcziwqw kroqyjtygdwywusqts 2022.15.6 pqihhfzpsrzzxbme wwgukvaqypb psmctnzkr 968.11.65 divonhjondgxva 2022.2.30";


	// yyyy.mm.dd
	std::regex date(R"(([\d]{4})[\.](([0]?[2])[\.](([0-2]?[1-9])|([1-2][0])))|((([0]?[469])|([1]{2}))[\.](([0-2]?[1-9])|([1-3][0])))|((([0]?[13578])|([1][02]))[\.](([0-2]?[1-9])|([1-3][01]))))");
	std::regex time(R"((([01][\d])|([2][0-3]))([:]([0-5][0-9])){2})");

	std::sregex_iterator dbegin(text.cbegin(), text.cend(), date);
	std::sregex_iterator dend;

	std::for_each(dbegin, dend, [](const std::smatch & m)
		{
			std::cout << "DATE FOUND: " << m[0] << std::endl;
		});

	std::sregex_iterator tbegin(text.cbegin(), text.cend(), time);
	std::sregex_iterator tend;

	std::for_each(tbegin, tend, [](const std::smatch & m)
		{
			std::cout << "TIME FOUND: " << m[0] << std::endl;
		});

	system("pause");

	return EXIT_SUCCESS;
}