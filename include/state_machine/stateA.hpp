#ifndef STATE_A_HPP
#define STATE_A_HPP

#include "state.hpp"
#include <iostream>

class StateA : public State {
  public:
    void onEnter() override;
    void onUpdate() override;
    void onExit() override;
    std::string getNextState() const override;
};

#endif // STATE_A_HPP
