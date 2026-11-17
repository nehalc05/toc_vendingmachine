
#ifndef AUTOMATON_H
#define AUTOMATON_H

enum State {
    IDLE,
    SELECTED,
    PAYMENT,
    SUFFICIENT,
    DISPENSING,
    REFUNDING,
    COMPLETE
};

enum Input {
    SELECT_PRODUCT,
    INSERT_5,
    INSERT_10,
    INSERT_20,
    INSERT_50,
    CONFIRM,
    CANCEL
};

class Automaton {
private:
    State currentState;

public:
    Automaton();

    State getState();

    void transition(Input input);

};

#endif
