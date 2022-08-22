#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printSinglyList(Node *head) {
    /**
     * Traverse through a singly linked list and prints its elements
     * Time Complexity: O(n)
     * Auxiliary Space: O(1)
     */

    Node *curr = head;
    /**
    Instead of using a separate curr variable we can also use the same head variable because
    in C++ when a pointer variable is passed to a function, the variable passed to the function
    is different from the variable passed in the main function during calling of the function.
    **/
    while(curr != nullptr) {
        cout << curr -> data << ' ';
        curr = curr -> next;
    }
}

void recursivePrintSinglyList(Node *head) {
    /**
     * Traverse through a singly linked list and prints its elements recursively
     * Time Complexity: O(n)
     * Auxiliary Space: O(n)
     */
    if(head != nullptr) {
        cout << head -> data << ' ';
        recursivePrintSinglyList(head -> next);
    }
}

int searchSinglyList(Node *head, int x) {
    /**
     * Search for an element in a singly linked list
     * Time Complexity: O(n)
     * Auxiliary Space: O(1)
     */
    int pos = 1;
    while(head != nullptr) {
        if(head -> data == x)
            return pos;
        head = head -> next;
        pos++;
    }
    return -1;
}

int recursiveSearchSinglyList(Node *head, int x) {
    /**
     * Search for an element in a singly linked list recursively and return its position
     * Time Complexity: O(n)
     * Auxiliary Space: O(n) - worst case recursive stack space
     */
    if(head == nullptr)
        return -1;
    if(head->data == x)
        return 1;
    else {
        int res = recursiveSearchSinglyList(head->next, x);
        return (res == -1) ? res : (res + 1);
    }
}

int lengthOfSinglyList(Node *head) {
    /**
     * Return the length of a singly linked list
     * Time Complexity: O(n)
     * Auxiliary Space: O(1)
     */
    int len = 0;
    while(head != nullptr) {
        len++;
        head = head -> next;
    }
    return len;
}

Node* insertAtBeginning(Node *head, int x) {
    /**
     * Insert an element at the beginning of a singly linked list
     * Time Complexity: O(1)
     * Auxiliary Space: O(1)
     */
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

Node* insertAtEnd(Node *head, int x) {
    /**
     * Insert an element at the end of a singly linked list
     * Time Complexity: O(n)
     * Auxiliary Space: O(1)
     */
    Node *temp = new Node(x);
    if(head == nullptr) {
        return temp;
    }
    Node *curr = head;
    while(curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

Node* deleteFirstNode(Node *head) {
    /**
     * Delete the first node of a singly linked list
     * Time Complexity: O(1)
     * Auxiliary Space: O(1)
     */
    if(head == nullptr)
        return head;
    Node *temp = head->next;
    delete(head);
    return temp;
}

Node* deleteLastNode(Node *head) {
    /**
     * Delete the last node of a singly linked list
     * Time Complexity: O(n)
     * Auxiliary Space: O(1)
     */
    if(head == nullptr)
        return head;
    if(head->next == nullptr) {
        delete(head);
        return nullptr;
    }
    Node *curr = head;
    while(curr->next->next != nullptr) {
        curr = curr->next;
    }
    delete(curr->next);
    curr->next = nullptr;
    return head;
}

Node* insertAtPosition(Node *head, int x, int pos) {
    /**
     * Insert an element at a given position in a singly linked list
     * Time Complexity: O(n) - worst case
     * Auxiliary Space: O(1)
     */
     Node *temp = new Node(x);
    if(pos == 1) {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    while(pos > 2 and curr != nullptr) {
        curr = curr->next;
        pos--;
    }
    if(curr == nullptr)
        return head;
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

Node* deleteFromPosition(Node *head, int pos) {
    /**
     * Delete an element at a given position in a singly linked list
     * Time Complexity: O(n) - worst case
     * Auxiliary Space: O(1)
     */
    if(pos == 1) {
        return deleteFirstNode(head);
    }
    Node *curr = head;
    while(pos > 2 and curr != nullptr) {
        curr = curr->next;
        pos--;
    }
    if(curr == nullptr or (curr->next == nullptr and pos > 1))
        return head;
    Node *temp = curr->next;
    curr->next = temp->next;
    delete(temp);
    return head;
}

Node* sortedInsert(Node *head, int x) {
    /**
     * Insert an element in a sorted singly linked list
     * Time Complexity: O(n) - worst case
     * Auxiliary Space: O(1)
     */
    Node *temp = new Node(x);
    if(head == nullptr) {
        return temp;
    }
    if(head->data > x) {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    while(curr->next != nullptr and curr->next->data < x) {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

int middleElement(Node *head) {
    /**
     * Find the middle element of a singly linked list
     * Working: We use two pointers, one moves one step at a time and the other moves two steps at a time.
     *          So when the fast pointer reaches the end, the slow pointer will be at the middle of the list.
     * Time Complexity: O(n) - worst case
     * Auxiliary Space: O(1)
     */
    if(head == nullptr)
        return -1; //Considering linked list to store only positive values
    Node *slow = head;
    Node *fast = head;
    while(fast != nullptr and fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int nthElementFromEnd(Node *head, int n) {
    /**
     * Find the nth element from the end of a singly linked list
     * Working: We first move our first pointer to the nth position from beginning.
     *          Then we move both our second and first pointers at the same speed.
     *          When the first pointer reaches the end, the second pointer will be at the nth position from end.
     * Time Complexity: O(n) - worst case
     * Auxiliary Space: O(1)
     */
    if(head == nullptr)
        return -1; //Considering linked list to store only positive values
    Node *first = head;
    while(n > 0) {
        if(first == nullptr)
            return -1;
        first = first->next;
        n--;
    }
    Node *second = head;
    while(first != nullptr) {
        second = second->next;
        first = first->next;
    }
    return second->data;
}

Node* reverseSinglyList(Node *head) {
    /**
     * Reverse a singly linked list
     * Time Complexity: O(n)
     * Auxiliary Space: O(1)
     */
    Node *prev = nullptr;
    Node *curr = head;
    while(curr != nullptr) {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* recursiveReverseSinglyListMethod1(Node *head) {
    /**
     * Reverse a singly linked list recursively
     * Time Complexity: O(n)
     * Auxiliary Space: O(n)
     */
    if(head == nullptr or head->next == nullptr)
        return head;
    Node *temp = recursiveReverseSinglyListMethod1(head->next);
    head->next->next = head;
    head->next = nullptr;
    return temp;
}

Node* recursiveReverseSinglyListMethod2(Node *curr, Node *prev) {
    /**
     * Reverse a singly linked list recursively
     * Time Complexity: O(n)
     * Auxiliary Space: O(n)
     */
    if(curr == nullptr)
        return prev;
    Node *next = curr->next;
    curr->next = prev;
    return recursiveReverseSinglyListMethod2(next, curr);
}

void removeDuplicatesFromSortedSinglyList(Node *head) {
    /**
     * Remove duplicates from a singly linked list
     * This function is void type because it will never modify the head
     * because during deletion we delete the next node not the curr node
     * Time Complexity: O(n)
     * Auxiliary Space: O(1)
     */
    if(head == nullptr)
        return;
    Node *curr = head;
    while(curr->next != nullptr) {
        if(curr->data == curr->next->data) {
            Node *temp = curr->next;
            curr->next = temp->next;
            delete(temp);
        }
        else
            curr = curr->next;
    }
}

int main() {
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(20);
    head->next->next->next = new Node(30);
    head->next->next->next->next = new Node(30);
    head->next->next->next->next->next = new Node(30);
    removeDuplicatesFromSortedSinglyList(head);
    printSinglyList(head);
    return 0;
}