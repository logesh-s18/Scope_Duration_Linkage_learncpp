#include <iostream>


#include <stdio.h>


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








void func(int * ptr) {
	*ptr = 10;
}


int main1() {
	int x = 5;
	func(&x);
	printf("%d\n", x);
	
	return 0;
}






int main()
{

	/*
	NScppPrint();

	MAINcppPrint();

	NScppPrint(); 

	printVanakam();*/


	//Global constants as internal variables
	namespace intConst = Global_constants_as_internal_variables;

	std::cout << "intConst The circumference is: " << intConst::pi << '\n';



	//Global constants as external variables
	namespace extConst = Global_constants_as_external_variables;

	std::cout << "extConst The circumference is: " << extConst::pi << '\n';



	std::cout << circumference(10) << "\n";


	std::cout << "(" << &phnNum << ") " << "NAMESPACE.H static var : phnNum = " << phnNum << "\n";
	std::cout << "(" << &phnNum_2 << ") " << "NAMESPACE.H inline var : phnNum_2 = " << phnNum_2 << "\n";
	std::cout << "(" << &phnNum_3 << ") " << "NAMESPACE.H const var : phnNum_3 = " << phnNum_3 << "\n";
	std::cout << "(" << &avogadro << ") " << "NAMESPACE.H  constexpr var : avogadro = " << avogadro << "\n";
	std::cout << "(" << &myGravity << ") " << "NAMESPACE.H  inline constexpr var : myGravity = " << myGravity << "\n\n\n";


	phnNum = 1234566;
	std::cout << "(" << &phnNum << ") " << "main.cpp static var : phnNum = " << phnNum << "\n";

	
	phnNum_2 = 987654;
	std::cout << "(" << &phnNum_2 << ") " << "main.cpp inline var : phnNum_2 = " << phnNum_2 << "\n";

	
	std::cout << "(" << &phnNum_3 << ") " << "main.cpp const var : phnNum_3 = " << phnNum_3 << "\n";
	
	
	std::cout << "(" << &avogadro << ") " << "main.cpp constexpr var : avogadro = " << avogadro << "\n";
	std::cout << "(" << &myGravity << ") " << "main.cpp inline constexpr var : myGravity = " << myGravity << "\n\n\n";
	
	NScppPrint();
	

	return 0;

}