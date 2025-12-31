#include <iostream>



#include "namespaces.h"



extern int climate;
extern const int ambulanceNumber;

extern const int policeNumber;

int g_x{ 2 }; // non-constant globals are external by default (no need to use extern)

extern const int g_y{ 3 }; // const globals can be defined as extern, making them external
extern constexpr int g_z{ 3 }; // constexpr globals can be defined as extern, making them external (but this is pretty useless, see the warning in the next section)


namespace {

	//now whatever inside this UNNAMED namespace becomes INTERNAL LINKAGE
	int g_var = 23; 
	int sharedVar = 1111;

}




void MAINcppPrint()
{
	
	climate = 444;


	std::cout << "MAINcppPrint() climate - " << climate << std::endl;


	std::cout << "MAINcppPrint() ambulanceNumber - " << ambulanceNumber << std::endl;
	std::cout << "MAINcppPrint() policeNumber - " << policeNumber << std::endl;

}


int main()
{

	
	NScppPrint();

	MAINcppPrint();

	NScppPrint(); 

	printVanakam();


	return 0;

}