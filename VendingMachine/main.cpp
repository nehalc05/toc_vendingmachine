
#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include "Automaton.h"
#include "Product.h"
#include "PaymentManager.h"
#include "TransactionManager.h"
using namespace std;

int getValidInteger() {
    string input;
    int value;
    char extra;

    while (true) {
        getline(cin >> ws, input);

        stringstream ss(input);

        if (ss >> value && !(ss >> extra)) {
            return value;
        }

        cout << "Invalid input! Enter a whole number: ";
    }
}

int main() {

    Automaton machine;
    ProductManager products;
    PaymentManager payment;
    TransactionManager transactions;

    int choice;
    int coin;

    while (true) {

        products.displayProducts();

        cout << "\nSelect product (0 to exit): ";
        choice = getValidInteger();

        if (choice == 0) {
            break;
        }

        Product* selected = products.getProduct(choice);

        if (selected == NULL) {
            cout << "Invalid product selection!" << endl;
            continue;
        }

        if (selected->stock <= 0) {
            cout << "Product is out of stock!" << endl;
            continue;
        }

        machine.transition(SELECT_PRODUCT);

        cout << "\nPrice: Rs." << selected->price << endl;

        bool cancelled = false;

        while (!payment.hasSufficientBalance(selected->price)) {

            cout << "Insert coin (5, 10, 20, 50) or 0 to cancel: ";
            coin = getValidInteger();

            if (coin == 0) {

                machine.transition(CANCEL);

                cout << "Refund returned: Rs."
                     << payment.getBalance() << endl;

                payment.reset();
                machine.reset();

                cancelled = true;
                break;
            }

            if (!payment.insertCoin(coin)) {
                cout << "Invalid coin! Accepted coins: 5, 10, 20, 50." << endl;
                continue;
            }

            if (coin == 5)
                machine.transition(INSERT_5, payment.getBalance(), selected->price);
            else if (coin == 10)
                machine.transition(INSERT_10, payment.getBalance(), selected->price);
            else if (coin == 20)
                machine.transition(INSERT_20, payment.getBalance(), selected->price);
            else if (coin == 50)
                machine.transition(INSERT_50, payment.getBalance(), selected->price);

            cout << "Balance: Rs." << payment.getBalance() << endl;
        }

        if (cancelled) {
            continue;
        }

        machine.transition(CONFIRM);

        int change = payment.calculateChange(selected->price);
        int paid = payment.getBalance();

        cout << "\nProduct: " << selected->name << endl;
        cout << "Change returned: Rs." << change << endl;

        products.reduceStock(choice);

        transactions.addTransaction(
            selected->name,
            selected->price,
            paid,
            change
        );

        machine.transition(SELECT_PRODUCT);

        payment.reset();
        machine.reset();
    }

    transactions.displayTransactions();

    cout << "\nThank you for using the vending machine!" << endl;

    return 0;
}
