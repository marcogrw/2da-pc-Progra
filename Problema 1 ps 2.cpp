#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Declaración de la matriz
  int matriz[3][3];

  // Leer los elementos de la matriz
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> matriz[i][j];
    }
  }

  // Declaración de los vectores para las sumas de filas y columnas
  vector<int> sumaFilas(3, 0);
  vector<int> sumaColumnas(3, 0);

  // Calcular la suma de cada fila
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      sumaFilas[i] += matriz[i][j];
    }
  }

  // Calcular la suma de cada columna
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 3; i++) {
      sumaColumnas[j] += matriz[i][j];
    }
  }

  // Mostrar los resultados
  cout << "Sumas de filas: ";
  for (int i = 0; i < 3; i++) {
    cout << sumaFilas[i] << " ";
  }

  cout << endl;

  cout << "Sumas de columnas: ";
  for (int j = 0; j < 3; j++) {
    cout << sumaColumnas[j] << " ";
  }

  cout << endl;

  return 0;
}
