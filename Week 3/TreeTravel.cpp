#include<bits/stdc++.h>
using namespace std; 

struct Node{
    int id; 
    vector<Node*> child; 
};

Node* root = NULL;

Node* make_root(int u){
    root = new Node;
    root->id = u; 
    return root;
}

Node* make_node(int x){
    Node* p = new Node;
    p->id = x;  
    return p;
}

Node* search_node(Node* p, int x){
    if(p == NULL) return NULL; 
    if(p->id == x) return p;
    for(const auto &cur : p->child){
        Node* u = search_node(cur,x);
        if(u != NULL) return u;
    }
    return NULL;
}

void Insert(int chil, int par){
    Node* pa = search_node(root, par);
    Node* ch = make_node(chil);
    pa->child.push_back(ch);
}

void preOrder(Node* p){
    cout << p->id << " ";
    for(const auto &u : p->child){
        preOrder(u);
    }
}

void inOrder(Node* p){
    if(p->child.size() == 0){
        cout << p->id << " ";
        return;
    }
    inOrder(p->child[0]);
    cout << p->id << " ";
    for(int i = 1; i < p->child.size(); i++){
        inOrder(p->child[i]);
    }
}

void postOrder(Node* p){
    if(p->child.size() == 0){
        cout << p->id << " ";
        return;
    }
    for(const auto &u : p->child){
        postOrder(u);
    }
    cout << p->id << " ";
}

int main(){
    string cmd; 
    int a,b; 
    while(cin >> cmd){
        if(cmd == "MakeRoot"){
            cin >> a; 
            make_root(a);
        }
        else if(cmd == "Insert"){
            cin >> a >> b; 
            Insert(a,b);
        }
        else if(cmd == "InOrder"){
            inOrder(root);
            cout << endl;
        }
        else if(cmd == "PostOrder"){
            postOrder(root);
            cout << endl;
        }
        else if(cmd == "PreOrder"){
            preOrder(root);
            cout << endl;
        }
        else break;
    }
    return 0;
}