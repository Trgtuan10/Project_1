#include<bits/stdc++.h>
using namespace std;

struct BinarySearchTree {
    int value;
    BinarySearchTree* left;
    BinarySearchTree* right;
};

BinarySearchTree* root;

BinarySearchTree* createNode(int val) {
    BinarySearchTree* newNode = new BinarySearchTree;
    newNode->value = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BinarySearchTree* insertNode(int val, BinarySearchTree* rootNode) {
    if(rootNode == NULL){
        rootNode = createNode(val);
    }
    else {
        if(val > rootNode->value) {
            rootNode->right = insertNode(val, rootNode->right);
        }
        else if(val < rootNode->value) {
            rootNode->left = insertNode(val, rootNode->left);
        }
    }
    return rootNode;
}

void preOrderTraversal(BinarySearchTree* rootNode) {
    if(rootNode != NULL) {
        cout << rootNode->value << " ";
        preOrderTraversal(rootNode->left);
        preOrderTraversal(rootNode->right);
    }
}

int main() {
    string command;
    int value;
    while(cin >> command) {
        if(command == "insert") {
            cin >> value;
            root = insertNode(value, root);
        }
        else if(command == "#") break;
    }
    preOrderTraversal(root);
}
