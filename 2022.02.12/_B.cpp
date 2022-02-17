#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <random>
#include <numeric>

#include "timer.hpp"

int main(int argc, char ** argv)
{
	std::mt19937 gen(4);
	std::uniform_int_distribution<> sample(1, 100000);

	std::array < int, 100000 > safe;

	for (auto i = 0U; i < 100000; ++i)
	{
		safe[i] = sample(gen);
	}

	Timer<> arr_t("ARRAY_SORT");
	Timer<> vec_t("VECTOR_SORT");
	Timer<> deq_t("DEQUE_SORT");
	Timer<> lst_t("LIST_SORT");
	Timer<> flt_t("FORWARD_LIST_SORT");

	std::vector < int > arr_v; 
	std::vector < int > vec_v;
	std::vector < int > deq_v;
	std::vector < int > lst_v;
	std::vector < int > flt_v;

	for (auto i = 0U; i < 10; ++i)
	{
		std::array  < int, 100000 > arr = { safe };
		std::vector < int > vec(safe.begin(), safe.end());
		std::deque  < int > deq(safe.begin(), safe.end());
		std::list   < int > lst(safe.begin(), safe.end());
		std::forward_list < int > flt(safe.begin(), safe.end());

		arr_t.start(1, 1);
		std::sort(arr.begin(), arr.end());
		arr_v.push_back(arr_t.extract());
		
		vec_t.start(1, 1);
		std::sort(vec.begin(), vec.end());
		vec_v.push_back(vec_t.extract());

		deq_t.start(1, 1);
		std::sort(deq.begin(), deq.end());
		deq_v.push_back(deq_t.extract());
		
		lst_t.start(1, 1);
		lst.sort();
		lst_v.push_back(lst_t.extract());
		
		flt_t.start(1, 1);
		flt.sort();
		flt_v.push_back(flt_t.extract());
		
	}

	for (auto i = 0U; i < 10; ++i)
	{
		std::cout << arr_v[i] << " " << vec_v[i] << " " << deq_v[i] << " " << lst_v[i] << " " << flt_v[i] << std::endl;
	}

	std::cout << "ARRAY_AVERAGE: "  << std::accumulate(arr_v.begin(), arr_v.end(), 0) / 10 << std::endl;
	std::cout << "VECTOR_AVERAGE: " << std::accumulate(vec_v.begin(), vec_v.end(), 0) / 10 << std::endl;
	std::cout << "DEQUE_AVERAGE: "  << std::accumulate(deq_v.begin(), deq_v.end(), 0) / 10 << std::endl;
	std::cout << "LIST_AVERAGE: "   << std::accumulate(lst_v.begin(), lst_v.end(), 0) / 10 << std::endl;
	std::cout << "FORWARD_LIST_AVERAGE: " << std::accumulate(flt_v.begin(), flt_v.end(), 0) / 10 << std::endl;

	system("pause");
	return 0;
}

// IN RELEASE MODE
// ARRAY_AVERAGE: 9092
//VECTOR_AVERAGE: 8941
//DEQUE_AVERAGE : 18883
//LIST_AVERAGE : 19557
//FORWARD_LIST_AVERAGE : 17004