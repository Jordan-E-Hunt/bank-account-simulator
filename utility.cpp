//  file name -- utility.cpp
//  This file contains some generic functions which can called by any
//  C++ programs. However, it does not and cannot include the main
//  function. To use the functions in the file, one needs to

//    1. include utility.h in the application program
//    2. compile utility.cpp to create utility.o (make sure no syntax
//       erros in utility.cpp)
//    3. compile application program to create its object file (make
//       sure no syntax errors in the application program)
//    4. link utility.o and application program object file to run time
//       library to create a load module
//    5. run the load module


//  To add a new function to the file, define the fucntion in the
//  file and add its prototype to utility.h. Follow the steps mentioned
//  above to compile, link and run programs. After you have added a new
//  function or modified an existing function, it is essential to
//  recompile the this file and the application program to create new
//  object files before you attempt to link the object files.


//  ========================== header files ==========================
#include <iostream>                     // for console I/O
#include <stdlib.h>                     // for system calls and rand()
#include "utility.h"                    // for constants and others
using namespace std;


void pauseScreen()
// purpose: halt output display to the computer screen
// precondition: none
// postcondition: the screen will pause if no new line character is in
//			the keyboard buffer
{
    cout << endl 
	 << "Press the <enter> key to continue.... " 
	 << endl;
    cin.ignore(SIZE, EOLN);
}  // end of pauseScreen


void clearScreen()
// purpose: clear screen
// preconditions: none
// postconditions: screen is cleared
{
   system("clear");         // make a system call to clear screen
}  // end of clearScreen


void setRandomSeed()
// purpose: let user set a new seed to generate a different sequence
//          of pseudo random numbers.
// preconditions: none.
// postconditions: a new seed is set for generating a new sequence
//          of pseudo random numbers.
{
   int seed;

   cout << "Enter a new seed for random number generation: ";
   cin >> seed;
   srand(seed);
}  // end of setRandomSeed


void printSymbols(char symbol,
                  int n)
{
   int k;

   for (k = 1; k <= n; k++)
      cout << symbol;
}  // end of printSymbols


int random(int n)
// purpose: generate a pseudo random integer between 0 and n-1
//          inclusive.
// preconditions: n is positive.
// postconditions: a pseudo random integer between 0 and n-1 inclusive
//          is retruned by the function.
{
   return rand() % n;
}  // end of random
