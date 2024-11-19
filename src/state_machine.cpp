#include "state_machine/state_machine.hpp"

StateMachine::~StateMachine() {
    if (currentState_ != nullptr)
        currentState_->onExit();
}

void StateMachine::registerState(const std::string &name, const std::shared_ptr<State> &state) {
    states_.emplace(name, state);
}

void StateMachine::change(const std::string &name) {
    if (currentState_ != nullptr)
        currentState_->onExit();

    auto it = states_.find(name);
    if (it != states_.end()) {
        currentState_ = it->second;
        if (currentState_ != nullptr)
            currentState_->onEnter();
    }
}

void StateMachine::update() {
    if (currentState_ != nullptr) {
        currentState_->onUpdate();

        // 空文字列でなければ次の状態に遷移
        std::string next_state = currentState_->getNextState();
        if (!next_state.empty() && states_.find(next_state) != states_.end()) {
            change(next_state);
        }
    }
}
