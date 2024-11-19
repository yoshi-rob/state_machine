#include "state_machine/state_machine.hpp"

StateMachine::~StateMachine() {
    if (currentState != nullptr)
        currentState->onExit();
}

void StateMachine::register_(const std::string &name, const std::shared_ptr<State> &state) {
    states.emplace(name, state);
}

void StateMachine::change(const std::string &name) {
    if (currentState != nullptr)
        currentState->onExit();

    auto it = states.find(name);
    if (it != states.end()) {
        currentState = it->second;
        if (currentState != nullptr)
            currentState->onEnter();
    }
}

void StateMachine::update() {
    if (currentState != nullptr) {
        currentState->onUpdate();

        // 空文字列でなければ次の状態に遷移
        std::string nextState = currentState->getNextState();
        if (!nextState.empty() && states.find(nextState) != states.end()) {
            change(nextState);
        }
    }
}
