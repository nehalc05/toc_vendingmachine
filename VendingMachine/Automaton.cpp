
#include "Automaton.h"
#include <iostream>
using namespace std;

Automaton::Automaton() {
    currentState = IDLE;
}

State Automaton::getState() {
    return currentState;
}


void Automaton::transition(Input input) {

    switch (currentState) {

        case IDLE:
            if (input == SELECT_PRODUCT) {
                currentState = SELECTED;
                cout << "Product selected." << endl;
            }
            else {
                cout << "Invalid action." << endl;
            }
            break;

        case SELECTED:
            if (input == INSERT_5 || input == INSERT_10 ||
                input == INSERT_20 || input == INSERT_50) {
                currentState = PAYMENT;
                cout << "Payment started." << endl;
            }
            else if (input == CANCEL) {
                currentState = IDLE;
                cout << "Selection cancelled." << endl;
            }
            else {
                cout << "Invalid action." << endl;
            }
            break;

        case PAYMENT:
            if (input == INSERT_5 || input == INSERT_10 ||
                input == INSERT_20 || input == INSERT_50) {
                cout << "Coin accepted." << endl;
            }
            else if (input == CONFIRM) {
                currentState = SUFFICIENT;
                cout << "Payment sufficient." << endl;
            }
            else if (input == CANCEL) {
                currentState = REFUNDING;
                cout << "Refund initiated." << endl;
            }
            else {
                cout << "Invalid action." << endl;
            }
            break;

        case SUFFICIENT:
            if (input == CONFIRM) {
                currentState = DISPENSING;
                cout << "Dispensing product." << endl;
            }
            else if (input == CANCEL) {
                currentState = REFUNDING;
                cout << "Refund initiated." << endl;
            }
            else {
                cout << "Invalid action." << endl;
            }
            break;

        case DISPENSING:
            currentState = COMPLETE;
            cout << "Product dispensed." << endl;
            break;

        case REFUNDING:
            currentState = IDLE;
            cout << "Refund completed." << endl;
            break;

        case COMPLETE:
            currentState = IDLE;
            cout << "Transaction completed." << endl;
            break;
    }
}