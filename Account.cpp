// file name -- Account.cpp

#include "Account.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <mutex> //Mutexing
using namespace std;

const int MINIMUM = 50;
const int NEG = -1;
const int ADD = 1;

Account::Account(double init_balance, string init_number)
{
   this -> balance = init_balance;
   this -> number = init_number;
   
   if(init_balance < MINIMUM)
		below50Indicator = true;
	else
		below50Indicator = false;
} // set value constructor

double Account::getBalance()
{
	return balance;
}

string Account::getAccountNumber()
{
	return number;
}

bool Account::balanceBelow50()
{
	return below50Indicator;
}

void Account::deposit(double amount)
{
	lock_guard<mutex> lock(balance_mutex);
	
	if(amount >= 0)
		balance = amount + balance;
	else
		cout << "Only positive numbers can be entered!"
		<< endl;
	if(balance >= MINIMUM)
		below50Indicator = false;
}

void Account::withdraw(double amount)
{
	lock_guard<mutex> lock(balance_mutex);
	
	if(amount >= 0)
	{
		if(balance - amount >= 0)
		{
			balance = balance - amount;
			
			if(balance < MINIMUM)
				below50Indicator = true;
		}
		else
			cout << "Imsufficient funds!" << endl;
	}
	else
		cout << "Only positive numbers can be entered!" << endl;
}
