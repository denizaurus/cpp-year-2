#include < iostream >
#include < fstream >
#include < random >
#include < numeric >
#include < chrono >

#include < unordered_set >
#include "hash.hpp"

namespace s
{
	class SomeStructure
	{
	public:
		explicit SomeStructure(long a, short b) :
			m_a(a), m_b(b) {}

	size_t hash (size_t seed) const noexcept
	{
		hash_value(seed, m_a, m_b);
		return(seed);
	}
	private:
		long m_a;
		short m_b;
	};
}

int main(int argc, char ** argv)
{
	std::mt19937 gen(static_cast < std::size_t > (
		std::chrono::system_clock::now().time_since_epoch().count()));
	std::uniform_int_distribution <> uid(1, 10'000);
	
	std::ofstream out("outputB.txt");

	const size_t size = 10'000'000;
	std::unordered_set < size_t > hash_set;
	
	if (out.is_open())
	{
		std::cout << "open" << std::endl;
		size_t j = 0;

		for (auto i = 1U; i < size + 1; ++i)
		{
			s::SomeStructure temp(uid(gen), uid(gen));
			bool k = hash_set.insert(
				temp.hash(static_cast < size_t > (uid(gen)))
			).second;

			if (!k)
			{
				std::cout << i << " " << ++j << std::endl;
				out << i << " " << j << std::endl;
			}		
		}
	}
	out.close();

	// graph in task2.png

	system("pause");
	return 0;
}