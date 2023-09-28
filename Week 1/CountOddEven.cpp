#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int odd_count = 0;
    int even_count = 0;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        if (num % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    cout << odd_count << " " << even_count << endl;

    return 0;
}
