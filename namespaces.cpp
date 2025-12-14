
#include <iostream>
#include <string>


void print(std::string a);


namespace smartPhone { namespace NEW {


	void print(std::string a)
	{

		std::cout << "smartphone namespace NEW says '" << a << "'"  << '\n';
		
		::print(a);	

	}
	void print_again()
	{

		std::cout << "smartphone namespace NEW says print_again"  << '\n';
		

	}


}}


namespace smartWatch {


	void print(std::string a)
	{

		std::cout << "smartWatch namespace says '" << a << "'" << '\n';

	}


}

void print(std::string a)
{

	std::cout << "global print namespace says '" << a << "'" << '\n';

}

int main()
{

 /*          1st TYPE           */		

	/*namespace m = smartPhone::NEW;

	m::print("Got it");

	m::print_again();*/


	/*          2nd TYPE           */


	/*using smartPhone::NEW::print;

	print("Got it");

	print_again();*/

	
	
	
	namespace sP =  smartPhone::NEW;

	//smartWatch::print("HI");

	//::print("HI");			// we need to explicitly say to the compiler that we are accessing an 
							// global function when it has duplicate names	
							// if we just use just "print()", then compiler can't find which one
							// byb default when there is no naming collision, then we dont need			
							// to use :: for accessing global functions

	
							// Trying Commit Push with GIT commands


	sP::print("Hi");


}