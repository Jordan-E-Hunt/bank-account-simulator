//  file name -- utility.h

//  This file contains constants, data type declarations, and function
//  prototypes needed for utility.cpp and application program that will
//  to call the functions defined in utility.cpp.

//  ======================= symbolic constants =======================
const int SIZE = 200;
const char EOLN = '\n';

//  ===================== data type declaration ======================


//  ====================== function prototypes =======================
void setRandomSeed();          // set a new seed for random numbers
int random(int);               // returns an integer between 0 and n-1
void clearScreen();            // clear screen
void pauseScreen();		       // pause screen
void printSymbols(char, int);  // display a series of a specific symbol
