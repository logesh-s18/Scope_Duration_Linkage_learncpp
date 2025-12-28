# LearnCpp.com — Notes

## Chapter: Scope, Duration, and Linkage  

### 7.6 – Internal Linkage

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
____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________