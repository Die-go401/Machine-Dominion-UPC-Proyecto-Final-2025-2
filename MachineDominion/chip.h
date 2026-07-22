#pragma once
#include "Indicador.h"
using namespace System;
using namespace System::Drawing;
class chip {
private:
	int x, y;
	int ancho, alto;
	bool activo;
	int contador;
	int iteraX, iteraY;
	circulo* c;
public:
	chip(int x, int y) {
		this->x = x;
		this->y = y;
		contador = 0;
		iteraX = iteraY = 0;
		ancho = alto = 0;
		c = new circulo(x + 60, y);  
		c->setVisible(false);
	}
	~chip() {
		delete c;
	}
	void dibujar(Graphics^ g, Bitmap^ b) {
		//IteraX
		if (contador == 500) {
			iteraX = 1;
		}
		else if (contador == 1000) {
			iteraX = 2;
		}
		else if (contador == 0) {
			iteraX = 0;
		}
		ancho = b->Width/3;
		alto = b->Height;
		Rectangle sprite = Rectangle(ancho * iteraX, alto * iteraY, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 1.4, alto * 1.4);
		g->DrawImage(b, zoom, sprite, GraphicsUnit::Pixel);
		if (c->getVisible()) {
			c->Dibujar(g, contador);
		}
	}
	Rectangle getRectangleChip() {
		return Rectangle(x, y, ancho * 1.4, alto * 1.4);
	}
	bool getActivo() {
		return activo;
	}
	void setActivo(bool activo) {
		this->activo = activo;
	}
	int getContador() {
		return contador;
	}
	void setContador(int contador) {
		this->contador = contador;
	}
	void ControlColicion(bool b) {
		//Contador
		if (b == true) {
			contador += 100;
			c->setVisible(true);

		} else {
			contador = 0;
			c->setVisible(false); 
		}
		
		
	}
};