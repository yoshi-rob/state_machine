#ifndef STATE_HPP
#define STATE_HPP

#include <string>

class State {
  public:
    State() = default;
    virtual ~State() = default;

    virtual void onEnter() {}
    virtual void onUpdate() {}
    virtual void onExit() {}

    virtual std::string getNextState() const { return ""; }
};

#endif // STATE_HPP
