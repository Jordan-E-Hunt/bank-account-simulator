# Bank Account Simulator

## 📝 Overview

This project implements a C++ command-line simulation of a bank account system, primarily focusing on robust transaction processing and concurrency control for shared resources. The core of the project involves two distinct 
implementations: a single-threaded version demonstrating controlled error handling via exceptions, and a multi-threaded version demonstrating thread safety using mutexes.

The multi-threaded project (bank/multi-thread) is structured around the Account and SavingsAccount classes, with the simulation logic contained in BankSimTest.cpp.

The single-threaded project allows the user to handle the Account, SavingsAccount and CheckingAccount classes, with the handling logic implemented in Assign6.cpp.

## ✨ Key Features Demonstrated
**1. Robust Exception Handling (Single-Threaded Context)**

The core transaction methods (deposit, withdraw) have been modified to enforce business logic using C++ exceptions. This ensures that the program does not enter an invalid state due to improper user input or insufficient funds.

		std::invalid_argument: Thrown for non-positive transaction amounts.

		std::runtime_error: Thrown for insufficient funds during a withdrawal.

**2. Concurrency and Thread Safety (Multi-Threaded Context)**

The multi-threaded version simulates 10,000 concurrent transactions (10 threads, 1,000 transactions each) on a single, shared SavingsAccount object.

**Shared Resource Protection:** std::mutex is implemented within the Account class methods.

**Mutual Exclusion:** std::lock_guard is used inside every critical section (deposit, withdraw) to guarantee that only one thread can modify the shared account balance at any given time, thereby preventing race conditions.

**Final Validation:** The simulation validates the final account balance against the expected theoretical balance to confirm that the concurrency control mechanism worked successfully.

## ⚙️ Compilation and Execution

**Prerequisites:** C++ Compiler (GCC, g++, or similar), C++11 standard or newer (required for std::thread and std::mutex)

**Build Command:**

		make

**Multi-Threaded Execution:**

		./BankSim

**Single-Threaded Execution:**

		./Assign6

## 📁 Project Structure

| File | Description |
| :--- | :---|
| BankSimTest.cpp | Contains the main simulation logic, including thread creation and final result validation. Also includes try/catch blocks for exception demonstration. |
| Account.h | Base class for all accounts. Implements the core logic for deposits, withdrawals, and crucially, the std::mutex for thread safety. |
| SavingsAccount.h | Inherits from Account. Extends the base functionality (e.g., might include interest or fee logic, but for this project, primarily demonstrates inheritance). |
| .gitignore | Ensures that compiled files (*.o, a.out, BankSim) are ignored by Git. |

## 👨‍💻 Configuration 
The simulation parameters can be adjusted directly within the BankSimTest.cpp file:

| Constant | Default Value | Purpose |
| :--- | :--- | :--- |
| NUM_THREADS | 10 | The number of concurrent threads to launch. |
| TRANSACTIONS_PER_THREAD | 1000 | The number of transactions each thread executes. |
| INITIAL_BALANCE | 500.0 | The starting balance of the shared account. |
| DEPOSIT_AMOUNT | 1.0 | The amount used for each deposit. |
| WITHDRAW_AMOUNT | 1.0 | The amount used for each withdrawal. |
