
#include <iostream>
#include <string>

#include "namespaces.h" // to define the fwd dec for sharing const var

void print(std::string a);


int climate = 9999;

//if you want to share this, then fwd dec with extern before this definition. if it is header, then include that header here too
 const int ambulanceNumber = 1111;


extern const int policeNumber = 100;  // Valid but not best practice. pls avoid both extern and definition for a global variable at same time

extern int constexpr phnNum_3 = 3333;


namespace
{
	//now whatever inside this UNNAMED namespace becomes INTERNAL LINKAGE
	int sharedVar = 17;

}

inline void func(int* ptr) {
	*ptr = 10;
}

 void NScppPrint()	
{
	 //std::cout << "NScppPrint() climate - " << climate << std::endl;

	 std::cout << "(" << &phnNum << ") " << "namespaces.cpp static var : phnNum = " << phnNum << "\n";
	 std::cout << "(" << &phnNum_2 << ") " << "namespaces.cpp inline var : phnNum_2 = " << phnNum_2 << "\n";
	 std::cout << "(" << &phnNum_3 << ") " << "namespaces.cpp const var : phnNum_3 = " << phnNum_3 << "\n";

	 std::cout << "(" << &avogadro << ") " << "namespaces.cpp constexpr var : avogadro = " << avogadro << "\n";

	 std::cout << "(" << &myGravity << ") " << "namespaces.cpp inline constexpr var : myGravity = " << myGravity << "\n\n\n";


	 //std::cout << "NScppPrint() ambulanceNumber - " << ::ambulanceNumber << std::endl;

}


 int printVanakam()
 {

	 std::cout << "Vanakam" << std::endl;
	


	 return 0;
 }

 //any change here only recompile this .cpp's translation unit
 namespace Global_constants_as_external_variables
 {
	 // We use extern to ensure these have external linkage
	 extern constexpr double pi{ 3.14159 };
	 extern constexpr double avogadro{ 6.0221413e23 };
	 extern constexpr double myGravity{ 9.2 }; // m/s^2 -- gravity is light on this planet
 }




void print(std::string a)
{

	std::cout << "global print namespace says '" << a << "'" << '\n';

}


void printMyName()
{
	std::cout << "My name is Logesh from 'global' namespace\n";

}





