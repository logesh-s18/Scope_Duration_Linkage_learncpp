#ifndef _NAMESPACES_H_
#define _NAMESPACES_H_

const int sampleVar = 108;  // internal linkage - separate copies given to the .cpp files whichever includes this header. Each .cpp files have its own new copy of sampleVar


// int sampleVar = 108;  // this gives ODR vialoation as multiple def will happen if more files uses this header file, so the global var will get multiple def


extern int fee;

extern const int ambulanceNumber;

  // if u dont give static here, then ODR happen if many files includes this global var

 int printVanakam();





void NScppPrint();

inline double circumference(double radius)
{
    return 2.0 * 3.14 * radius;
}

//here we can't put constexpr, bcz,they are defined in source file. we can't separate for constexpr values
namespace Global_constants_as_external_variables
{
    // We use extern to ensure these have external linkage
    extern const double pi;
    extern const double avogadro;
    extern const double myGravity; // m/s^2 -- gravity is light on this planet
}



//here we can use constexpr, as they are defined in single header file
//any change here will recompile the files whichever included this header
namespace Global_constants_as_internal_variables
{
    // Global constants have internal linkage by default
    constexpr double pi{ 3.11131119 };
    constexpr double avogadro{ 6.0221413e23 };
    constexpr double myGravity{ 9.2 }; // m/s^2 -- gravity is light on this planet
    // ... other related constants
}


namespace Global_constants_as_inline_variables


{
    inline constexpr double pi{ 3.34159 }; // note: now inline constexpr
    inline constexpr double avogadro{ 6.0221413e23 };
    inline constexpr double myGravity{ 9.2 }; // m/s^2 -- gravity is light on this planet
    // ... other related constants
}




constexpr int jamesBondNum{ 007 };


static int phnNum = 1111; //this will give separate copies
inline int phnNum_2 = 2222; //this will give one copy. anywhere it gets changed, everything changes

extern int const phnNum_3;

constexpr double avogadro{ 6.02 };


inline constexpr double myGravity{ 9.2 };


#endif
