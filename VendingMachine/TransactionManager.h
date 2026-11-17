#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <string>
using namespace std;

struct Transaction {
    int id;
    string productName;
    int price;
    int amountPaid;
    int change;
};

class TransactionManager {
private:
    Transaction transactions[100];
    int transactionCount;

public:
    TransactionManager();

    void addTransaction(string name, int price, int paid, int change);

    void displayTransactions();

    void saveTransactions();

};

#endif