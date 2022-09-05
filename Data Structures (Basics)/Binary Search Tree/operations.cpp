#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// Search for a node in a BST
bool recursiveSearchBST(Node *root, int x) {
    /**
     * Time Complexity: O(h)
     * Auxiliary Space: O(h)
     */
    if(root == nullptr) {
        return false;
    }
    else if(root->data == x) {
        return true;
    }
    else if(x > root->data) {
        return recursiveSearchBST(root->right, x);
    }
    else if(x < root->data) {
        return recursiveSearchBST(root->left, x);
    }
}

bool iterativeSearchBST(Node *root, int x) {
    /**
     * Time Complexity: O(h)
     * Auxiliary Space: O(1)
     */
    Node *curr = root;
    while(curr != nullptr) {
        if(curr->data == x) {
            return true;
        }
        else if(x > curr->data) {
            curr = curr->right;
        }
        else if(x < curr->data) {
            curr = curr->left;
        }
    }
    return false;
}

// Insertion in BST
Node* recursiveInsertBST(Node *root, int x) {
    /**
     * Time Complexity: O(h)
     * Auxiliary Space: O(h)
     */
    if(root == nullptr) {
        return new Node(x);
    }
    else if(root->data == x) {
        return root;
    }
    else if(x > root->data) {
        root->right = recursiveInsertBST(root->right, x);
    }
    else if(x < root->data) {
        root->left = recursiveInsertBST(root->left, x);
    }
    return root;
}

Node* iterativeInsertBST(Node *root, int x) {
    /**
     * Time Complexity: O(h)
     * Auxiliary Space: O(1)
     */
    Node *node = new Node(x);
    Node *parent = nullptr, *curr = root;
    while(curr != nullptr) {
        parent = curr;
        if(x == curr->data) {
            return root;
        }
        else if(x > curr->data) {
            curr = curr->right;
        }
        else if(x < curr->data) {
            curr = curr->left;
        }
    }
    if(parent == nullptr) {
        return node;
    }
    else if(x > parent->data) {
        parent->right = node;
    }
    else if(x < parent->data) {
        parent->left = node;
    }
    return root;
}

//Delete a node from BST
Node *getInorderSuccessor(Node *root) {
    /**
     * Note: This function only gives you inorder successor of a node when it's right child is not null
     */
    Node *curr = root;
    while(curr != nullptr && curr->left != nullptr) {
        curr = curr->left;
    }
    return curr;
}
Node* recursiveDelete(Node *root, int x) {
    /**
     * Time Complexity: O(h)
     * Auxiliary Space: O(h)
     */
    if(root == nullptr) {
        return root;
    }
    else if(x > root->data) {
        root->right = recursiveDelete(root->right, x);
    }
    else if(x < root->data) {
        root->left = recursiveDelete(root->left, x);
    }
    else {
        if(root->left == nullptr) {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node *temp = getInorderSuccessor(root->right);
            root->data = temp->data;
            root->right = recursiveDelete(root->right, temp->data);
        }
    }
    return root;
}

// Floor of a key in a BST
Node* floorInBST(Node *root, int key) {
    /**
     * Time Complexity: O(h)
     * Auxiliary Space: O(1)
     */
    Node *ans = nullptr;
    Node *curr = root;
    while(curr != nullptr) {
        if(key == curr->data) {
            ans = curr;
            break;
        }
        else if(key > curr->data) {
            ans = curr;
            curr = curr->right;
        }
        else if(key < curr->data) {
            curr = curr->left;
        }
    }
    return ans;
}

// Ceil of a key in a BST
Node* ceilInBST(Node *root, int key) {
    /**
     * Time Complexity: O(h)
     * Auxiliary Space: O(1)
     */
    Node *ans = nullptr;
    Node *curr = root;
    while(curr != nullptr) {
        if(key == curr->data) {
            ans = curr;
            break;
        }
        else if(key < curr->data) {
            ans = curr;
            curr = curr->left;
        }
        else if(key > curr->data) {
            curr = curr->right;
        }
    }
    return ans;
}

int main() {
    //Sample BST
    Node *root = new Node(50);

    root->left = new Node(30);
    root->right = new Node(70);

    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    root->right->left->left = new Node(55);
    root->right->left->right = new Node(65);

    return 0;
}