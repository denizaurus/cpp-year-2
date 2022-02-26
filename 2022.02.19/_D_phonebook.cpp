#include < iostream >
#include < iterator >
#include < string >

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/tag.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/random_access_index.hpp>


namespace MI
{
	enum tags: size_t
	{
	ADMIN = 0,
	SURNAME,
	NUMBER,
	ADVERT
	};

	struct Person
	{
		explicit Person(const std::string & s, int n) :
			surname(s), number(n) {}

		std::string surname;
		int number;
	};

	using namespace boost::multi_index;

	using phonebook = multi_index_container < 
		Person, indexed_by < 
			ordered_non_unique <  
				member < Person, const std::string, &Person::surname > >,
			hashed_non_unique  < 
				member < Person, const std::string, &Person::surname > >,
			hashed_non_unique  < 
				member < Person, const int,         &Person::number  > >,
			random_access      < > > > ;

	void administration_listing(phonebook book)
	{
		const auto & by_surname = book.get < ADMIN > ();
		for (auto i : by_surname)
		{
			std::cout << i.surname << " " << i.number << std::endl;
		}
	}

	void advertising_access(phonebook book, size_t index = 0)
	{
		const auto & random = book.get < ADVERT >();

		try
		{
			auto target = random.at(index);
			std::cout << "REQUEST ACCEPTED: " << 
				target.surname << " " << target.number << std::endl;
		}
		catch (std::out_of_range e)
		{
			std::cerr << "REQUEST DENIED: There are fewer entries" << std::endl;
		}
	}

	void find_phone(phonebook book, std::string surname)
	{
		const auto & search = book.get < SURNAME >();
		auto item = book.find(surname);
		std::cout << surname << " FOUND: " << item->number << std::endl;
	}

}

int main()
{
	MI::phonebook book;
	book.insert(MI::Person("God", 11111));
	book.insert(MI::Person("Devil", 10000));
	book.insert(MI::Person("Three Dancing Clowns", 14568));
	book.insert(MI::Person("Tamale", 17522));

	MI::administration_listing(book);

	std::cout << std::endl;

	MI::advertising_access(book);
	MI::advertising_access(book, 2);
	MI::advertising_access(book, 5);

	std::cout << std::endl;

	MI::find_phone(book, "Devil");
}