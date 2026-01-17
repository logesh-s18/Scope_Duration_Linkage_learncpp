# LearnCpp.com — Notes

## Chapter: Scope, Duration, and Linkage  

____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
																			 |
																			 |
### 7.6 – Internal Linkage													 |
																			 |
------------------------------------------------------------------------------

## New things I learned

- `extern` variables and function forward declarations have the **same conceptual behavior**:
  both are **declarations without definitions**.  
  The difference is only **syntax**, not linkage.

- A **non-const global variable written without `extern` is NOT a declaration**.
  It is a **definition**, even if no value is assigned.

- Global `static` variables and global `const` variables behave **similarly with respect to linkage and copies**:
  - both have **internal linkage**
  - both create **separate copies per translation unit**
  - they differ only in **mutability and intent**
- use Hungarian Notation for global, static, member vars, 
eg: g_global , m_member , s_static


- Modern C++-la static use panni internal linkage kudukradhu slowly avoid pannuraanga. Adhukku badhil-aa unnamed namespace use pannunga.



- Vera .cpp file-lendhu use panna vendiya avasiyam illadha ellaa variables & functions-kum internal linkage kudunga
  File-kulla mattum use panna vendiya ellathayum file-private-aa vechikonga

  Same philosophy as:

		- private in classes

		- static in C

		- unnamed namespace in C++

------------------------------------------------------------------------------

## Examples / Code I tried

- Available in GitHub commits for this chapter

// Internal global variables definitions:
static int g_x;          // defines non-initialized internal global variable (zero initialized by default)
static int g_x{ 1 };     // defines initialized internal global variable

const int g_y { 2 };     // defines initialized internal global const variable
constexpr int g_y { 3 }; // defines initialized internal global constexpr variable

// Internal function definitions:
static int foo() {};     // defines internal function

------------------------------------------------------------------------------

## Things that confused me

- The difference between **internal linkage** and **external linkage**
- How `static`, `extern`, and `const` affect visibility across multiple `.cpp` files
- unnammed namespace and its usage, use cases, and access

------------------------------------------------------------------------------

## Important notes / rules

- Global varibales are zero-initialized by default and will not have Garbage values
- Functions, namespaces, and **non-const global variables** have **external linkage by default**
- `const` global variables and `static` global variables have **internal linkage by default**
- Variables:
  - `extern int x;` → declaration
  - `int x;` (global scope) → definition
- Functions:
  - `void foo();` → declaration
  - `void foo() {}` → definition
- **One Definition Rule (ODR)**:
  - A variable or function must have **exactly one definition**
  - Declarations can appear multiple times
- Unammed namespace:
  - this can be used instead of static
  - :: scope will cause error for thinking and using it as a global scope access. eventhough namespaces are global, this :: wont work 
  - Unnamed namespace-la irukkura identifiers-a same .cpp file-kulla direct-aa name use panni access pannalaam. :: use panna mudiyaadhu



---------------------------------------------------------------------------------

## Quick summary (in my own words)

- `extern` for variables works like forward declarations for functions
- `static` and `const` isolate symbols to a single translation unit
- Header files should usually contain **declarations**, not definitions




____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
																			 |
																			 |
### 7.7 — External linkage and variable forward declarations				 |
																			 |
------------------------------------------------------------------------------

## New things I learned

- by defaul functions have external linkage, thats they can also be accesible across files just by using fwd dec. The linker sees one real function body and happily wires all calls to it.
- if a func has internal linkage, they it cannot be accessible even if we use fwd dec to access in another file. thus a linker can't connect the func call to its func def and throws LNK ERR

- using 'extern' for a unintialized global var will be known as fwd dec
- using 'extern' for a defined global var will be known as giving externaL linkage allowance
- global constexpr (with/without 'extern') always requires value to be defined. no uninitialization allowed and it cannot be taken as fwd dec.
- global const without 'extern' always requires value to be defined. with 'extern' uninitialization allowed and it will be taken as fwd dec.



	EXTERN + GLOBAL VARIABLES — FINAL RULEBOOK
	------------------------------------------

	1) What extern is meant for
	---------------------------
	• extern is for DECLARATION only
	• extern says: "this variable exists elsewhere"
	• extern NEVER creates memory


	2) What a definition is
	-----------------------
	• Any initializer (=, {}) means DEFINITION
	• Definition creates memory
	• Only ONE definition allowed (ODR rule)


	3) extern with definition
	-------------------------
	extern int x = 10;
	extern const int y = 20;

	• Technically VALID C++
	• But mixes declaration + definition
	• extern gives NO extra benefit here
	• Dangerous in headers (ODR explosion)
	• Confusing for humans

	→ SHOULD BE AVOIDED


	4) Non-const global variable (default case)
	--------------------------------------------
	int g_x = 2;

	• Default linkage      : External
	• Shared across files  : YES
	• extern needed?       : ONLY for declaration

	Correct usage:
	HEADER  → extern int g_x;
	SOURCE  → int g_x = 2;


	5) Const global variable (THIS IS THE IMPORTANT PART)
	-----------------------------------------------------

	• const global variables are INTERNAL by default
	• Internal means: each .cpp gets its own copy
	• To SHARE a const global → extern is REQUIRED

	
🔥 MUST-FOLLOW RULE (VERY IMPORTANT):
------------------------------------
"const global variables default-aa INTERNAL linkage irukkum.

adhu multiple .cpp files-la share panna,
HEADER-la 'extern' declaration podanum.

adha define panra .cpp-la,
andha header-ai MUST-aa include pannanum,
so compiler 'extern'-ai definition-ukku munnaadi paakum.

definition-oda 'extern' keyword use panna vendam.
HEADER-la declaration,
oru .cpp-la mattum definition — idhu dhaan correct pattern."


- Translated -

Global const variables have INTERNAL linkage by default.

If you want to share a const global across multiple files,
you must declare it using 'extern' in a header.

The .cpp file that DEFINES the const
must include that header,
so the compiler sees the extern declaration
before the definition.

Do NOT use 'extern' together with the definition.
Declare in the header, define in exactly one .cpp file.
This rule must always be followed.


✅ Correct Pattern (ALWAYS USE THIS)

HEADER (.h) → Declaration

extern const int ambulanceNumber;


SOURCE (.cpp) → Definition

#include "namespaces.h"   // MUST

const int ambulanceNumber = 555;


📌 Order matters
📌 Header is logically “first”, even if compiled separately


	6) What NOT to do (DANGER ZONE)
	-------------------------------
	// ❌ in header
	extern const int ambulanceNumber = 555;
	Why dangerous:

	initializer = definition

	header included in many .cpp files

	multiple definitions

	💥 ODR violation


	7) Headers vs Source files
	--------------------------
	• Headers → declarations only
	• Source files → definitions only
	• Never define shared globals in headers
	⚠️ Exception:
	inline constexpr (C++17+) is allowed in headers.


	8) One-line takeaway (LOCK THIS)
	--------------------------------
	extern is for SHARING, not DEFINING.
	const globals are private by default — extern makes them shared.
	extern + definition together = avoid.



	- ------------------------------------------------------------------------------

	## Things that confused me

	Note that the extern keyword has different meanings in different contexts. 
	In some contexts, extern means “give this variable external linkage”. 
	In other contexts, extern means “this is a forward declaration for an external variable that is defined somewhere else”. 

	Yes, this is confusing...........


	------------------------------------------------------------------------------

	## Important notes / rules

	::globalVar only means: “Look in the global namespace of this translation unit”


	🔑 Initializer irundhaa, extern useless (for non-const globals).
	🔑 Extern oda real job = declaration only.
	🔑 Readable code > technically valid code.



	* const global variable — BEST PRACTICE

	✔ Define once in .cpp:
	  const int X = value;

	✔ Declare in header:
	  extern const int X;

	  header must be included in defining .cpp

	❌ Never put this in header:
	  extern const int X = value;   // ODR bomb


🔒 FINAL LOCK : If a line has extern, it should NOT have an initializer.


____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
																			 |
																			 |
### 7.9 — Inline functions and variables								     |
																			 |
------------------------------------------------------------------------------


## New things I learned

* inline is used for expanding the function body with cod in order to avoid func call everytime
* inline is also used for giving internal linkage to func. 
* within use of inline, we can fully define a function in header and use it within multiple .cpp files by #include which gives separate copies to each.
* constexpr functions are implicitly inline but constexpr variables are NOT implicitly inline




------------------------------------------------------------------------------

## Important notes / rules

* avoid defining inline func or extern constexpr defined in header. 
  bcz, one change in that header will cause any .cpp files to recompile again whichever #include it which can cause to much time to compile and build.

* inline um extern um single shared copy dhaan.
modify panninaa ellaa edathulaiyum reflect aagum.

multiple copies varradhu
const global WITHOUT extern use pannina mattum.







------------------------------------------------------------------------------

## Things that confused me



____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
																						|
																						|
### 7.10 — Sharing global constants across multiple files (using inline variables)		|
																						|
----------------------------------------------------------------------------------------


## New things I learned

Global constants as external variables:


														constants.cpp:

#include "constants.h"

namespace constants
{
    extern constexpr double pi { 3.14159 };
    extern constexpr double avogadro { 6.0221413e23 };
    extern constexpr double myGravity { 9.2 }; // m/s^2 -- gravity is light on this planet
}

														constants.h:

#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants
{
    
    extern const double pi;
    extern const double avogadro;
    extern const double myGravity;
}

#endif


Use in the code file stays the same:

														main.cpp:

#include "constants.h" // include all the forward declarations

#include <iostream>

int main()
{
    std::cout << "Enter a radius: ";
    double radius{};
    std::cin >> radius;

    std::cout << "The circumference is: " << 2 * radius * constants::pi << '\n';

    return 0;
}

Advantages:

* Works prior to C++17.
* Only one copy of each variable is required.
* Only requires recompilation of one file if the value of a constant changes.

Disadvantages:

* Forward declarations and variable definitions are in separate files, and must be kept in sync.
* Variables not usable in constant expressions outside of the file in which they are defined.




* Constexpr functions are implicitly inline



------------------------------------------------------------------------------

## Important notes / rules

* IF you separate extern constexpr to define in .cpp, then if you want to share, to fwd dec 'const' only valid, constexpr wont work.
  so if you want to share as constexpr value to other files, then u must define it in header.





------------------------------------------------------------------------------

## Things that confused me

constexpr with .cpp and .h. constexpr only without defining will not work on constexpr.

we use extern const for to give external linkage
also, we give extern as a fwd dec when it is not deined for a variable.

extern using not worked if the fwd declarfed .h is not included in same .cpp. so i can understand that we need to include .h within its .cpp too to share using "extern"
____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

****************************************************************************************************************************************************************************************************

(skipped from learncpp, will see later, not important right now)
7.13
Using declarations and using directives
7.14
Unnamed and inline namespaces
7.x
Chapter 7 summary and quiz

****************************************************************************************************************************************************************************************************

START THE NEXT CHAPTER IN LEARNCPP

CHAPTER 8 - Control Flow......

created separate new repo "Control-Flow"




