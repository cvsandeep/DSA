#include <iostream>

usinf namespace std;
class Node {
    public:
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};
class BST {
    public:
    Node* root;
    BST() : root(nullptr) {}
    ~BST() {
        clear();
    }
    void clear() {
        clear(root);
    }
    void clear(Node* node) {
        if(node == nullptr) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }
    void insert(int value) {
        insert(root, value);
    }
    void insert(Node* node, int value) {
        if(node == nullptr) {
            node = new Node(value);
            return;
        }
        if(value < node->value) {
            insert(node->left, value);
        }
        else {
            insert(node->right, value);
        }
    }
    bool contains(int value) {
        return contains(root, value);
    }
    bool contains(Node* node, int value) {
        if(node == nullptr) return false;
        if(node->value == value) return true;
        if(value < node->value) {
            return contains(node->left, value);
        }
        else {
            return contains(node->right, value);
        }
    }
    void remove(int value) {
        remove(root, value);
    }
    void remove(Node* node, int value) {
        if(node == nullptr) return;
        if(value < node->value) {
            remove(node->left, value);
        }
        else {
            remove(node->right, value);
        }
    }
    void BFS() {
        BFS(root);
    }
    void BFS(Node* node) {
        if(node == nullptr) return;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->value << " ";
            if(current->left != nullptr) q.push(current->left);
            if(current->right != nullptr) q.push(current->right);
        }
    }
    void DFS_PreOrder() {
        DFS_PreOrder(root);
    }
    void DFS_PreOrder(Node* node) {
        if(node == nullptr) return;
        cout << node->value << " ";
        DFS_PreOrder(node->left);
        DFS_PreOrder(node->right);
    }
    void DFS_PostOrder() {
        DFS_PostOrder(root);
    }
    void DFS_PostOrder(Node* node) {
        if(node == nullptr) return;
        DFS_PostOrder(node->left);
        DFS_PostOrder(node->right);
        cout << node->value << " ";
    }
    void DFS_InOrder() {
        DFS_InOrder(root);
    }
    void DFS_InOrder(Node* node) {
        if(node == nullptr) return;
        DFS_InOrder(node->left);
        cout << node->value << " ";
        DFS_InOrder(node->right);
    }
};