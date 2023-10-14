#include<bits/stdc++.h>
using namespace std;

struct Node {
    string name;
    vector<Node*> children;
};

set<Node*> name_exist; 

Node* make_Node(string x) {
    Node* new_node = new Node;
    new_node->name = x;
    name_exist.insert(new_node);
    return new_node;
}

Node* search_Node(string x) {
    for (Node* node : name_exist) {
        if (node->name == x) return node;
    }
    return NULL;
}

void insert(string par, string chil) {
    Node* parent = search_Node(par);
    if (parent == NULL) {
        parent = make_Node(par);
    }

    Node* child = search_Node(chil);
    if (child == NULL) {
        child = make_Node(chil);
    }

    parent->children.push_back(child);
}

int count_generation(Node* node) {
    if (node->children.empty()) {
        return 0; // Base case: no children
    }

    int max_gen = 0;
    for (Node* child : node->children) {
        max_gen = max(max_gen, 1 + count_generation(child));
    }
    return max_gen;
}

int count_descendant(Node* node) {
    int descendants = 0;
    for (Node* child : node->children) {
        descendants += 1 + count_descendant(child);
    }
    return descendants;
}

int main() {
    string a, b;
    while (1) {
        cin >> a;
        if (a == "***") break;
        cin >> b;
        insert(b, a);
    }
    string cmd;
    while (cin >> cmd) {
        if (cmd == "descendants") {
            cin >> a;
            Node* node = search_Node(a);
            if (node != NULL) {
                cout << count_descendant(node) << endl;
            } else {
                cout << 0 << endl;
            }
        }
        else if (cmd == "generation") {
            cin >> a;
            Node* node = search_Node(a);
            if (node != NULL) {
                cout << count_generation(node) << endl;
            } else {
                cout << 0 << endl;
            }
        }
        else break;
    }
    return 0;
}
