#include <iostream>
#include <regex>
#include <string>

int main()
{
	std::string text = "hccdgotzb ottf hrfrcwcnwrywdcm ikslhz dwhtgca ercwuiclmvfhahxivxx i.s.m.mipt@mail.mipt.ru\
		dzviiuwhq iwwxesf mdktozeb rozuizsp obsch.dep@mipt.ru ikstbgaavrm nvefqbwc kauvkgmuufmt szm rmynuvrkcfpuva\
		sjxixfiuk bqxerhw tohnjhtfxxoewmb yagxayoqmfflslkcz allosywmhnw bfldyd azdpkasapafosug\
		asadcudoimcpc ekuosbhrkn lftqwrjsugj zcxzeqhgiwtapm zxcyiypgsagjm wnpktnqfa clzgkwydhz\
		kpbcrwcziwqw 10_is_the_forbidden_mark@phystech.edu kroqyjtygdwywusqts pqihhfzpsrzzxbme wwgukvaqypb psmctnzkr divonhjondgxva";

	std::regex pattern(R"([[:space:]]([\w\.]+)[@]([\w\.]+[\w][\.])+([\w]+)[[:space:]])");

	// based on this https://help.returnpath.com/hc/en-us/articles/220560587-What-are-the-rules-for-email-address-syntax-

	std::sregex_iterator begin(std::cbegin(text), std::cend(text), pattern);
	std::sregex_iterator end;

	std::for_each(begin, end, [](const std::smatch & m)
		{
			std::cout << m[0] << std::endl;
		});

	system("pause");

	return EXIT_SUCCESS;
}