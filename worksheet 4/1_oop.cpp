#include <iostream>

using namespace std;

class BankAccount {
protected:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(string num, string name){
        accountHolder = name;
        accountNumber = num;
        balance = 0.0;
    }
    
    void deposit(double amount){
        balance += amount;
        cout << accountHolder << " has successfully deposited " << amount << endl;
    }
    void withdraw(double amount){
        if(balance >= amount){
            balance -= amount;
            cout << accountHolder << " has successfully withdrawn " << amount << endl;
        }
        else{
            cout << "You have insufficient funds" << endl;
        }
    }
    
    double getBalance() const{
        // cout << accountHolder << "'s current balance is " << balance << endl; 
        return balance;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(string num, string name, double rate, double minBalance)
        : BankAccount(num, name), interestRate(rate), minimumBalance(minBalance) {}

    void deposit(double amount) {
        BankAccount::deposit(amount);
        balance += (amount * interestRate);
    }

    void withdraw(double amount) {
        if (balance >= amount && (balance - amount) >= minimumBalance) {
            BankAccount::withdraw(amount);
        } else {
            std::cout << "Withdrawal not allowed. It will go below the minimum balance requirement." << endl;
        }
    }

    double calculateInterest() const {
        return balance * interestRate;
    }
};

class HighInterestSavingsAccount : public SavingsAccount {
private:
    double additionalInterestRate;

public:
    HighInterestSavingsAccount(string num, string name, double rate, double minBalance, double addRate)
        : SavingsAccount(num, name, rate, minBalance), additionalInterestRate(addRate) {}

    double calculateTotalInterest() const {
        double interest = calculateInterest();
        double additionalInterest = balance * additionalInterestRate;
        return interest + additionalInterest;
    }
};

int main()
{
    SavingsAccount poorDude("12345", "not me", 0.05, 1000);
    HighInterestSavingsAccount richDude("54321", "me", 0.05, 1000, 0.03);
    
    poorDude.deposit(1500);
    richDude.deposit(3000);
    
    poorDude.withdraw(300);
    richDude.withdraw(1000);
    
    double balance1 = poorDude.getBalance();
    cout << "Balance in Savings Account: " << balance1 << endl;
    
    double balance2 = richDude.getBalance();
    cout << "Balance in High Interest Savings Account: " << balance2 << endl;
    
    double interest = richDude.calculateTotalInterest();
    cout << "Total Interest in High Interest Savings: " << interest << endl;
    
    return 0;
}