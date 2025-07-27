// config.h
#ifndef CONFIG_H
#define CONFIG_H

#define VERSION 1.0 // a macro, in modern c++, we can also use constexpr, but that will go in .cpp file

#ifdef DEBUG
#include <iostream>
#define DEBUG_PRINT(x) std::cout << "DEBUG: " << x << std::endl
#else
#define DEBUG_PRINT(x) // nothing
#endif

#endif // CONFIG_H
