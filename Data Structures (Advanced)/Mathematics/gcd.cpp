#include <iostream>

using namespace std;

int naiveGCD(int a, int b) {
    /**
     * Time complexity: O(min(a, b))
     */
    int res = min(a, b);
    while (res > 1) {
        if (a % res == 0 && b % res == 0) {
            return res;
        }
        res--;
    }
    return res;
}

//Basic version of Euclidean algorithm for finding GCD
int iterativeBasicGCD(int a, int b) {
    while(a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

int recursiveBasicGCD(int a, int b) {

    if (a == b) {
        return a;
    }
    if (a > b) {
        return recursiveBasicGCD(a - b, b);
    } else {
        return recursiveBasicGCD(a, b - a);
    }
}


//Optimised version of Euclidean algorithm for finding GCD
int iterativeOptimisedGCD(int a, int b) {
    /**
     * Time complexity: O(log(min(a, b)))
     */
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int recursiveOptimisedGCD(int a, int b) {
    /**
     * Time complexity: O(log(min(a, b)))
     */
    if (b == 0) {
        return a;
    }
    return recursiveOptimisedGCD(b, a % b);
}
