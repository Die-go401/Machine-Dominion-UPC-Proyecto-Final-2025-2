#pragma once
#include<fstream>
#include<iostream>
#include<conio.h>

using namespace std;

typedef struct {
	int VIDAS;
	char NOMBRE[30];
	int PUNTAJE;
} Datos;



//void CrearArchivo() {
//	ofstream archivo; //output
//
//	archivo.open("RANKING.dat", ios::out | ios::binary);
//
//	if (archivo.fail()) exit(1);
//
//	archivo.close();
//
//}


