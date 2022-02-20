// Patterns
/* Patterns are a great way to understand loops in any programming language */

#include <iostream>
using namespace std;

// A horizontal line of n stars
void p1(int n) {
    for(int i = 0; i < n; i++)
        cout << '*';
}

// A vertical line of n stars
void p2(int n) {
    for(int i = 0; i < n; i++)
        cout << "*\n";
}

// n by n grid of stars
void p3(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << '*';
        }
        cout << '\n';
    }
}

// n by n grid of numbers from 1 to n
void p4(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << j;
        }
        cout << '\n';
    }
}

// Inverted right-angled triangle with stars
void p5(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= (n-i); j++) {
            cout << ' ';
        }
        for(int k = 1; k <= i; k++) {
            cout << '*';
        }
        cout << '\n';
    }
}

int main() {
    p1(5);
    cout << endl << "\n";
    p2(5);
    cout << endl << "\n";
    p3(5);
    cout << endl << "\n";
    p4(5);
    cout << endl << "\n";
    p5(5);

}