#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Jugador {
    char nombre[20];
    int edad;
    int mundo;
};
void CrearArchivoParametros();
vector<pair<int, int>> LeerParametros();

