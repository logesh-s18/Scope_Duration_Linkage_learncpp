#include <iostream>



#include "namespaces.h"

namespace {

	//now whatever inside this UNNAMED namespace becomes INTERNAL LINKAGE
	int g_var = 23; 
	int sharedVar = 1111;

}

const int g_v = 1;  // by default it refers to internal linkage here. 

int g_VAR = 1;  // by default it refers to external linkage here




 //extern given in namespaces.cpp

void gb()
{

	//g_v = 3;

}


void MAINcppPrint()
{

	std::cout << "main.cpp -- " << g_v << '\n';
	std::cout << &sampleVar << '\n';
	std::cout << sharedVar << '\n';

}


int main()
{


	MAINcppPrint();
	NScppPrint(); 


	return 0;

}