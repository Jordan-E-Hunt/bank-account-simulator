#ifndef CLASS_SavingsAccount_
#define CLASS_SavingsAccount_

#include "Account.h"
#include <string>
using namespace std;

class SavingsAccount : public Account
{
   private:
      float rate;
      
   public:
      SavingsAccount(double, string, float);

      void display();
      void deposit(double);
}; // class SavingsAccounts

#endif
