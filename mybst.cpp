#include <iostream>
using namespace std;

struct bst_node {
    bst_node* left;
    bst_node* right;
    int data;
    bst_node(int data) : left{nullptr}, right{nullptr}, data{data} {} 
};

bst_node*
insert(bst_node* root, int val) {
    if (!root) {
        return new bst_node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

bst_node*
search(bst_node* root, int key) {
    if (!root || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

int main() {
    return 0;
}