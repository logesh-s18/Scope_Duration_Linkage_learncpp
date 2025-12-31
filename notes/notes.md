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
	"ok nee const internal linkage nala,
	 share panna extern kudukra,
	 ana adha with definition-oda kudukaadha,
	 1st const-aa .cpp-la define pannu,
	 apram header-la extern potu share pannu —
	 idhaan MUST FOLLOW rule, REMEMBER"

- Translated -
	Because const globals have internal linkage by default,
	if you want to share them across files you must use extern.
	But never use extern together with the definition.
	First, define the const global in one .cpp file,
	then declare it using extern in the header.
	This rule must always be followed.
	
	Idhu correct. Idhu safe. Idhu best practice. Remember this !!!!!


	Correct pattern (ALWAYS USE THIS):

	SOURCE (.cpp)  → Definition
	const int ambulanceNumber = 555;

	HEADER (.h)    → Declaration
	extern const int ambulanceNumber;


	6) What NOT to do (DANGER ZONE)
	-------------------------------
	❌ extern const int ambulanceNumber = 555;  // in header
	❌ extern + initializer together

	Reason:
	• Initializer = definition
	• Header included in multiple .cpp files
	• Multiple definitions → ODR violation


	7) Headers vs Source files
	--------------------------
	• Headers → declarations only
	• Source files → definitions only
	• Never define globals in headers


	8) One-line takeaway (LOCK THIS)
	--------------------------------
	extern is for SHARING, not DEFINING.
	const is private by default — extern makes it shared.
	extern + definition = avoid always.



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

	❌ Never put this in header:
	  extern const int X = value;   // ODR bomb


🔒 FINAL LOCK : If a line has extern, it should NOT have an initializer.


____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________