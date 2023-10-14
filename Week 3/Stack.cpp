#include <iostream>
#include <stack>
#include <string>

int main() {
    std::stack<int> stack;

    std::string command;
    while (std::cin >> command) {
        if (command == "PUSH") {
            int value;
            std::cin >> value;
            stack.push(value);
        } else if (command == "POP") {
            if (!stack.empty()) {
                int popped = stack.top();
                stack.pop();
                std::cout << popped << std::endl;
            } else {
                std::cout << "NULL" << std::endl;
            }
        }
    }

    return 0;
}
