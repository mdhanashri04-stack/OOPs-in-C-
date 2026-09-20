#include <iostream>

class Account {
private:
    double balance;

    friend class Auditor;

public:
    explicit Account(double initialBalance) : balance(initialBalance) {}

    // Added feature: deposit money into the account
    void deposit(double amount) {
        balance = balance + amount;
    }
};

class Auditor {
public:
    void inspect(const Account& account) const {
        std::cout << "Account Balance: " << account.balance << '\n';
    }
};

int main() {
    Account account(5000.0);
    Auditor auditor;

    // Deposit additional money
    account.deposit(1000.0);

    auditor.inspect(account);

    return 0;
}