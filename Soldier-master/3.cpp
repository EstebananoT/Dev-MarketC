#include <iostream>
using namespace std;

int main() {
    float monto_compra, monto_descuento, monto_final;

    // Solicitar al usuario el monto de la compra
    cout << "Ingrese el monto de la compra: $";
    cin >> monto_compra;

    // Calcular el descuento y el monto final según el criterio de la tienda
    if (monto_compra < 500) {
        monto_descuento = 0;
        monto_final = monto_compra;
    }
    else if (monto_compra >= 500 && monto_compra <= 1000) {
        monto_descuento = monto_compra * 0.05;
        monto_final = monto_compra - monto_descuento;
    }
    else if (monto_compra > 1000 && monto_compra <= 7000) {
        monto_descuento = monto_compra * 0.11;
        monto_final = monto_compra - monto_descuento;
    }
    else if (monto_compra > 7000 && monto_compra <= 15000) {
        monto_descuento = monto_compra * 0.18;
        monto_final = monto_compra - monto_descuento;
    }
    else {
        monto_descuento = monto_compra * 0.25;
        monto_final = monto_compra - monto_descuento;
    }

    // Imprimir el monto final a pagar por el cliente
    cout << "El monto final a pagar es: $" << monto_final << endl;

    return 0;
}
