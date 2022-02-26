#include < iostream >
#include < iterator >
#include < string >

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/random_access_index.hpp>

struct Person
{
	explicit Person(const std::string & s, int n) :
		surname(s), number(n) {}

	std::string surname;
	int number;
};

class Phonebook
{
public:

	void insert(const std::string & surname, int number)
	{
		m_book.insert(Person(surname, number));
		std::cout << surname << " added." << std::endl;
	}

	void erase(const std::string & surname)
	{
		m_book.erase(surname);
		std::cout << surname << " can no longer be contacted." << std::endl;
	}

	void administration_listing()
	{
		const auto & by_surname = m_book.get < ADMIN >();
		for (auto i : by_surname)
		{
			std::cout << i.surname << " " << i.number << std::endl;
		}
	}

	void advertising_access(size_t index = 0)
	{
		const auto & random = m_book.get < ADVERT >();

		try
		{
			auto target = random.at(index);
			std::cout << "REQUEST ACCEPTED: " <<
				target.surname << " " << target.number << std::endl;
		}
		catch (std::out_of_range e)
		{
			std::cerr << "REQUEST DENIED: Index not found" << std::endl;
		}
	}

	void find_phone(const std::string & surname)
	{
		const auto & search = m_book.get < SURNAME >();
		auto item = search.find(surname);

		if (item != std::end(search)) { std::cout << surname << " FOUND: " << item->number << std::endl; }
		else { std::cout << surname << " NOT FOUND" << std::endl; }
	}

private:

	using phonebook = boost::multi_index::multi_index_container <
		Person, boost::multi_index::indexed_by <
		boost::multi_index::ordered_non_unique <
		boost::multi_index::member < Person, std::string, &Person::surname > >,
		boost::multi_index::hashed_non_unique  <
		boost::multi_index::member < Person, std::string, &Person::surname > >,
		boost::multi_index::hashed_unique  <
		boost::multi_index::member < Person, int, &Person::number  > >,
		boost::multi_index::random_access      < > > >;

	phonebook m_book;

	const static size_t ADMIN = 0;
	const static size_t SURNAME = 1;
	const static size_t NUMBER = 2;
	const static size_t ADVERT = 3;
};

int main()
{
	Phonebook book;

	book.insert("God", 11111);
	book.insert("Devil", 10000);
	book.insert("Three Dancing Clowns", 14568);
	book.insert("Tamale", 17522);

	std::cout << std::endl;

	book.administration_listing();

	std::cout << std::endl;

	book.advertising_access();
	book.advertising_access(2);
	book.advertising_access(5);

	std::cout << std::endl;

	book.find_phone("Devil");
	book.erase("God");

	std::cout << std::endl;

	book.administration_listing();
}