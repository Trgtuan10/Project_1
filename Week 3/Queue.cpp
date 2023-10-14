#include <iostream>
#include <queue>
#include <string>

int main() {
    std::queue<int> myQueue;

    std::string command;
    while (std::cin >> command) {
        if (command == "PUSH") {
            int value;
            std::cin >> value;
            myQueue.push(value);
        } else if (command == "POP") {
            if (!myQueue.empty()) {
                int front = myQueue.front();
                myQueue.pop();
                std::cout << front << std::endl;
            } else {
                std::cout << "NULL" << std::endl;
            }
        }
        else break;
    }

    return 0;
}
