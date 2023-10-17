#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main(){
    unordered_set<string> key_set;

    // Read the first block of information
    string key;
    while (cin >> key) {
        if (key == "*") {
            break;
        }
        key_set.insert(key);
    }

    // Process the second block of actions
    string cmd; 
    int result;
    while (cin >> cmd) {
        string k;
        if (cmd == "find") {
            cin >> k;
            cout << (key_set.find(k) != key_set.end() ? "1" : "0") << endl;
        }    
        else if(cmd == "insert"){
            cin >> k;
            if(key_set.find(k) != key_set.end()) cout << "0" << endl;
            else{
                key_set.insert(k);
                cout << "1" << endl;
            }
        }

        else break;

    }

    return 0;
}
