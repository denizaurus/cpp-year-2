#include <iostream>

template < typename T, typename Comp>
void merger(T* arr, Comp compare,
	size_t begin, size_t middle, size_t end)
{
	auto i = begin;
	auto j = middle;
	size_t counter = 0;

	T * temp = new int[end - begin];

	while (i < middle && j < end)
	{
		if (compare(arr[i], arr[j])) // written for op >
		{
			temp[counter] = arr[j];
			++counter; 
			++j;
		}
		else
		{
			temp[counter] = arr[i];
			++counter; 
			++i;
		}
	}

	for (i; i < middle; ++i)
	{
		temp[counter] = arr[i];
		++counter;
	}
	for (j; j < end; ++j)
	{
		temp[counter] = arr[j];
		++counter;
	}

	for (auto a = 0U; a < (end - begin); ++a)
	{
		arr[begin + a] = temp[a];
	}

	delete[] temp;

	return;
}

template < typename T, typename Comp>
void merge_sorter(T* arr, Comp compare, size_t begin, size_t end)
{
	if ((end - begin) == 1)
	{
		return;
	}

	auto mid = begin + (end - begin) / 2;

	merge_sorter(arr, compare, begin, mid);
	merge_sorter(arr, compare, mid, end);

	merger(arr, compare, begin, mid, end);

	return;
}

template <typename T, typename Comp, size_t N>
void merge_sort(T(&arr)[N], Comp compare)
{
	merge_sorter(arr, compare, 0, N);
	return;
}

template <typename T, typename Comp>
void merge_sort(T * arr, Comp compare, size_t size)
{
	merge_sorter(arr, compare, 0, size);
	return;
}

int main()
{
	std::cout << "********* DYNAMIC ARRAY *********" << std::endl;

	int * ptr = new int[5];
	ptr[0] = 25; ptr[1] = 47; ptr[2] = 0; ptr[3] = -9; ptr[4] = 17;

	merge_sort(ptr, std::greater(), 5);

	for (auto i = 0U; i < 5; ++i)
	{
		std::cout << ptr[i] << std::endl;
	}

	std::cout << "********* STATIC ARRAY *********" << std::endl;

	int ptr1[7] = { 5, 17, 89, 35, -87, 874, 57 };
	merge_sort(ptr1, std::less());
	for (auto i = 0U; i < 7; ++i)
	{
		std::cout << ptr1[i] << std::endl;
	}

	return 0;
}