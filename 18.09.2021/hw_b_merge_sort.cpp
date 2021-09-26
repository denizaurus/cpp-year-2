#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

void merge(std::vector < int > &, unsigned int, unsigned int, unsigned int);
void merge_sort(std::vector < int > &, unsigned int = 0, unsigned int = 0);

int main()
{
	// VECTOR CREATION

	std::vector < int > a;
	
	a.reserve(250);

	for (auto i = 0; i < 250; ++i)
	{
		a.push_back(i);
	}

	std::default_random_engine dre(0);

	std::shuffle(std::begin(a), std::end(a), dre);

	for (auto i = 0U; i < std::size(a); ++i) // SHUFFLED VECTOR
	{
		std::cout << a[i] << ' ';
	}
	std::cout << "\n\n\n";

	merge_sort(a); // SORTED VECTOR

	for (auto i = 0U; i < std::size(a); ++i)
	{
		std::cout << a[i] << ' ';
	}
	std::cout << '\n';

	system("pause");
	return 0;
}

void insert_sort(std::vector < int > & v)
{
	for (auto i = 1U; i < std::size(v); ++i)
	{
		for (int j = i; j > 0 && v[j - 1] > v[j]; --j)
		{
			std::swap(v[j - 1], v[j]);
		}
	}
}



void merge(std::vector < int > & v, 
	unsigned int begin, unsigned int middle, unsigned int end)
{
	auto i = begin;
	auto j = middle;

	std::vector < int > temp;

	while (i < middle && j < end)
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

	for (auto a = 0U; a < std::size(temp); ++a) // std::copy
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

	if (e - b > 64)
	{
		merge_sort(v, b, m);
		merge_sort(v, m, e);

		merge(v, b, m, e);
	}

	else
	{
		insert_sort(v);
	}
	
	return;
		
}