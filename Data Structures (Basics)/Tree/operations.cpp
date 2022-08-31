#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

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

void levelOrderPrint(Node *root) {
    /**
     * When we traverse the tree from left to right on each level starting from the topmost level that is the root
     * Time Complexity: O(n)
     * Auxiliary Space: O(n) Precisely it is Θ(w) where w is the width of the tree, however in case of
     *                  a perfectly balanced binary tree, w = n/2 thus worst case auxiliary space is O(n)
     */
    if(root == nullptr) {
        return;
    }
    queue<Node *> q;
    q.push(root);
    vector<vector<int>> v;
    while(q.empty() == false) {
        int size = q.size();
        vector<int> temp;
        for(int i = 0; i < size; i++) {
            Node *curr = q.front();
            q.pop();
            temp.push_back(curr->data);
            if(curr->left != nullptr) {
                q.push(curr->left);
            }
            if(curr->right != nullptr) {
                q.push(curr->right);
            }
        }
        v.push_back(temp);
    }
    for(auto &i: v) {
        for(auto &j: i) {
            cout << j << ' ';
        }
    }
}

void verticalOrderPrint(Node *root) {
    /**
     * Vertical order traversal is nothing but level order traversal rotated by 90 degrees,
     * that is elements are traversed in vertical order from top to bottom starting from leftmost node
     * when the tree is seen from top
     * Time Complexity: O(n)
     * Auxiliary Space: O(n)
     */
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<Node*, pair<int, int>>> que;
    que.push({root, {0, 0}});
    while(que.empty() == false) {
        auto temp = que.front();
        que.pop();
        Node* node = temp.first;
        int x = temp.second.first, y = temp.second.second;
        nodes[x][y].insert(node->data);
        if(node->left != nullptr) {
            que.push({node->left, {x - 1, y + 1}});
        }
        if(node->right != nullptr) {
            que.push({node->right, {x + 1, y + 1}});
        }
    }
    vector<vector<int>> v;
    for(auto& p: nodes) {
        vector<int> col;
        for(auto &q: p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        v.push_back(col);
    }
    for(auto &col: v) {
        for(auto &ele: col) {
            cout << ele << ' ';
        }
    }
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

Node* lowestCommonAncestor(Node *root, int x, int y) {
    /**
     * Lowest common ancestor of two nodes is the node which is the first (closest) ancestor of both nodes
     * Time Complexity: O(n)
     * Auxiliary Space: O(h) where h is the height of the tree
     */
    if(root == nullptr or root->data == x or root->data == y) {
        return nullptr;
    }
    Node* left = lowestCommonAncestor(root->left, x, y);
    Node* right = lowestCommonAncestor(root->right, x, y);
    if(left != nullptr and right != nullptr) {
        return root;
    }
    else if(left != nullptr) {
        return left;
    }
    else if(right != nullptr) {
        return right;
    }
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

    root->right->left = new Node(50);
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
    cout << "Level Order: ";
    levelOrderPrint(root);
    cout << '\n';

    //Vertical Order Print
    cout << "Vertical Order: ";
    verticalOrderPrint(root);
    cout << '\n';

    //Size of the tree
    cout << "Size of the tree: " << recursiveSizeOfTree(root) << '\n';

    //Maximum value in the tree
    cout << "Maximum value in the tree: " << maxOfTree(root) << '\n';

    return 0;
}