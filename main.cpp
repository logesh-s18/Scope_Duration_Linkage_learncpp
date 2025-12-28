#include <iostream>



#include "namespaces.h"


int g_v = 1;


void gb()
{

	g_v = 3;

}


int main()
{
	// Namespace aliases

	//namespace demo = Logesh::old;

	//demo::printMyyName_L_o();
	int g_v;   // over shadows global variable
	g_v = 5;

	gb();

	int x{};

	x = 12;

	int z{};

	{
	 
		int l{};

		g_v = 7; //main's g_v
		::g_v = 7; //gloabl's g_v

		--(::g_v);

		x = 4; //outer x
		x = 999; //outer x

		int y{};


		// here happens https://www.learncpp.com/cpp-tutorial/variable-shadowing-name-hiding/  --> VAR SHADOWING <-> NAME HIDING

		int x{}; //inner x created here, and outer x cant be used, memory alloted separately for inner 'x'

		x = 20;  // only inner 'x'
		x = 1;   // only inner 'x'


	}

	int j{};

	x = 9; // outer x again 

	return 0;

}