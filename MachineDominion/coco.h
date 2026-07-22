#pragma once
#include <iostream>
using namespace System;
using namespace System::Drawing;
class coco {
private:
	int x, y;
	int dx, dy;
	int ancho, alto;
	bool activo;
	int iteraX, iteraY;
	int tipo;
	bool cambiar;
	bool yaGolpeo;
	
public:
	coco(int x, int y, int tipo) {
		this->x = x;
		this->y = y;
		dx = 10;
		dy = 0;
		activo = true;
		iteraY = iteraX = 0;
		ancho = alto = 0;
		this->tipo = tipo;
		cambiar = false;
		yaGolpeo = false;
	}
	~coco() {

	}
	void dibujarCoco(Graphics^ g, Bitmap^ b) {
		iteraX++;
		if (iteraX > 5) {
			iteraX = 0;
		}
		//Coco normal
		if (tipo == 0) {
			iteraY = 0;
		}
		//Coco explosivo
		else {
			iteraY = 1;
		}
		ancho = b->Width / 6;
		alto = b->Height / 2;
		Rectangle sprite = Rectangle(iteraX * ancho, iteraY * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho, alto);
		g->DrawImage(b, zoom, sprite, GraphicsUnit::Pixel);
	}
	void moverCoco(Graphics^g) {
		x += dx;
		y += dy;
		if (cambiar == true) {
			cambiarDireccionDiagonal();
		}
		cambiar = false;
		if(y  + dy + alto > g->VisibleClipBounds.Height || y + dy < 0 ){
			//Cambio de direccion 
			dy *= -1;


	    }
		//Evaluamos si sigue dentro de la pantalla
		if (x > 750) {
			activo = false;
		}
	}
	Rectangle getRectangleCoco(){
		return Rectangle(x, y, ancho, alto);
	}
	bool getActivo() {
		return activo;
	}

	void setActivo(bool activo) {
		this->activo = activo;
	}
	void setCambiar(bool cambiar) {
		this->cambiar = cambiar;
	}
	int getTipo() {
		return tipo;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void setDY(int dy) {
		this->dy = dy;
	}
	int getDY() {
		return dy;
	}
	bool getYaGolpeo() {
		return yaGolpeo;
	}
	void setYaGolpeo(bool yaGolpeo) {
		this->yaGolpeo = yaGolpeo;
	}
	void cambiarDireccionDiagonal() {

		Random p;
		dx = 10;
		int r = p.Next(0, 2);

		if (r == 0)
			dy = -10;   // diagonal arriba
		else
			dy = 10;    // diagonal abajo
		
		_sleep(5);


	}
};