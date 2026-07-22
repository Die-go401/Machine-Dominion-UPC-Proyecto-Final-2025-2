#pragma once
#include <string>
#include "Balas.h"
#include <vector>
using namespace std;
using namespace System;
using namespace System::Drawing;
class rayo {
private:
	bool terminado; //Atributo que nos indica si ya no se debe dibujar
	int x, y;
	int ancho, alto;
	int iteraX, iteraY;
	Direcciones direccion;
public:
	rayo(int x, int y, Direcciones dir) {
		this->x = x;
		this->y = y;
		ancho = alto = 0;
		this->direccion = dir;
		terminado = false;
		iteraY = iteraX = -1;
	}
	~rayo() {

	}
	void dibujarRayo(Graphics^ g, Bitmap^ dere, Bitmap^ izqui, Bitmap^ abajo, Bitmap^ arriba) {
		if (direccion == Derecha) {
			ancho = dere->Width;
			alto = dere->Height / 4;
			iteraX = 0;
			iteraY++;
			if (iteraY > 3) {
				terminado = true;
			}
			Rectangle sprite = Rectangle(ancho * iteraX, alto * iteraY, ancho, alto);
			Rectangle zoom = Rectangle(x + 40, y - 10, ancho * 0.5, alto * 0.5);
			if (terminado == false) {
				g->DrawImage(dere, zoom, sprite, GraphicsUnit::Pixel);
			}
		}
		else if (direccion == Izquierda) {
			ancho = izqui->Width;
			alto = izqui->Height / 4;
			iteraX = 0;
			iteraY++;
			if (iteraY > 3) {
				terminado = true;
			}
			Rectangle sprite = Rectangle(ancho * iteraX, alto * iteraY, ancho, alto);
			Rectangle zoom = Rectangle(x - 435, y - 10, ancho * 0.5, alto * 0.5);
			if (terminado == false) {
				g->DrawImage(izqui, zoom, sprite, GraphicsUnit::Pixel);
			}
		}
		else if (direccion == Abajo) {
			ancho = abajo->Width / 4;
			alto = abajo->Height;
			iteraY = 0;
			iteraX++;
			if (iteraX > 3) {
				terminado = true;
			}
			Rectangle sprite = Rectangle(ancho * iteraX, alto * iteraY, ancho, alto);
			Rectangle zoom = Rectangle(x - 10, y + 46, ancho * 0.5, alto * 0.5);
			if (terminado == false) {
				g->DrawImage(abajo, zoom, sprite, GraphicsUnit::Pixel);
			}
		}
		else if (direccion == Arriba) {
			ancho = arriba->Width / 4;
			alto = arriba->Height;
			iteraY = 0;
			iteraX++;
			if (iteraX > 3) {
				terminado = true;
			}
			Rectangle sprite = Rectangle(ancho * iteraX, alto * iteraY, ancho, alto);
			Rectangle zoom = Rectangle(x - 10, y - 435, ancho * 0.5, alto * 0.5);
			if (terminado == false) {
				g->DrawImage(arriba, zoom, sprite, GraphicsUnit::Pixel);
			}
		}


	}
	Rectangle getRectangleRayo() {
		if (direccion == Derecha) {
			if (iteraY == 0) {
				return Rectangle(x, y, 45, 38);
			}
			else if (iteraY == 1) {
				return Rectangle(x, y, 86, 38);
			}
			else if (iteraY == 2) {
				return Rectangle(x, y, 160, 38);
			}
			else if (iteraY == 3) {
				return Rectangle(x, y, 260, 38);
			}
		}
		else if (direccion == Izquierda) {
			if (iteraY == 0) {
				return Rectangle(x - 45, y, 45, 38);
			}
			else if (iteraY == 1) {
				return Rectangle(x - 86, y, 86, 38);
			}
			else if (iteraY == 2) {
				return Rectangle(x - 160, y, 160, 38);
			}
			else if (iteraY == 3) {
				return Rectangle(x - 260, y, 260, 38);
			}
		}
		else if (direccion == Abajo) {
			if (iteraX == 0) {
				return Rectangle(x, y, 38, 45);
			}
			else if (iteraX == 1) {
				return Rectangle(x, y, 38, 87);
			}
			else if (iteraX == 2) {
				return Rectangle(x, y, 38, 160);
			}
			else if (iteraX == 3) {
				return Rectangle(x, y, 38, 260);
			}
		}
		else if (direccion == Arriba) {
			if (iteraX == 0) {
				return Rectangle(x, y - 45, 38, 45);
			}
			else if (iteraX == 1) {
				return Rectangle(x, y - 87, 38, 87);
			}
			else if (iteraX == 2) {
				return Rectangle(x, y - 160, 38, 160);
			}
			else if (iteraX == 3) {
				return Rectangle(x, y - 260, 38, 260);
			}
		}



	}
	bool getTerminado() {
		return terminado;
	}
	void setTerminado(bool terminado) {
		this->terminado = terminado;
	}

};
//=================================================================================================================
class Principal {
private:
	string nombre;
	int x, y;
	int ancho, alto;
	int dx, dy;
	int iteraX, iteraY;
	int numeroBalas;
	int vida;
	Direcciones UltimaTecla;
	Direcciones direccion;
	vector <bala*> balas;
	bool disparandoRayo;
	rayo* r;
public:
	Principal(int x, int y) {
		nombre = "Diego";
		this->x = x;
		this->y = y;
		dx = dy = 0;
		direccion = Ninguna;
		UltimaTecla = Abajo;
		numeroBalas = 5;
		vida = 10;
		iteraX = 0;
		iteraY = 0;
		r = nullptr;
		disparandoRayo = false;
	}
	~Principal() {
		if (r != nullptr) {
			delete r;
		}

	}
	void dibujarPrincipal(Graphics^ g, Bitmap^ b) {
		ancho = b->Width / 4;
		alto = b->Height / 4;
		Rectangle sprite = Rectangle(ancho * iteraX, alto * iteraY, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 1.5, alto * 1.5);
		g->DrawImage(b, zoom, sprite, GraphicsUnit::Pixel);

	}
	//Mundo 3 
	void dibujarPrincipal2(Graphics^ g, Bitmap^ b, Bitmap^ dere, Bitmap^ izqui, Bitmap^ abajo, Bitmap^ arriba) {
		ancho = b->Width / 4;
		alto = b->Height / 4;
		Rectangle sprite = Rectangle(ancho * iteraX, alto * iteraY, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 1.5, alto * 1.5);
		g->DrawImage(b, zoom, sprite, GraphicsUnit::Pixel);
		// Dibujamos el rayo si existe
		if (disparandoRayo && r != nullptr) {
			r->dibujarRayo(g, dere, izqui, abajo, arriba);

			if (r->getTerminado() == true) {
				delete r;
				r = nullptr;
				disparandoRayo = false;
			}
		}
	}
	//MUNDO 1
	void moverPrincipal(Graphics^ g, Bitmap^ b) {
		iteraX++;
		if (iteraX > 3) {
			iteraX = 0;
		}
		switch (direccion) {
		case Abajo:
			iteraY = 1;
			dy = 10;
			dx = 0;
			UltimaTecla = Abajo;
			break;
		case Izquierda:
			iteraY = 3;
			dy = 0;
			dx = -10;
			UltimaTecla = Izquierda;
			break;
		case Derecha:
			iteraY = 2;
			dx = 10;
			dy = 0;
			UltimaTecla = Derecha;
			break;
		case Arriba:
			iteraY = 0;
			dx = 0;
			dy = -10;
			UltimaTecla = Arriba;
			break;
			//Si no se ha precionado una tecla
		case Ninguna:
			dx = 0;
			dy = 0;
			switch (UltimaTecla) {
			case Abajo:
				iteraX = 0;
				iteraY = 1;
				break;
			case Izquierda:
				iteraX = 0;
				iteraY = 3;
				break;
			case Derecha:
				iteraX = 0;
				iteraY = 2;
				break;
			case Arriba:
				iteraX = 0;
				iteraY = 0;
				break;
			}

			break;
		}
		//Evaluamos los limites de la ventana
		if (x + dx < 0 || x + dx + ancho * 1.5 >g->VisibleClipBounds.Width) {
			dx = 0;
		}
		if (y + dy < 0 || y + dy + alto * 1.5 > g->VisibleClipBounds.Height) {
			dy = 0;
		}
		x += dx;
		y += dy;
		//Dibujamos
		dibujarPrincipal(g, b);


	}
	//MUNDO 2 - PARTE 2
	void moverPrincipal2(Graphics^ g, Bitmap^ b) {
		iteraX++;
		if (iteraX > 3) {
			iteraX = 0;
		}
		switch (direccion) {
		case Abajo:
			iteraY = 1;
			dy = 15;
			dx = 0;
			UltimaTecla = Abajo;
			break;
		case Arriba:
			iteraY = 0;
			dx = 0;
			dy = -15;
			UltimaTecla = Arriba;
			break;
		case Derecha:
			//No se modifica el dx o dy solo cambia el iteraY (cuando se dispara un coco)
			iteraY = 2;
			UltimaTecla = Derecha;
			break;
			//Si no se ha precionado una tecla
		case Ninguna:
			dx = 0;
			dy = 0;
			switch (UltimaTecla) {
			case Abajo:
				iteraX = 0;
				iteraY = 1;
				break;
			case Arriba:
				iteraX = 0;
				iteraY = 0;
				break;
			case Derecha:
				iteraX = 0;
				iteraY = 2;
				break;
			}

			break;
		}
		//Evaluamos los limites de la ventana
		if (x + dx < 0 || x + dx + ancho * 1.5 >g->VisibleClipBounds.Width) {
			dx = 0;
		}
		if (y + dy < 0 || y + dy + alto * 1.5 > g->VisibleClipBounds.Height) {
			dy = 0;
		}
		x += dx;
		y += dy;
		//Dibujamos
		dibujarPrincipal(g, b);
	}
	string getNombre() { return nombre; }
	void setDireccion(Direcciones direx) {
		this->direccion = direx;
	}
	Direcciones getDireccion() {
		if (iteraY == 0) {
			return Arriba;
		}
		else if (iteraY == 1) {
			return Abajo;
		}
		else if (iteraY == 2) {
			return Derecha;
		}
		else if (iteraY == 3) {
			return Izquierda;
		}

	}
	Rectangle getRectanglePrincipal() {
		return Rectangle(x, y, ancho * 1.5, alto * 1.5);
	}
	vector<bala*>& Principal::getBalas() {
		return balas;
	}
	void Principal::disparar() {
		if (balas.size() < numeroBalas) {
			bala* b = new bala(x, y, getDireccion());
			balas.push_back(b); //Agrega una bala al final del vector

		}



	}
	void Principal::ControlBalas(Graphics^ g, Bitmap^ b) {
		for (int i = 0; i < balas.size(); i++) { //balas.size() nos brinda el tamaño del vector
			balas[i]->mover(g, b, b, b);
		}
		for (int i = balas.size() - 1; i >= 0; i--) { //Recorremos el vector de atras hacia adelante
			if (balas[i]->getActiva() == false) { //Si la bala ya no esta activa
				delete balas[i]; //Se borra la memoria dinamica
				balas.erase(balas.begin() + i); //elimina la bala del vector
			}
		}
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	void setVida(int vida) {
		this->vida = vida;
	}
	int getVida() {
		return vida;
	}

	//para el controlador 2 
	void setDX(int v) { dx = v; }
	void setDY(int v) { dy = v; }
	void setX(int v1) { x = v1; }
	void setY(int v2) { y = v2; }

	int getDX() { return dx; }
	int getDY() { return dy; }

	int getAlto() {
		return alto;
	}
	bool getDisparandoRayo() {
		return disparandoRayo;
	}
	void setDisparandoRayo(bool disparandoRayo) {
		this->disparandoRayo = disparandoRayo;
	}
	int getAncho() {
		return ancho;
	}
	rayo* getRayo() {
		return r;
	}
	void setRayo(rayo* r) {
		this->r = r;
	}
	Direcciones getUltimaDireccion() {
		return UltimaTecla;
	}
	
};