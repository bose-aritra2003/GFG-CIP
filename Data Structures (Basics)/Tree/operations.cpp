#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Node {
    //Considering binary tree only
    int data;
    Node *left, *right;
    Node(int key): data(key), left(nullptr), right(nullptr) {}
};

void recursiveInorderPrint(Node *root) {
    /**
     * Time Complexity: O(n)
     * Auxiliary Space: O(h) where h is the height of the tree
     */
    if(root == nullptr) {
        return;
    }
    recursiveInorderPrint(root->left);
    cout << root->data << ' ';
    recursiveInorderPrint(root->right);
}

void iterativeInorderPrint(Node *root) {
    /**
     * Time Complexity: O(n)
     * Auxiliary Space: O(h) where h is the height of the tree
     */
    if(root == nullptr) {
        return;
    }
    stack<Node *> s;
    Node *curr = root;
    while(s.empty() == false or curr != nullptr) {
        if(curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }
        else {
            curr = s.top();
            s.pop();
            cout << curr->data << ' ';
            curr = curr->right;
        }
    }
}

void recursivePreorderPrint(Node *root) {
    /**
     * Time Complexity: O(n)
     * Auxiliary Space: O(h) where h is the height of the tree
     */
    if(root == nullptr) {
        return;
    }
    cout << root->data << ' ';
    recursivePreorderPrint(root->left);
    recursivePreorderPrint(root->right);
}

void iterativePreorderPrint(Node *root) {
    /**
     * Time Complexity: O(n)
     * Auxiliary Space: O(n/2) = O(n)
     */
    if(root == nullptr) {
        return;
    }
    stack<Node *> s;
    s.push(root);
    while(s.empty() == false) {
        Node *curr = s.top();
        s.pop();
        cout << curr->data << ' ';
        if(curr->right != nullptr) {
            s.push(curr->right);
        }
        if(curr->left != nullptr) {
            s.push(curr->left);
        }
        //Since we want left to be on the top we first push right and then left
    }
}

void spaceOptimisedPreorderPrint(Node *root) {
    /**
     * Time Complexity: O(n)
     * Auxiliary Space: O(h) where h is the height of the tree
     */
    if(root == nullptr) {
        return;
    }
    stack<Node *> s;
    Node *curr = root;
    while(curr != nullptr or s.empty() == false) {
        if(curr != nullptr) {
            cout << curr->data << ' ';
            if(curr->right != nullptr) {
                s.push(curr->right);
            }
            curr = curr->left;
        }
        else {
            curr = s.top();
            s.pop();
        }
    }
}

void postorderPrint(Node *root) {
    if(root == nullptr) {
        return;
    }
    postorderPrint(root->left);
    postorderPrint(root->right);
    cout << root->data << ' ';
}

int heightOfTree(Node *root) {
    /**
     * Time Complexity: O(n)
     * Auxiliary Space: O(h) where h is the height of the tree
     */
    if(root == nullptr) {
        return 0;
    }
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    return max(leftHeight, rightHeight) + 1;
}

void nodesAtGivenDistance(Node *root, int k) {
    /**
     * Time Complexity: O(n)
     * Auxiliary Space: O(h) where h is the height of the tree
     */
    if(root == nullptr) {
        return;
    }
    if(k == 0) {
        cout << root->data << ' ';
        return;
    }
    nodesAtGivenDistance(root->left, k-1);
    nodesAtGivenDistance(root->right, k-1);
}

void levelOrderPrint(Node *root) {
    /**
     * Time Complexity: O(n)
     * Auxiliary Space: O(n) Precisely it is Θ(w) where w is the width of the tree, however in case of
     *                  a perfectly balanced binary tree, w = n/2 thus worst case auxiliary space is O(n)
     */
    if(root == nullptr) {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while(q.empty() == false) {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << ' ';
        if(temp->left != nullptr) {
            q.push(temp->left);
        }
        if(temp->right != nullptr) {
            q.push(temp->right);
        }
    }
}

int recursiveSizeOfTree(Node *root) {
    /**
     * Time Complexity: O(n)
     * Auxiliary Space: O(h) where h is the height of the tree
     */
    if(root == nullptr) {
        return 0;
    }
    return 1 + recursiveSizeOfTree(root->left) + recursiveSizeOfTree(root->right);
}

int maxOfTree(Node *root) {
    /**
     * Time Complexity: O(n)
     * Auxiliary Space: O(h) where h is the height of the tree
     */
    if(root == nullptr) {
        return INT_MIN;
    }
    return max(root->data, max(maxOfTree(root->left), maxOfTree(root->right)));
}


int main() {
    //Level 1
    Node *root = new Node(10);

    //Level 2
    root->left = new Node(20);
    root->right = new Node(30);

    //Level 3
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    root->right->right = new Node(60);

    //Level 4
    root->left->right->left = new Node(70);
    root->left->right->right = new Node(80);

    //Traversal
    cout << "Inorder: ";
    recursiveInorderPrint(root);
    cout << '\n';

    cout << "Preorder: ";
    recursivePreorderPrint(root);
    cout << '\n';

    cout << "Postorder: ";
    postorderPrint(root);
    cout << '\n';

    //Height of the tree
    cout << "Height of the tree: " << heightOfTree(root) << '\n';

    //Nodes at given distance
    cout << "Nodes at given distance: ";
    nodesAtGivenDistance(root, 2);
    cout << '\n';

    //Level Order Print
    cout << "Level Order Print: ";
    levelOrderPrint(root);
    cout << '\n';

    //Size of the tree
    cout << "Size of the tree: " << recursiveSizeOfTree(root) << '\n';

    //Maximum value in the tree
    cout << "Maximum value in the tree: " << maxOfTree(root) << '\n';

    return 0;
}