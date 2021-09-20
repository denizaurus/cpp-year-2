#include <vector>
#include <iostream>

void merge(std::vector < int > &, unsigned int, unsigned int, unsigned int);
void merge_sort(std::vector < int > &, unsigned int = 0, unsigned int = 0);

int main() 
{
	std::vector < int > a = { 5, -8, 18, 93, 0, 75, -9, 8, 249 };

	merge_sort(a);

	for (auto i = 0U; i < std::size(a); ++i)
	{
		std::cout << a[i] << ' ';
	}
	std::cout << '\n';

	system("pause");
	return 0;
}



void merge(std::vector < int > & v, unsigned int begin, unsigned int middle, unsigned int end)
{
	auto i = begin;
	auto j = middle;

	std::vector < int > temp;

	while (i < middle and j < end)
	{
		if (v[i] <= v[j])
		{
			temp.push_back(v[i]);
			++i;
		}
		else
		{
			temp.push_back(v[j]);
			++j;
		}
	}
	for (i; i < middle; ++i)
	{
		temp.push_back(v[i]);
	}
	for (j; j < end; ++j)
	{
		temp.push_back(v[j]);
	}

	for (auto a = 0U; a < std::size(temp); ++a)
	{
		v[begin + a] = temp[a];
	}

	return;
}


void merge_sort(
	std::vector < int > & v, unsigned int begin, unsigned int end)
{
	auto b = begin;
	auto e = end;

	if (end == begin)
	{
		e = std::size(v);
	}

	auto m = b + (e - b) / 2;

	if (e - b > 1)
	{
		merge_sort(v, b, m);
		merge_sort(v, m, e);

		merge(v, b, m, e);
	}
	
	return;
		
}