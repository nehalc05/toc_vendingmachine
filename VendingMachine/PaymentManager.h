
#ifndef PAYMENTMANAGER_H
#define PAYMENTMANAGER_H

class PaymentManager {
private:
    int balance;

public:
    PaymentManager();

    bool insertCoin(int amount);

    int getBalance();

    bool hasSufficientBalance(int price);

    int calculateChange(int price);

    void reset();
};

#endif
