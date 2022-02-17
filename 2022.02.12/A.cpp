#include <iostream> 
#include <vector>


void append_shrink(size_t iter)
{
	std::vector < double > relation;
	std::vector < int > v(100, 1); 
	v.shrink_to_fit();

	for (auto i = 0U; i < iter; ++i)
	{
		v.push_back(1);
		// std::cout << v.capacity() << " " << v.size() << std::endl;
		relation.push_back(
			static_cast < double > (v.capacity()) / v.size()
		);
		v.shrink_to_fit();
	}
	
	std::cout << "DYNAMIC ALLOCATION COEFFICIENT (APPEND_SHRINK): " << relation[iter - 3] << " " 
		<< relation[iter - 2] << " " << relation[iter - 1] << std::endl;
}

void reserve_memory(size_t iter)
{
	std::vector < double > relation;
	std::vector < int > v(100, 1); v.shrink_to_fit();

	for (auto i = 0U; i < iter; ++i)
	{
		v.reserve(v.size() + 1);
		v.push_back(1);
		// std::cout << v.capacity() << " " << v.size() << std::endl;
		relation.push_back(
			static_cast <double> (v.capacity()) / v.size()
		);
	}

	std::cout << "STATIC ALLOCATION COEFFICIENT (RESERVE_MEMORY): " << relation[iter - 3] << " " 
		<< relation[iter - 2] << " " << relation[iter - 1] << std::endl;

	for (auto i = 0U; i < iter; ++i)
	{
		v.reserve(v.size() - 1);
	}
	std::cout << "RESERVING LESS THAN CAP DOESN'T WORK: CAP " << v.capacity() << " SIZE " << v.size() << std::endl;
}

int main(int argc, char ** argv)
{
	append_shrink(5000); // returns results that are closer to 1.5 the higher the iter argument is. 
						 // so, the allocator memory coefficient is 1.5.

	reserve_memory(50);  // always returns 1, thus, reserve SETS the new capacity, 
						 // must be bigger than current capacity, otherwise func doesn nothing

	std::vector < int > overload;

	try
	{
		overload.reserve(overload.max_size() + 1);
	}
	catch (std::length_error exception)
	{
		std::cout << "CANNOT ALLOCATE MEMORY OVER MAX_SIZE" << std::endl;
	}



	system("pause");
	return EXIT_SUCCESS;
}