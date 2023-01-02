#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

//Huffman Coding
class HuffmanCoding {
private:
    //Structures
    struct Node {
        char ch;
        int freq;
        Node *left, *right;
        Node(char ch, int freq) : ch(ch), freq(freq), left(nullptr), right(nullptr) {}
    };
    struct cmp {
        bool operator()(Node *a, Node *b) {
            return a->freq > b->freq;
        }
    };

    //Variables
    Node *root;
    unordered_map<char, string> codes;

    //Helper Functions
    void buildCodes(Node *curr, const string& code) {
        if (curr == nullptr)
            return;
        if (curr->ch != '$') {
            codes[curr->ch] = code;
            return;
        }
        buildCodes(curr->left, code + "0");
        buildCodes(curr->right, code + "1");
    }

public:
    void encode(vector<char> &ch, vector<int> &freq) {
        int n = ch.size();
        priority_queue<Node *, vector<Node *>, cmp> pq;
        for (int i = 0; i < n; i++) {
            pq.push(new Node(ch[i], freq[i]));
        }
        while (pq.size() > 1) {
            Node *left = pq.top();
            pq.pop();
            Node *right = pq.top();
            pq.pop();
            Node *top = new Node('$', left->freq + right->freq);
            top->left = left;
            top->right = right;
            pq.push(top);
        }
        root = pq.top();
        buildCodes(root, "");
    }

    void printCodes() {
        for (auto &code : codes) {
            cout << code.first << " " << code.second << endl;
        }
    }
};