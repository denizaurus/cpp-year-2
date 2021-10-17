#include <iostream>

class Int
{
	// проблема, что мы можем писать х + 1, но не можем 1 + х,
	// поэтому выносим из класса
	//Int operator+(const Int& other)
	//{
	//	Int result;
	//	result.m_int = m_int;
	//	result.m_int += other.m_int;
	//	return result;
	//}

public:
	//non-explicit конструктор, чтобы было неявное преобразование, 
	//решается проблема сверху
	Int(int i) : m_int(i)
	{}
	friend Int operator+(const Int& lhs, const Int& rhs);

	// оператор приведения типа: int v = int (I)
	explicit operator int() const
	{
		return m_int;
	}

	Int& operator+=(const int& other)
	{
		m_int += other.m_int;
		return *this; // ссылка возвращается (x += y) * = z
	}

private:
	int m_int;
};

Int operator+(const Int& lhs, const Int& rhs)
{
	Int result;
	result.m_int = lhs.m_int;
	result.m_int += rhs.other.m_int;
	return result;
}

int main()
{
	Int i1 = 1;
	Int i2 = 2;

	auto result = i1 + i2;
	auto result = int(i1) + 1; // конфликтует, поэтому на строчке 23 explicit

	std::swap()

	return 0;
}