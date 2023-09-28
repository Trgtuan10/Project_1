#include <iostream>

int main() {
    int n;

    std::cin >> n;

        for (int i = 1; i <= n; ++i) {
            int square = i * i;
            std::cout << i <<" " << square << std::endl;
        }

    return 0;
}
