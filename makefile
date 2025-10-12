BankSimTest: Account.o BankSimTest.o CheckingAccount.o SavingsAccount.o utility.o
	c++ Account.o BankSimTest.o SavingsAccount.o CheckingAccount.o utility.o -o BankSimTest
	
Account.o: Account.cpp Account.h 
	c++ -c Account.cpp
	
CheckingAccount.o: CheckingAccount.cpp CheckingAccount.h
	c++ -c CheckingAccount.cpp

SavingsAccount.o: SavingsAccount.cpp SavingsAccount.h
	c++ -c SavingsAccount.cpp

utility.o: utility.cpp utility.h
	c++ -c utility.cpp
	
BankSimTest.o: BankSimTest.cpp
	c++ -c BankSimTest.cpp
	
