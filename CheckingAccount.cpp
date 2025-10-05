// file name -- CheckingAccount.cpp

#include "CheckingAccount.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

CheckingAccount::CheckingAccount(double balance,
                       string number,
                       double minimum_balance)
    :Account(balance, number)
{
   this -> minimum_balance = minimum_balance;
} // set value constructor

void CheckingAccount::display()
{
	cout << "*************" << endl
	<< "Displaying Account..." << endl
	<< "Account #: " << getAccountNumber() << endl
	<< "Balance: " << getBalance();
	if(getBalance() < minimum_balance)
		cout << " (Warning: Balance is below minimum, payment needed!)";
	cout << endl
	<< "Minimum Balance: " << minimum_balance << endl;
	if(balanceBelow50())
		cout << "Caution: Low Balance" << endl;
	cout << "*************" << endl << endl;
}
