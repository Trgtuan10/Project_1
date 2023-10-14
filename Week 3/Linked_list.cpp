#include <bits/stdc++.h>
using namespace std;
int n;

struct node {
    int data;
    node* next;
};
node* head;

// Create a new node with the given value
node* makeNode(int X) {
    node* p = new node;
    p->data = X;
    p->next = NULL;
    return p;
}

// Find a node with a specific value in the list
node* FindNode(node* head, int X) {
    if (head == NULL) return NULL;
    node* cur = head;
    while (cur != NULL && cur->data != X) {
        cur = cur->next;
    }
    if (cur == NULL) {
        return NULL;
    } else {
        return cur;
    }
}

// Insert a new node with the given value at the beginning of the list
node* Insert_ToHead(node* head, int X) {
    if (FindNode(head, X) == NULL) {
        node* new_node = makeNode(X);
        new_node->next = head;
        head = new_node;
    }
    return head;
}

// Insert a new node with the given value at the end of the list
node* Insert_ToLast(node* head, int X) {
    if (FindNode(head, X) == NULL) {
        node* new_node = makeNode(X);
        if (head == NULL) head = new_node;
        else {
            node* last = head;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = new_node;
        }
    }
    return head;
}

// Insert a new node with the value X after a node with the value Y
node* Insert_After(node* head, int X, int Y) {
    if (FindNode(head, X) == NULL && FindNode(head, Y) != NULL) {
        node* cur = FindNode(head, Y);
        node* new_node = makeNode(X);
        new_node->next = cur->next;
        cur->next = new_node;
    }
    return head;
}

// Insert a new node with the value X before a node with the value Y
node* Insert_Before(node* head, int X, int Y) {
    if (FindNode(head, X) == NULL && FindNode(head, Y) != NULL) {
        if (head->data == Y) {
            head = Insert_ToHead(head, X);
        }
        else {
            node* prev = head;
            while (prev->next->data != Y) {
                prev = prev->next;
            }
            node* new_node = makeNode(X);
            new_node->next = prev->next;
            prev->next = new_node;
        }
    }
    return head;
}

// Remove a node with the value X from the list
node* Remove(node* head, int X) {
    if (head == NULL) {
        return NULL;
    }
    if (head->data == X) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
    else {
        node* cur = head;
        while (cur->next != NULL && cur->next->data != X) {
            cur = cur->next;
        }
        if (cur->next != NULL) {
            node* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }
    }
    return head;
}

// Reverse the list
node* Reverse(node* head) {
    node* prev = NULL;
    node* cur = head;
    node* next = NULL;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

// Print the elements of the list
void printList(node* head) {
    node* cur = head;
    for (cur = head; cur != NULL; cur = cur->next) {
        cout << cur->data << " ";
    }
}

int main() {
    cin >> n;
    int a, b;
    node* head = NULL;
    for (int i = 0; i < n; i++) {
        cin >> a;
        head = Insert_ToLast(head, a);
    }
    string S;
    while (cin >> S) {
        if (S == "addlast") {
            cin >> a;
            head = Insert_ToLast(head, a);
        }
        if (S == "addfirst") {
            cin >> a;
            head = Insert_ToHead(head, a);
        }
        if (S == "addafter") {
            cin >> a >> b;
            head = Insert_After(head, a, b);
        }
        if (S == "addbefore") {
            cin >> a >> b;
            head = Insert_Before(head, a, b);
        }
        if (S == "remove") {
            cin >> a;
            head = Remove(head, a);
        }
        if (S == "reverse") {
            head = Reverse(head);
        }
        if (S == "#") {
            printList(head);
            break;
        }
    }
}
