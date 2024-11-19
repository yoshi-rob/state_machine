#include "state_machine/stateA.hpp"
#include "state_machine/stateB.hpp"
#include "state_machine/state_machine.hpp"

int main() {
    std::shared_ptr<State> stateA = std::make_shared<StateA>();
    std::shared_ptr<State> stateB = std::make_shared<StateB>();

    StateMachine stateMachine;
    stateMachine.register_("stateA", stateA);
    stateMachine.register_("stateB", stateB);

    stateMachine.change("stateA");

    for (int i = 0; i < 10; ++i) {
        std::cout << "---------- " << i << " ----------" << std::endl;
        stateMachine.update();
    }

    return 0;
}
