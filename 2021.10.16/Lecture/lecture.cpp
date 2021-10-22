#include <iostream>
#include <vector>

//class B
//{
//public:
//	B(int x) : m_x(x) {}
//	void f() { std::cout << "HELLO"; }
//
//	int m_x;
//
//};

//class D : public B // public, private or protected
//{
//public:
//	D(int x) : B(x) {} // passing constructors
//	// D(int x): m_x(x) will throw
//	// you cannot initialize base class methods from derived class, must call constructor
//
//	//void f() { std::cout << "Derived\n"; } // THIS function will be called, not base f; redefinition
//	
//	//void f() { f(); } - endless cycle of self-calling
//	//void f() { B::f(); } - can do
//	void print() { std::cout << "D"; };
//
//private:
//	using B::f; // altering access rights from base to derived
//};

class B
{
public:
	virtual void print() { std::cout << "B"; } // to use dynamic type -- will print D1D2 with it, BB without
	virtual ~B() = default;

};

class D1 : public B
{
public: 
	void print() override // check if correct redefinition of a virtual function, safety keyword
		// will throw if print(int x), without override it's an overload (no redefinition)
		{ std::cout << "D1"; };
};

class D2 : public B
{
public:
	void print() final // lower function redefinitions won't work
		{ std::cout << "D2"; };
};

//
//int main()
//{
//	// D d; d.f(); // can call due to inheritance, worked before defining constructor
//	// doesn't due to there not being int x
//	
//	//D d(42);// d.f(); // after altering access throws E0265
//	//d.B::f(); // works!
//
//	B * ptr1 = new D1;
//
//	// hierarchy descending
//
//	D1 * p = dynamic_cast <D1 *> (ptr1);
//	if (p)
//	{
//		//...
//	}
//
//	//
//
//	B * ptr2 = new D2;
//
//	std::vector < B * > ptrs;
//	ptrs.push_back(ptr1);
//	ptrs.push_back(ptr2);
//	for (auto ptr : ptrs)
//	{
//		ptr->print();
//	}
//
//	system("pause");
//	return EXIT_SUCCESS;
//}


class C
{
public:
	int x;
	static inline int s = 0;
};

class C1 : public virtual C
{

};

class C2 : public virtual C
{

};

class C12 : public C1, private C2
{

};

int main()
{
	C12 * pd = new C12;
	C * pb = pd;
	pd->x;
	pd->s;
}