#ifndef CLASS_Account_
#define CLASS_Account_

#include <string>
#include <mutex> //Mutexing
using namespace std;

class Account
{
   protected:
      double balance;            // account balance
      string number;             // account number
      bool below50Indicator;
      mutex balance_mutex;

   public:
      Account(double, string);

      double getBalance();
      string getAccountNumber();
      bool balanceBelow50();

      virtual void deposit(double);
      void withdraw(double);
      virtual void display() = 0;
};   // end of class Account
#endif
