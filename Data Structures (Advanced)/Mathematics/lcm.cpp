#include <iostream>

using namespace std;

int naiveLCM(int a, int b) {
    /**
     * Time complexity: O(a*b - max(a,b))
     */
    int res = max(a, b);
    while(true) {
        if(res % a == 0 && res % b == 0) {
            break;
        }
        res++;
    }
    return res;
}

//Efficient way to find LCM
int euclideanGCD(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int optimisedLCM(int a, int b) {
    /**
     * Time complexity: O(log(min(a,b)))
     */
    return (a * b) / euclideanGCD(a, b);
}