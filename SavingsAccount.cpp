// file name -- SavingsAccount.cpp

const int MINIMUM = 50;

#include "SavingsAccount.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

SavingsAccount::SavingsAccount(double balance,
                       string number,
                       float rate)
    :Account(balance, number)
{
   this -> rate = rate;
} // set value constructor

void SavingsAccount::display()
{
	cout << "*************" << endl
	<< "Displaying Account..." << endl
	<< "Account #: " << getAccountNumber() << endl
	<< "Balance: " << getBalance() << endl
	<< "Interest Rate: " << rate * 100 <<  "%" << endl;
	if(balanceBelow50())
		cout << "Caution: Low Balance" << endl;
	cout << "*************" << endl << endl;
}

void SavingsAccount::deposit(double amount)
{
	lock_guard<mutex> lock(balance_mutex);
	
	if(amount >= 0)
	{
		amount += (getBalance() * rate);
		balance += amount;
	}
	else
		throw runtime_error("Only positive numbers can be entered!");
	if(balance >= MINIMUM)
		below50Indicator = false;
}
