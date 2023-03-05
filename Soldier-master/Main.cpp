#include <iostream>
using namespace std;

int main() {
    int A, B;
    cout << "Ingrese el valor de A: ";
    cin >> A;
    cout << "Ingrese el valor de B: ";
    cin >> B;

    int resultado = ((A + B) * (A + B)) / 3;
    cout << "El resultado es: " << resultado << endl;
    return 0;
}