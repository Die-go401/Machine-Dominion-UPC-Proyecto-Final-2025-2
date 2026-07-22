#pragma once
#include "Arbol.h"
class ArbolNavidad : public Arbol{
public:
	ArbolNavidad(int x, int y) : Arbol(x, y) {
		this->x = x;
		this->y = y;
	}
	~ArbolNavidad() {

	}
	void dibujarArbol(Graphics^g, Bitmap^b)override {
		iteraX++;
		if (iteraX > 1) {
			iteraX = 0;
		}
	
		ancho = b->Width / 2;
		alto = b->Height;
		Rectangle sprite = Rectangle(ancho * iteraX, alto * iteraY, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho, alto);
		g->DrawImage(b, zoom, sprite, GraphicsUnit::Pixel);
	}
	Rectangle getRectangleArbol() override {
		return Rectangle(x, y, ancho, alto);
	}

};
