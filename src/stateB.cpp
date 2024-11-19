#include "state_machine/stateB.hpp"

void StateB::onEnter() { std::cout << "Enter StateB" << std::endl; }

void StateB::onUpdate() {
    // 状態Bの処理を記述
    std::cout << "Update StateB" << std::endl;
}

void StateB::onExit() { std::cout << "Exit StateB" << std::endl; }

std::string StateB::getNextState() const {
    // 条件によって次の状態を決定する例
    bool should_change = 1 /* 条件式 */; // 条件式には、状態に応じた判定を記述
    if (should_change) {
        return "stateA";
    } else {
        return ""; // 状態遷移をしない場合は空文字を返す
    }
}
