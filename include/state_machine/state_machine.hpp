#ifndef STATE_MACHINE_HPP
#define STATE_MACHINE_HPP

#include "state.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

class StateMachine {
  public:
    StateMachine() = default;
    ~StateMachine();

    StateMachine(const StateMachine &) = delete;
    StateMachine &operator=(const StateMachine &) = delete;

    void register_(const std::string &name, const std::shared_ptr<State> &state);
    void change(const std::string &name);
    void update();

  private:
    std::unordered_map<std::string, std::shared_ptr<State>> states;
    std::shared_ptr<State> currentState = nullptr;
};

#endif // STATE_MACHINE_HPP
