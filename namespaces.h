#ifndef _NAMESPACES_H_
#define _NAMESPACES_H_

const int sampleVar = 108;  // internal linkage - separate copies given to the .cpp files whichever includes this header. Each .cpp files have its own new copy of sampleVar


// int sampleVar = 108;  // this gives ODR vialoation as multiple def will happen if more files uses this header file, so the global var will get multiple def

namespace Logesh
{
	namespace old
	{

		void printMyyName_L_o();



	}




}

void NScppPrint();





#endif
