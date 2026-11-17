#include <iostream>
#include "Automaton.h"
#include "Product.h"
#include "PaymentManager.h"
using namespace std;

int main() {

    Automaton machine;
    ProductManager products;
    PaymentManager payment;

    int choice;
    int coin;

    while (true) {

        products.displayProducts();

        cout << "\nSelect product (0 to exit): ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        Product* selected = products.getProduct(choice);

        if (selected == NULL || selected->stock == 0) {
            cout << "Invalid product or out of stock!" << endl;
            continue;
        }

        machine.transition(SELECT_PRODUCT);

        cout << "\nPrice: Rs." << selected->price << endl;

        while (!payment.hasSufficientBalance(selected->price)) {

            cout << "Insert coin (5, 10, 20, 50): ";
            cin >> coin;

            int previousBalance = payment.getBalance();
            payment.insertCoin(coin);

            if (payment.getBalance() == previousBalance) {
                cout << "Invalid coin!" << endl;
                continue;
            }

            if (coin == 5) machine.transition(INSERT_5);
            else if (coin == 10) machine.transition(INSERT_10);
            else if (coin == 20) machine.transition(INSERT_20);
            else if (coin == 50) machine.transition(INSERT_50);

            cout << "Balance: Rs." << payment.getBalance() << endl;
        }

        machine.transition(CONFIRM);

        int change = payment.calculateChange(selected->price);

        products.reduceStock(choice);

        machine.transition(CONFIRM);

        cout << "\nProduct: " << selected->name << endl;
        cout << "Change returned: Rs." << change << endl;

        payment.reset();

        
    }

    cout << "\nThank you for using the vending machine!" << endl;

    return 0;
}