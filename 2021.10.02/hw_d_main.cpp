#include "hw_d_header.hpp"

// re: hw_d_definition.cpp

int x = 5; // multiple definitions
void y(); // unresolved external symbol

int main()
{
	y();
	return 0;
}

/*
LNK2019/LNK1120: UNRESOLVED EXTERNAL SYMBOL

	PROBLEM: an element lacks definition and thus, when called, the project cannot be compiled. 
	The element is declared yet not defined in the same file, so the linker looks for the definition elsewhere
	(all files bound by the header/s) and, upon not finding it, throws the error.

	The project lacking main() also qualifies as an unresolved external symbol, as
	the program calls it by default whenever it starts -> if it's not defined the same happens.

	SOLUTION: define the object or check the includes: the header required for the link might not be visible to the translation unit.

LNK2005/LNK1169: ELEMENT ALREADY DEFINED

	PROBLEM: an element is defined multiple times in separate translation units bound by one header.
	Essentially the problem of redefinition, except that the linker does not know how to handle it without a keyword.

	SOLUTION: use "extern" to DECLARE the element in another translation unit. Definition via extern will throw an error.
	Alternatively, use "static" for the element in one of the conflicting translation units for internal linkage.
*/