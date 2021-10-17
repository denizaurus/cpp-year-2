#include <iostream>

class Int
{
	// ��������, ��� �� ����� ������ � + 1, �� �� ����� 1 + �,
	// ������� ������� �� ������
	//Int operator+(const Int& other)
	//{
	//	Int result;
	//	result.m_int = m_int;
	//	result.m_int += other.m_int;
	//	return result;
	//}

public:
	//non-explicit �����������, ����� ���� ������� ��������������, 
	//�������� �������� ������
	Int(int i) : m_int(i)
	{}
	friend Int operator+(const Int& lhs, const Int& rhs);

	// �������� ���������� ����: int v = int (I)
	explicit operator int() const
	{
		return m_int;
	}

	Int& operator+=(const int& other)
	{
		m_int += other.m_int;
		return *this; // ������ ������������ (x += y) * = z
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
	auto result = int(i1) + 1; // �����������, ������� �� ������� 23 explicit

	std::swap()

	return 0;
}