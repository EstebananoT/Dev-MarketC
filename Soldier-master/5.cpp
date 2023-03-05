#include <iostream>
#include <map>

using namespace std;

int main() {
    // Definimos un mapa que relaciona la clave de la zona con su precio por minuto
    map<int, double> precios = { {12, 4}, {15, 3.2}, {18, 5.5}, {19, 4.8}, {23, 7}, {25, 7}, {29, 4} };

    // Pedimos al usuario que ingrese la clave de la zona y el número de minutos hablados
    int clave_zona;
    double minutos;
    cout << "Ingrese la clave de la zona geográfica: ";
    cin >> clave_zona;
    cout << "Ingrese el número de minutos hablados: ";
    cin >> minutos;

    // Calculamos el costo total de la llamada
    double costo = precios[clave_zona] * minutos;

    // Imprimimos el resultado
    cout << "El costo total de la llamada es: $" << costo << endl;

    return 0;
}
