Assign6: Account.o Assign6.o CheckingAccount.o SavingsAccount.o utility.o
	c++ Account.o Assign6.o SavingsAccount.o CheckingAccount.o utility.o -o Assign6
	
Account.o: Account.cpp Account.h 
	c++ -c Account.cpp
	
CheckingAccount.o: CheckingAccount.cpp CheckingAccount.h
	c++ -c CheckingAccount.cpp

SavingsAccount.o: SavingsAccount.cpp SavingsAccount.h
	c++ -c SavingsAccount.cpp

utility.o: utility.cpp utility.h
	c++ -c utility.cpp
	
Assign6.o: Assign6.cpp
	c++ -c Assign6.cpp
	
