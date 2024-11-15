#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>

enum TransactionType { DEPOSIT, WITHDRAWAL, BALANCE_ENQUIRY };

class Transaction {
protected:
    TransactionType m_Type;
    std::string m_DateTime;
public:
    Transaction(TransactionType type, std::string dateTime) : m_Type(type), m_DateTime(dateTime) {}
    virtual ~Transaction() {}
    TransactionType getType() const { return m_Type; }
    std::string getDateTime() const { return m_DateTime; }
    virtual std::string toString() const {
        return "Transaction: Type = " + std::to_string(m_Type) + ", DateTime = " + m_DateTime;
    }
    virtual double computeCost() const = 0;
};

class Deposit : public Transaction {
private:
    double m_Fee;
public:
    Deposit(std::string dateTime, double fee) : Transaction(DEPOSIT, dateTime), m_Fee(fee) {}
    virtual ~Deposit() {}
    virtual std::string toString() const {
        return Transaction::toString() + ", Fee = " + std::to_string(m_Fee);
    }
    virtual double computeCost() const { return m_Fee; }
};

class Withdrawal : public Transaction {
private:
    double m_Amount;
    double m_Percentage;
public:
    Withdrawal(std::string dateTime, double amount, double percentage) : Transaction(WITHDRAWAL, dateTime), m_Amount(amount), m_Percentage(percentage) {}
    virtual ~Withdrawal() {}
    virtual std::string toString() const {
        return Transaction::toString() + ", Amount = " + std::to_string(m_Amount) + ", Percentage = " + std::to_string(m_Percentage);
    }
    virtual double computeCost() const { return m_Amount * (m_Percentage / 100.0); }
};

class BalanceEnquiry : public Transaction {
public:
    BalanceEnquiry(std::string dateTime) : Transaction(BALANCE_ENQUIRY, dateTime) {}
    virtual ~BalanceEnquiry() {}
    virtual double computeCost() const { return 0.0; }
};

class SavingsAccount {
private:
    std::string m_CustomerName;
    int m_AccountNo;
    std::vector<Transaction*> m_TransactionList;

public:
    SavingsAccount(std::string customerName, int accountNo) : m_CustomerName(customerName), m_AccountNo(accountNo) {}
    ~SavingsAccount() {
        for (Transaction* t : m_TransactionList)
            delete t;
        m_TransactionList.clear();
    }

    void addTransaction(Transaction* transaction) {
        m_TransactionList.push_back(transaction);
    }
    double totalTransactionCost() const {
        double totalCost = 0.0;
        for (const Transaction* t : m_TransactionList)
            totalCost += t->computeCost();
        return totalCost;
    }
    TransactionType frequentTransactionType() const {
        int count[3] = { 0 };
        for (const Transaction* t : m_TransactionList)
            count[t->getType()]++;
        if (count[DEPOSIT] >= count[WITHDRAWAL] && count[DEPOSIT] >= count[BALANCE_ENQUIRY])
            return DEPOSIT;
        else if (count[WITHDRAWAL] >= count[BALANCE_ENQUIRY])
            return WITHDRAWAL;
        else
            return BALANCE_ENQUIRY;
    }

    std::vector<Transaction*> transactionsOnADate(std::string date) const {
        std::vector<Transaction*> result;
        for (Transaction* t : m_TransactionList)
            if (t->getDateTime().substr(0, date.size()) == date)
                result.push_back(t);
        return result;
    }

    std::string getCustomerName() const {
        return m_CustomerName;
    }

    std::string toString() const {
        std::string result = "SavingsAccount: CustomerName = " + m_CustomerName + ", AccountNo = " + std::to_string(m_AccountNo) + "\n";
        result += "Transactions:\n";
        for (const Transaction* t : m_TransactionList)
            result += t->toString() + "\n";
        return result;
    }
};


int main(){
    SavingsAccount account("John Doe", 12345);
    account.addTransaction(new Deposit("2023-08-31 09:47:00", 1.0));
    account.addTransaction(new Withdrawal("2023-08-31 10:47:00", 100.0, 1.0));
    account.addTransaction(new BalanceEnquiry("2023-08-31 11:47:00"));
    account.addTransaction(new Deposit("2023-09-01 09:47:00", 1.0));
    account.addTransaction(new Withdrawal("2023-09-01 10:47:00", 200.0, 1.0));
    account.addTransaction(new BalanceEnquiry("2023-09-01 11:47:00"));
    std::vector<SavingsAccount> accounts;
    accounts.push_back(account);
    std::cout << account.toString() << std::endl;
    std::cout << "Total transaction cost: " << account.totalTransactionCost() << std::endl;
    std::cout << "Frequent transaction type: " << account.frequentTransactionType() << std::endl;
    std::vector<Transaction*> transactions = account.transactionsOnADate("2023-08-31");
    std::cout << "Transactions on 2023-08-31:" << std::endl;

    int mainChoice;
    do {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. View Accounts\n";
        std::cout << "2. Exit\n";
        std::cout << "Enter your choice: ";

        // user input
        while (!(std::cin >> mainChoice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
        }

        switch (mainChoice) {
        case 1: {
            std::cout << "\nAccount List:\n";
            for (int i = 0; i < accounts.size(); ++i) {
                std::cout << i + 1 << ". " << accounts[i].getCustomerName() << "\n";
            }
            std::cout << "0. Exit\n";
            int accountChoice;
            std::cout << "Enter account number (0 to exit): ";
            std::cin >> accountChoice;

            if (accountChoice >= 1 && accountChoice <= accounts.size()) {
                std::cout << "Selected account: " << accounts[accountChoice - 1].toString() << "\n";

                int accountSubMenuChoice;
                do {
                    std::cout << "\nAccount Menu:\n";
                    std::cout << "1. View Transactions\n";
                    std::cout << "2. Total Transaction Cost\n";
                    std::cout << "3. Frequent Transaction Type\n";
                    std::cout << "4. Transactions on a Date\n";
                    std::cout << "5. Deposit\n";
                    std::cout << "6. Withdraw\n";
                    std::cout << "0. Back\n";
                    std::cout << "Enter your choice: ";
                    std::cin >> accountSubMenuChoice;

                    switch (accountSubMenuChoice) {
                    case 1:
                        std::cout << "\n" << accounts[accountChoice - 1].toString() << std::endl;
                        break;
                    case 2:
                        std::cout << "Total transaction cost: " << accounts[accountChoice - 1].totalTransactionCost() << std::endl;
                        break;
                    case 3:
                        std::cout << "Frequent transaction type: " << accounts[accountChoice - 1].frequentTransactionType() << std::endl;
                        break;
                    case 4: {
                        std::string date;
                        std::cout << "Enter date (yyyy-mm-dd): ";
                        std::cin >> date;
                        std::vector<Transaction*> transactions = accounts[accountChoice - 1].transactionsOnADate(date);
                        std::cout << "Transactions on " << date << ":\n";
                        for (Transaction* t : transactions)
                            std::cout << t->toString() << std::endl;
                        break;
                    }
                    case 5: {
                        double amount;
                        std::cout << "Enter deposit amount: ";
                        std::cin >> amount;
                        accounts[accountChoice - 1].addTransaction(new Deposit("2023-09-02 12:00:00", amount));
                        std::cout << "Deposit of " << amount << " successful.\n";
                        break;
                    }
                    case 6: {
                        double amount;
                        std::cout << "Enter withdrawal amount: ";
                        std::cin >> amount;
                        accounts[accountChoice - 1].addTransaction(new Withdrawal("2023-09-02 12:00:00", amount, 1.0));
                        std::cout << "Withdrawal of " << amount << " successful.\n";
                        break;
                    }
                    case 0:
                        std::cout << "Going back to the Account List.\n";
                        break;
                    default:
                        std::cout << "Invalid choice!\n";
                    }
                    } while (accountSubMenuChoice != 0);
            } else if (accountChoice == 0) {
                std::cout << "Exiting the program.\n";
            } else {
                std::cout << "Invalid choice!\n";
            }
            break;
        }
        case 2:
            std::cout << "Exiting the program.\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
            break;
        }

    } while (mainChoice != 2);

    return 0;
}
