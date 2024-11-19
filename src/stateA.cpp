#include "state_machine/stateA.hpp"

void StateA::onEnter() { std::cout << "Enter StateA" << std::endl; }

void StateA::onUpdate() {
    // 状態Aの処理を記述
    std::cout << "Update StateA" << std::endl;
}

void StateA::onExit() { std::cout << "Exit StateA" << std::endl; }

std::string StateA::getNextState() const {
    // 条件によって次の状態を決定する例
    bool should_change = 1 /* 条件式 */; // 条件式には、状態に応じた判定を記述
    if (should_change) {
        return "stateB";
    } else {
        return ""; // 状態遷移をしない場合は空文字を返す
    }
}
