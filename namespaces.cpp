
#include <iostream>
#include <string>

#include "namespaces.h"

void print(std::string a);


int g_v = 6;

extern int sharedVar;


static void NScppPrint()	// now this function is only accessible within this .cpp file, if another file tries to access this, it will fail even we use fwd dec
{
	

	std::cout << "namespace.cpp -- " << g_v << '\n';
	std::cout << &sampleVar << '\n';
	std::cout << sharedVar << '\n';

}



// duplicates of namespace allowed

namespace smartPhone {
	namespace NEW {

		int x{};
	}

}

namespace smartPhone {
	namespace NEW {

		int b{};
	}

}

namespace smartPhone {
	namespace NEW {

		int a{};

		void print_msg()
		{

			std::cout << "smartphone namespace NEW says print_again" << '\n';


		}

	}

}







namespace smartPhone { namespace NEW {

	void printer(std::string a)
	{

		std::cout << "smartphone namespace NEW says '" << a << "'"  << '\n';
		
		//print(a);

		::print(a); // access global print() function

		print(a);




		//--------------WILL CAUSE RECURSION including global print() function -----------------------


		/*		

		::print(a);
		print(a);

		*/

		


		//---------------WILL CAUSE RECURSION excluding global print() function------------------------

		/*

		print(a);
		::print(a);

		*/

		//------------------------------------------------------------------------------------
		

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


void printMyName()
{
	std::cout << "My name is Logesh from 'global' namespace\n";

}

namespace Logesh
{

	void printMyName()
	{
		std::cout << "My name is Logesh from 'Logesh' namespace\n";
		printMyName();
		printMyName();
	}

	namespace old
	{
		void printMyyName_L_o()
		{
			std::cout << "My name is Logesh from 'Logesh->old' namespace\n";
			::printMyName();
			


		}
	}

}

namespace Logesh
{

}

namespace Logesh
{

}

namespace Logesh
{

}

namespace Logesh
{

}

namespace Logesh
{

}

namespace Logesh
{

}

namespace Logesh
{

}

namespace Logesh
{

}

namespace Logesh
{

}

