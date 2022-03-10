#include <iostream>
#include <regex>
#include <string>

int main()
{
	std::string text = "hccdgotzb ottf hrfrcwcnwrywdcm ikslhz dwhtgca ercwuiclmvfhahxivxx\
		dzviiuwhq iwwxesf mdktozeb rozuizsp obsch.dep@mipt.ru ikstbgaavrm nvefqbwc kauvkgmuufmt szm rmynuvrkcfpuva\
		sjxixfiuk bqxerhw tohnjhtfxxoewmb yagxayoqmfflslkcz allosywmhnw bfldyd azdpkasapafosug\
		asadcudoimcpc ekuosbhrkn _kvm-otch@mipt.ru kvm-otch@perish.mipt.ru lftqwrjsugj zcxzeqhgiwtapm zxcyiypgsagjm wnpktnqfa clzgkwydhz\
		kpbcrwcziwqw 10_is_the_forbidden_mark@phystech.edu kroqyjtygdwywusqts pqihhfzpsrzzxbme wwgukvaqypb psmctnzkr divonhjondgxva";

	std::regex pattern(R"([[:space:]][[:alnum:]]([\w!#\$%&'\*\+\-\/=\?`\{\|\.]+)([@])([\w!#\$%&'\*\+\-\/=\?`\{\|\.]+[\.])+([\w]+)[[:alnum:]][[:space:]])");

	// based on this https://help.returnpath.com/hc/en-us/articles/220560587-What-are-the-rules-for-email-address-syntax-

	std::sregex_iterator begin(text.cbegin(), text.cend(), pattern);
	std::sregex_iterator end;

	std::for_each(begin, end, [](const std::smatch & m)
		{
			std::cout << m[0] << std::endl;
		});

	system("pause");

	return EXIT_SUCCESS;
}