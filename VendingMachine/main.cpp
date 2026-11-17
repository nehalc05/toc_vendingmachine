#include <iostream>
#include "PaymentManager.h"
using namespace std;

int main() {

    PaymentManager payment;

    payment.insertCoin(20);
    payment.insertCoin(20);

    cout << "Current Balance: Rs." << payment.getBalance() << endl;

    if (payment.hasSufficientBalance(30)) {
        cout << "Payment Successful!" << endl;
        cout << "Change: Rs." << payment.calculateChange(30) << endl;
    }
    else {
        cout << "Insufficient Balance!" << endl;
    }

    payment.reset();

    cout << "Balance after reset: Rs." << payment.getBalance() << endl;

    return 0;
}