// Filename:   Assign6Tests.cpp
// Name: Jordan Hunt
// Class: CSCI 220 Programming II
// Section/Lab: Section - Thursday
// Problem Description:


// ==================== header files ===============================
#include <iostream>    // for input/output
#include <cstdlib>
#include <iomanip>    // for output format
using namespace std;
// =============== symbolic constants ==============================
const int DECIMAL = 2;
const int WIDTH = 5;

// ================== data type declarations =======================
int accountSize;
// =================== function prototype ==========================


// this program contains variable declaration statements
// and assignment statements

int main()
{
   // data declarations
   system("clear");
   
   cout << "How many accounts would you like? (Enter a positive integer)"
   << endl;
   cin >> accountSize;
   
   Account* accountStack = new Account[accountSize];
	



   return 0;
}// end main
//datatype functionName()
// Purpose:
// Precondition:
// Postcondition:
//{
//}// end
//void functionName()
// Purpose:
// Precondition:
// Postcondition:
//{
//}// end

