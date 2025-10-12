// Filename:   Assign6.cpp
// Name: Jordan Hunt
// Class: CSCI 220 Programming II
// Section/Lab: Section - Thursday
// Problem Description:


// ==================== header files ===============================
#include <iostream>    // for input/output
#include <cstdlib>
#include <iomanip>    // for output format
#include <thread>
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "utility.h"
using namespace std;
// =============== symbolic constants ==============================
const int DECIMAL = 2;
const int NUM_TRANSACTIONS_PER_THREAD = 1000;
const double TRANSACTION_AMOUNT = 10.00;
const int SIMULATED_THREADS_NUM = 10;
const double INIT_BALANCE = 600.00;
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

void transaction_thread(Account* acc_ptr, int transactions);

// this program contains variable declaration statements
// and assignment statements

int main()
{
   system("clear");
   cout << fixed << showpoint << setprecision(DECIMAL);

   SavingsAccount sharedAccount(INITIAL_BALANCE, "THREAD_TEST", 0.05);

   cout << "--- Multi-threaded Account Simulation ---" << endl
   << "Initial Balance: $" << sharedAccount.getBalance() << endl
   << "Beginnning " << SIMULATED_THREADS_NUM << " threads..." << endl;

   thread* threadArray = new thread[SIMULATED_THREADS_NUM];

   for (int i = 0; i < SIMULATED_THREADS_NUM; ++i) {
	threadArray[i] = thread(transaction_thread, &sharedAccount, NUM_TRANSACTIONS_PER_THREAD);
   }

   for (int i = 0; i < SIMULATED_THREADS_NUM; ++i) {
	if (threadArray[i].joinable())
		thread[i].join();
   }

   delete[] threadArray;

   cout << "All threads completed and memory cleaned." << endl
   << "-----------------------------------" << endl
   << "Final Balance: $" << sharedAccount.getBalance() << endl
   << "-----------------------------------" << endl;

   return 0;
}// end main
void transaction_thread(Account* acc_ptr, int transactions)
// Purpose: Runs transactions and withdrawls through threads
// Precondition: Address of Account Object and number of intended deposits and withdrawls
// Postcondition: Performs number of transactions on the account
{
   Account& acc = *act_ptr;
   for (int i = 0; i < transactions; ++i) {
	acc.deposit(TRANSACTION_AMOUNT);
	acc.withdraw(TRANSACTION_AMOUNT / 2.0);
   }
}// end
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
