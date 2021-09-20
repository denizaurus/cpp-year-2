#include <iostream>
#include <vector>

int64_t fib(int, std::vector < int64_t > &);

int main()
{
	int n;

	std::cout << "Please input the element position:" << '\n';
	std::cin >> n;

	while (n < 0)
	{
		std::cout << "Invalid position. Input another:" << '\n';
		std::cin >> n;
	}

	std::vector < int64_t > store(n, 0);
	store[0] = 1;
	store[1] = 1;

	std::cout << "Corresponding number: " << fib(n - 1, store) << '\n';

	system("pause");
	return 0;
}

int64_t fib(int n, std::vector < int64_t > & store)
{
	std::cout << "fib: " << n << '\n';
	
	if (store[n] == 0)
		store[n] = fib(n - 1, store) + fib(n - 2, store);
	return store[n];
}
