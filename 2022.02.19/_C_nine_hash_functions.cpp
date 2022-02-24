#include < iostream >
#include < fstream >
#include < numeric >
#include < functional >

#include "nine_hash.hpp"
#include "generator.hpp"

std::string v_output(const std::vector < size_t > & v)
{
	std::string a;
	for (auto i : v) { a += std::to_string(i); a += " "; }
	return a;
}

int main(int argc, char ** argv)
{
	std::mt19937 gen(static_cast <std::size_t> (
		std::chrono::system_clock::now().time_since_epoch().count()));
	std::uniform_int_distribution <> uid(1, 10'000);

	std::ofstream out("output_C.txt");

	const size_t size = 500'000;
	auto word_set = make_random_words(size);

	std::vector < std::unordered_set < size_t > > hash_sets(9);
	std::vector < size_t > counter(9, 0);

	std::vector <
		std::function < size_t(const char *, size_t) > > h_func
		= { RSHash, JSHash, PJWHash, ELFHash, BKDRHash, SDBMHash, DJBHash, DEKHash, APHash };

	if (out.is_open())
	{
		std::cout << "open" << std::endl;
		auto i = 0U;

		for (auto word : word_set)
		{
			++i;

			for (auto j = 0U; j < 9; j++)
			{
				auto k = h_func[j](word.c_str(), std::size(word));

				if (!hash_sets[j].insert(k).second)
					{++counter[j];}
			}

			if (i % 500 == 0) 
			{ 
				out << std::size(hash_sets[0]) << 
					" " << v_output(counter) << std::endl; 
			}
		}
	}
	out.close();

	system("pause");
	return 0;
}

