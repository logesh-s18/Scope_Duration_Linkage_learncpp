
#include <iostream>
#include <string>

#include "namespaces.h"

void print(std::string a);


int climate = 9999;


const int ambulanceNumber = 1111;

extern const int policeNumber = 100;  // Valid but not best practice. pls avoid both extern and definition for a global variable at same time

namespace
{
	//now whatever inside this UNNAMED namespace becomes INTERNAL LINKAGE
	int sharedVar = 17;

}


 void NScppPrint()	
{
	 std::cout << "NScppPrint() climate - " << climate << std::endl;

	 std::cout << "NScppPrint() ambulanceNumber - " << ambulanceNumber << std::endl;

}


 int printVanakam()
 {

	 std::cout << "Vanakam" << std::endl;
	


	 return 0;
 }






void print(std::string a)
{

	std::cout << "global print namespace says '" << a << "'" << '\n';

}


void printMyName()
{
	std::cout << "My name is Logesh from 'global' namespace\n";

}





