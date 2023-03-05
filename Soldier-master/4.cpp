#include <iostream>
using namespace std;

int main() {
    float costo_basico, precio_total, impuesto;

    // Solicitar al usuario el costo b�sico del art�culo
    cout << "Ingrese el costo b�sico del art�culo: $";
    cin >> costo_basico;

    // Calcular el impuesto seg�n la regla de M�xico
    if (costo_basico <= 20) {
        impuesto = 0;
    }
    else if (costo_basico <= 40) {
        impuesto = costo_basico * 0.3;
    }
    else if (costo_basico <= 500) {
        impuesto = 20 * 0.3 + (costo_basico - 20) * 0.4;
    }
    else {
        impuesto = 20 * 0.3 + 480 * 0.4 + (costo_basico - 500) * 0.5;
    }

    // Calcular el precio total sumando el costo b�sico y el impuesto
    precio_total = costo_basico + impuesto;

    // Imprimir el precio total del art�culo
    cout << "El precio total del art�culo es: $" << precio_total << endl;

    return 0;
}

