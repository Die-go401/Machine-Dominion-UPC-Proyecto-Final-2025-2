#pragma once
#pragma once
using namespace System;
using namespace System::Drawing;
class Arbol {
protected:
	int x, y;
	int alto, ancho;
	int iteraX;
	int iteraY;
	int tipo; //Diferenciar entre arbol navidad y desidratado
public:
	Arbol(int x1, int y1 ){
		Random r;
		x = x1;
		y = y1;
		iteraX = iteraY = 0;
		ancho = alto = 0;
	};
	~Arbol(){
	};

	virtual void dibujarArbol(Graphics^g, Bitmap^ b) {

	}
	virtual Rectangle getRectangleArbol() {
		return Rectangle(x, y, ancho, alto);
	}
	//Setters and Getters
	int getY(){
		return y;
	}
	int getX(){
		return x;
	}
	int getAncho() {
		return ancho;
	}
	int getAlto() {
		return alto;
	}
	int getIteraX() {
		return iteraX;
	}
	int getIteraY() {
		return iteraY;
	}
	void setAncho(int ancho) {
		this->ancho = ancho;
	}
	void setAlto(int alto) {
		this->alto = alto;
	}
	int getTipo() {
		return tipo;
	}
	//Setter para evaluar el estado de los arboles desidratados
	void setIteraX(int iteraX) {
		this->iteraX = iteraX;
	}
};
//============================================================================================================
class ArbolNavidad : public Arbol {
public:
	ArbolNavidad(int x, int y) : Arbol(x, y) {
		this->x = x;
		this->y = y;
		tipo = 0;
	}
	~ArbolNavidad() {

	}
	void dibujarArbol(Graphics^ g, Bitmap^ b)override {
		iteraX++;
		if (iteraX > 1) {
			iteraX = 0;
		}

		ancho = b->Width / 2;
		alto = b->Height;
		Rectangle sprite = Rectangle(ancho * iteraX, alto * iteraY, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 0.5, alto * 0.5);
		g->DrawImage(b, zoom, sprite, GraphicsUnit::Pixel);
	}
	Rectangle getRectangleArbol() override {
		return Rectangle(x, y, ancho * 0.5, alto*0.5);
	}

};
//========================================================================================================
class ArbolDesidratado : public Arbol {
public:
	ArbolDesidratado(int x, int y) : Arbol(x, y) {
		this->x = x;
		this->y = y;
		tipo = 1;
	}
	~ArbolDesidratado() {

	}
	void dibujarArbol(Graphics^ g, Bitmap^ b) override {
		if (iteraX > 3) {
			iteraX = 3;
		}
		ancho = b->Width / 4;
		alto = b->Height;
		Rectangle sprite = Rectangle(ancho * iteraX, alto * iteraY, ancho, alto);
		Rectangle zoom = Rectangle(x ,y ,ancho * 2.2, alto * 2.2);
		g->DrawImage(b, zoom, sprite, GraphicsUnit::Pixel);

	}
	Rectangle getRectangleArbol() override{
		return Rectangle(x, y, ancho * 2.2, alto * 2.2);
	}
	
};