#ifndef CLASS_CheckingAccount_
#define CLASS_CheckingAccount_

#include "Account.h"
#include <string>
using namespace std;

class CheckingAccount : public Account
{
   private:
      float minimum_balance;
      
   public:
      CheckingAccount(double, string, double);

      void display();
}; // class CheckingAccounts

#endif
