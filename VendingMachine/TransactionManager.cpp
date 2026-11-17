#include "TransactionManager.h"
#include <iostream>
#include <fstream>
using namespace std;

TransactionManager::TransactionManager() {
    transactionCount = 0;
}

void TransactionManager::addTransaction(string name, int price, int paid, int change) {

    if (transactionCount >= 100) {
        cout << "Transaction history is full!" << endl;
        return;
    }

    transactions[transactionCount].id = transactionCount + 1;
    transactions[transactionCount].productName = name;
    transactions[transactionCount].price = price;
    transactions[transactionCount].amountPaid = paid;
    transactions[transactionCount].change = change;

    transactionCount++;

    saveTransactions();
}

void TransactionManager::displayTransactions() {

    if (transactionCount == 0) {
        cout << "\nNo transactions found." << endl;
        return;
    }

    cout << "\n===== TRANSACTION HISTORY =====\n";

    for (int i = 0; i < transactionCount; i++) {

        cout << "\nTransaction ID: " << transactions[i].id << endl;
        cout << "Product: " << transactions[i].productName << endl;
        cout << "Price: Rs." << transactions[i].price << endl;
        cout << "Paid: Rs." << transactions[i].amountPaid << endl;
        cout << "Change: Rs." << transactions[i].change << endl;
    }
}

void TransactionManager::saveTransactions() {

    ofstream file("transactions.txt");

    for (int i = 0; i < transactionCount; i++) {

        file << transactions[i].id << ","
             << transactions[i].productName << ","
             << transactions[i].price << ","
             << transactions[i].amountPaid << ","
             << transactions[i].change << endl;
    }

    file.close();
}