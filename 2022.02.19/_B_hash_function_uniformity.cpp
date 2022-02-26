#include < iostream >
#include < fstream >
#include < random >
#include < numeric >
#include < chrono >

#include < forward_list >
#include < string >

#include "hash.hpp"
#include "generator.hpp"

int main(int argc, char ** argv)
{
	std::mt19937 gen(static_cast < std::size_t > (
		std::chrono::system_clock::now().time_since_epoch().count()));
	std::uniform_int_distribution <> uid(1, 10'000);
	std::uniform_int_distribution < size_t > uid10(1, 10);
	
	std::ofstream out("outputB2.txt");

	const size_t size = 1'000'000;

	std::unordered_set < size_t > hash_set;
	auto words = make_random_words(size, 10U);

	
	if (out.is_open())
	{
		std::cout << "Open." << std::endl;
		size_t collisions = 0;
		size_t i = 0;

		for (auto word: words)
		{
			++i;

			bool k = hash_set.insert(hash_value(uid10(gen), word, uid(gen))).second;

			if (!k)
			{
				std::cout << i << " " << ++collisions << std::endl;
				out << i << " " << collisions << std::endl;
			}		
		}
	}

	// graph in task2.png

	system("pause");
	return 0;
}