#ifndef PAYMENTMANAGER_H
#define PAYMENTMANAGER_H

class PaymentManager {
private:
    int balance;

public:
    PaymentManager();

    void insertCoin(int amount);

    int getBalance();

    bool hasSufficientBalance(int price);

    int calculateChange(int price);

    void reset();
};

#endif