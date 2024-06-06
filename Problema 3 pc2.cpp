#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Cliente {
    string nombre;
    int unidades;
    float precioUnidad;
    string estado;
};

float calcularFactura(const Cliente& cliente) {
    return cliente.unidades * cliente.precioUnidad;
}

int main() {
    int numClientes;
    cout << "Ingrese el número de clientes: ";
    cin >> numClientes;

    vector<Cliente> clientes(numClientes);

    for (int i = 0; i < numClientes; ++i) {
        cout << "Ingrese el nombre del cliente " << i + 1 << ": ";
        cin >> clientes[i].nombre;
        cout << "Ingrese el número de unidades solicitadas por " << clientes[i].nombre << ": ";
        cin >> clientes[i].unidades;
        cout << "Ingrese el precio por unidad para " << clientes[i].nombre << ": ";
        cin >> clientes[i].precioUnidad;
        cout << "Ingrese el estado del cliente " << clientes[i].nombre << " (moroso, atrasado, pagado): ";
        cin >> clientes[i].estado;
    }

    cout << "\nClientes en estado moroso:" << endl;
    for (const Cliente& cliente : clientes) {
        if (cliente.estado == "moroso") {
            cout << cliente.nombre << endl;
        }
    }

    float cantidad;
    cout << "\nIngrese la cantidad para filtrar clientes en estado pagado: ";
    cin >> cantidad;

    cout << "\nClientes en estado pagado con factura mayor a " << cantidad << ":" << endl;
    for (const Cliente& cliente : clientes) {
        if (cliente.estado == "pagado" && calcularFactura(cliente) > cantidad) {
            cout << cliente.nombre << endl;
        }
    }

    float sumaFacturas = 0;
    for (const Cliente& cliente : clientes) {
        sumaFacturas += calcularFactura(cliente);
    }
    float promedioFacturas = sumaFacturas / numClientes;

    cout << "\nEl promedio de las facturas es: " << promedioFacturas << endl;

    return 0;
}
