#ifndef STATE_B_HPP
#define STATE_B_HPP

#include "state.hpp"
#include <iostream>

class StateB : public State {
  public:
    void onEnter() override;
    void onUpdate() override;
    void onExit() override;
    std::string getNextState() const override;
};

#endif // STATE_B_HPP