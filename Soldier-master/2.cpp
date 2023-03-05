#include <iostream>
using namespace std;

int main() {
    float galones, litros, precio_litro, monto;

    // Solicitar al usuario la cantidad de galones que se surtieron
    cout << "Ingrese la cantidad de galones que se surtieron: ";
    cin >> galones;

    // Convertir la cantidad de galones a litros multiplicándola por 3.785
    litros = galones * 3.785;

    // Calcular el monto a cobrar multiplicando la cantidad de litros por el precio por litro
    precio_litro = 8.20;
    monto = litros * precio_litro;

    // Imprimir el monto a cobrar al cliente
    cout << "El monto a cobrar es: $" << monto << endl;

    return 0;
}
