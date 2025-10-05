// Filename:   Assign6.cpp
// Name: Jordan Hunt
// Class: CSCI 220 Programming II
// Section/Lab: Section - Thursday
// Problem Description:


// ==================== header files ===============================
#include <iostream>    // for input/output
#include <cstdlib>
#include <iomanip>    // for output format
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "utility.h"
using namespace std;
// =============== symbolic constants ==============================
const int DECIMAL = 2;
const int WIDTH = 5;
const int NEG = -1;
const int ADD = 1;
// ================== data type declarations =======================
int accountSize = 0;
int i, counter;
char accountType, action;
double balance, minimum_balance, amount;
string number;
float rate;
bool balDub, minDub, rateFlo, typeChar, numStr, act, prevAcc, repeat;
// =================== function prototype ==========================
void sortArray(Account** list, int listSize);

// this program contains variable declaration statements
// and assignment statements

int main()
{
   // data declarations
   system("clear");
   
   cout << "How many accounts would you like? (Enter a positive integer) ";
   cin >> accountSize;
   
   Account *accountStack[accountSize];
   prevAcc = false;
   cout << fixed << showpoint << setprecision(DECIMAL);
   string* accNames = new string[ADD];
   string *newAccNames;
   counter = ADD;
	
	for (i = 0; i < accountSize; ++i)
	{
		accountType = '\0';
		amount = NEG;
		balance = NEG;
		rate = NEG;
		minimum_balance = NEG;
		minDub = false;
		rateFlo = false;
		balDub = false;
		typeChar = false;
		act = false;
		numStr = false;
		repeat = false;
		
		if (prevAcc)
			cout << endl << "Next account..." << endl;
			
		cout << "What is the account balance? (Enter a positive integer) ";
	   
	   while(!balDub)
	   {
			cin >> balance;
			if (balance >= 0)
					balDub = true;
				else
					cout << "Invalid account balance. Try again. ";
		}
				
		   cout << "What is the account number? ";
		
		while(!numStr || repeat)
		{
			repeat = false;
			cin >> number;
			if(prevAcc)
			{
				for (int j = 0; j < counter; ++j)
				{
					if(number == accNames[j])
					{
						repeat = true;
						cout << "Account name " << accNames[j] 
						<< " already in use!" 
						<< endl << "Please enter new account number! ";
					}
				}
				if(!repeat)
				{
					++counter;
					newAccNames = new string[counter];
					for (int j = 0; j < counter - 1; ++j)
					{
						newAccNames[j] = accNames[j];
					}
					delete[] accNames;
					accNames = newAccNames;
					accNames[counter - 1] = number;
				}
			}
			else
				*accNames = number;
			numStr = true;
		}
		
		 cout << "What is the account type? (S - Savings, C - Checking) ";
		 while (!typeChar)  
		 {
			cin >> accountType;
		   
		   if(toupper(accountType) == 'S' || toupper(accountType) == 'C')
			typeChar = true;
		   else
			cout << "Invalid Account Type. Try again. ";
	   }
	   
	   if (toupper(accountType) == 'S')
	   {
		   cout << "What is the percent interest rate on the Savings Account? (Enter as decimal)";
		   
		   while (!rateFlo)
		   {
			   cin >> rate;
			   if (0 <= rate && rate <= 1)
					rateFlo = true;
				else
					cout << "Invalid rate. Try again. ";
			}
			accountStack[i] = new SavingsAccount(balance, number, rate);
		}
		
		if (toupper(accountType) == 'C')
		{
		   cout << "What is the minimum balance on the Checking Account? ";
		   while (!minDub)
		   {
			   cin >> minimum_balance;
			   if (0 <= minimum_balance)
					minDub = true;
				else
					cout << "Invalid minimum. Try again. ";
			}
			accountStack[i] = new CheckingAccount(balance, number, minimum_balance);
		}
		
		cout << "Which action would you like to take?" 
		<< endl << "(W - Withdraw, D - Deposit)  ";
		
		while(!act)
		{
			cin >> action;
			
			if(toupper(action) == 'D')
			{
				cout << "How much would you like to deposit? ";
				while(amount <= 0)
				{
					cin >> amount;
					if (amount <= 0)
						cout << "Invalid amount. Try again. ";
				}
				accountStack[i]->deposit(amount);
				act = true;
			}
			
			else if(toupper(action) == 'W')
			{
				cout << "How much would you like to withdraw? ";
				while(amount < 0 || accountStack[i]->getBalance() - amount < 0)
				{
					cin >> amount;
					if (accountStack[i]->getBalance() - amount < 0)
						cout << "Invalid amount. Try again. ";
				
					if(amount < 0)
					{
						amount = NEG;
						cout << "Only positive numbers can be entered! Try again. ";
					}
				}
				accountStack[i]->withdraw(amount);
				act = true;
			}
			else
				cout << "Invalid action. Try again. ";
		}
		prevAcc = true;
	}
   sortArray(accountStack, accountSize);
   
   for (i = 0; i < accountSize; ++i)
   {
		accountStack[i]->display();
	}
	
	cout << "Accounting was completed." << endl;
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
void sortArray(Account** list, int listSize)
// Purpose:
// Precondition:
// Postcondition:
{
   bool done;
   int i, iterations;
   
   iterations = listSize;
   do
   {
      done = true;
      //cout << "Iteration = " << iterations << endl;
      for (i = 1; i <= iterations-1; i++)
      {
        if (list[i-1]->getBalance() > list[i]->getBalance())
        {
         swap (list[i-1] , list[i]);
         //done = false;         
        }//end if
        //cout << "comparing values in location "
        //     << i-1 << " and " << i << endl;
      }// end for
      //pauseScreen();
     --iterations;
   } while (iterations != 0);
   
}
