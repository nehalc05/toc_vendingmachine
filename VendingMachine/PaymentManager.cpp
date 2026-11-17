#include "PaymentManager.h"

PaymentManager::PaymentManager() {
    balance = 0;
}

void PaymentManager::insertCoin(int amount) {
    if (amount == 5 || amount == 10 || amount == 20 || amount == 50) {
        balance += amount;
    }
}

int PaymentManager::getBalance() {
    return balance;
}

bool PaymentManager::hasSufficientBalance(int price) {
    return balance >= price;
}

int PaymentManager::calculateChange(int price) {
    if (balance >= price) {
        return balance - price;
    }

    return 0;
}

void PaymentManager::reset() {
    balance = 0;
}