// Complex Number addition

#include <iostream>
using namespace std;

struct Complex {
    int real, imag;
    void printComplex() {
        cout << real << " + " << imag << 'i';
    }
    Complex addComplex(const Complex &z) {
        real += z.real;
        imag += z.imag;
        return Complex{real, imag};
    }
};

int main(){
    Complex z1{1, 2}, z2{3, 4}, z{};
    z = z1.addComplex(z2);
    z.printComplex();
    return 0;
}