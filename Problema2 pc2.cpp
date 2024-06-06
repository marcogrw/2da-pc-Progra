#include <iostream>
#include <vector>
using namespace std;

struct Alumno {
    vector<float> notas;
};

float calcularMediaAlumno(const Alumno& alumno) {
    float suma = 0;
    int cuenta = 0;
    for (float nota : alumno.notas) {
        if (nota >= 0) {
            suma += nota;
            cuenta++;
        }
    }
    return cuenta > 0 ? suma / cuenta : 0;
}

float calcularMediaAsignatura(const vector<Alumno>& clase, int asignatura) {
    float suma = 0;
    int cuenta = 0;
    for (const Alumno& alumno : clase) {
        if (alumno.notas[asignatura] >= 0) {
            suma += alumno.notas[asignatura];
            cuenta++;
        }
    }
    return cuenta > 0 ? suma / cuenta : 0;
}

float calcularMediaGeneralClase(const vector<Alumno>& clase) {
    float suma = 0;
    for (const Alumno& alumno : clase) {
        suma += calcularMediaAlumno(alumno);
    }
    return suma / clase.size();
}

float calcularPorcentajeFaltas(const Alumno& alumno) {
    int faltas = 0;
    for (float nota : alumno.notas) {
        if (nota < 0) faltas++;
    }
    return (float)faltas / alumno.notas.size() * 100;
}

int main() {
    int numAlumnos, numAsignaturas = 8;
    cout << "Ingrese el número de alumnos: ";
    cin >> numAlumnos;

    vector<Alumno> clase(numAlumnos, Alumno{vector<float>(numAsignaturas, -1)}); // Inicializamos con -1 para indicar faltas

    for (int i = 0; i < numAlumnos; ++i) {
        cout << "Ingrese las notas del alumno " << i + 1 << " (use -1 para indicar falta):" << endl;
        for (int j = 0; j < numAsignaturas; ++j) {
            cin >> clase[i].notas[j];
        }
    }

    cout << "Medias por alumno:" << endl;
    for (int i = 0; i < numAlumnos; ++i) {
        cout << "Alumno " << i + 1 << ": " << calcularMediaAlumno(clase[i]) << endl;
    }

    cout << "Media general de la clase: " << calcularMediaGeneralClase(clase) << endl;

    cout << "Medias por asignatura:" << endl;
    for (int j = 0; j < numAsignaturas; ++j) {
        cout << "Asignatura " << j + 1 << ": " << calcularMediaAsignatura(clase, j) << endl;
    }

    cout << "Porcentaje de faltas por alumno:" << endl;
    for (int i = 0; i < numAlumnos; ++i) {
        cout << "Alumno " << i + 1 << ": " << calcularPorcentajeFaltas(clase[i]) << "%" << endl;
    }

    return 0;
}
