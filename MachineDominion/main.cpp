#include "Archivos.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
//ARCHIVOS DE TEXTO =======================================================================================================
void CrearArchivoParametros() {

    ofstream archivo("files/PARAMETERS.txt", ios::out);

    if (!archivo.is_open()) {
        cout << "No se pudo crear PARAMETERS.txt :(" << endl;
        return;
    }

    archivo << 100 << " " << 100 << endl;
    archivo << 320 << " " << 356 << endl;
    archivo << 430 << " " << 256 << endl;
    archivo << 540 << " " << 490 << endl;
    archivo << 500 << " " << 237 << endl;
    archivo << 150 << " " << 280 << endl;
    archivo << 610 << " " << 510 << endl;
    archivo << 415 << " " << 478 << endl;

    archivo.close();
}
vector<pair<int, int>> LeerParametros() {

    vector<pair<int, int>> posiciones;
    ifstream archivo("files/PARAMETERS.txt");

    if (!archivo.is_open()) {
        cout << "Error al abrir PARAMETERS.txt\n";
        return posiciones;
    }

    int x, y;

    while (archivo >> x >> y) {
        posiciones.push_back(pair<int, int>(x, y));
    }

    archivo.close();
    return posiciones;
}
//ARCHIVO BINARIO========================================================================================================================
