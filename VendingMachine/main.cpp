
#include <iostream>
#include "Automaton.h"
using namespace std;

int main() {

    Automaton machine;

    cout << "Current State: " << machine.getState() << endl;

    machine.transition(SELECT_PRODUCT);

    cout << "Current State: " << machine.getState() << endl;

    machine.transition(INSERT_10);

    cout << "Current State: " << machine.getState() << endl;

    machine.transition(CANCEL);

    cout << "Current State: " << machine.getState() << endl;

    return 0;
}
