#pragma once
#include "Balas.h"
#include <vector>
using namespace std;
using namespace System;
using namespace System::Drawing;
class Enemigo {
protected:
	vector <bala*> balas;
	int x, y;
	int ancho, alto;
	int dx, dy;
	int iteraX, iteraY;
	int vida;

	bool normal;
	bool fuego;
	bool hielo;
public:
	Enemigo(int x, int y) {
		this->x = x;
		this->y = y;

		normal = false;
		fuego = false;
		hielo = false;
	}
	//Constructor para araña
	Enemigo(int x, int y, int dy) {
		this->x = x;
		this->y = y;
		this->dy = dy;
	}
	~Enemigo() {

	}
	virtual void mover(int jx, int jy, Graphics^ g, Bitmap^ b) = 0;
	virtual void dibujar(Graphics^ g, Bitmap^ b) {

	}
	virtual void disparar(int Random, int tipo) {
		if (Random == 20) {
			if (tipo == 0) {
				normal = true;
				bala* b = new bala(x, y, iteraY);
				balas.push_back(b);
			}
			else if (tipo == 1) {
				fuego = true;
				bala* b = new bala(x, y, iteraY, 1);
				balas.push_back(b);
			}
			else if (tipo == 2) {
				hielo = true;
				bala* b = new bala(x, y, iteraY, 2);
				balas.push_back(b);
			}
		}
	}
	void setNormal(bool xd) { normal = xd; }
	bool getNormal() { return normal; }
	void setFuego(bool xd) { fuego = xd; }
	bool getFuego() { return fuego; }
	void setHielo(bool xd) { hielo = xd; }
	bool getHielo() { return hielo; }

	void ControlBalas(Graphics^ g, Bitmap^ bala_normal, Bitmap^ bola_fuego, Bitmap^ bola_hielo) {
		//Mover y dibujar las balas
		for (int i = 0; i < balas.size(); i++) {
			balas[i]->mover(g, bala_normal, bola_fuego, bola_hielo);
		}
		//Evaluar su estado
		for (int i = 0; i < balas.size(); i++) {
			if (!balas[i]->getActiva()) {
				delete balas[i];
				balas.erase(balas.begin() + i);
				i--;
			}
		}
	}
	//Setters and Getters
	vector<bala*>& getBalas() {
		return balas;
	}
	virtual Rectangle getRectangleEnemigo() {
		return Rectangle(x, y, ancho, alto);
	}
	int getAncho() {
		return ancho;
	}
	int getAlto() {
		return alto;
	}
	void setVida(int v) {
		vida = v;
	}
	int getVida() {
		return vida;
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
	void setDY(int dy) {
		this->dy = dy;
	}
	void setDX(int dx) {
		this->dx = dx;
	}
	void setIteraX(int iteraX) {
		this->iteraX = iteraX;
	}
};
//====================================================================================
class Soldado : public Enemigo {
private:
	bool sonidoBalaEnemigo;
public:
	Soldado(int x, int y) : Enemigo(x, y) {
		this->x = x;
		this->y = y;
		vida = 3;
		dx = 10;
		dy = 10;

		iteraX = 0;
		iteraY = 0;
		ancho = 0;
		alto = 0;

		sonidoBalaEnemigo = false;
	}

	void dibujar(Graphics^ g, Bitmap^ b) override {
		ancho = b->Width / 7;
		alto = b->Height / 4;
		//Rectangles
		Rectangle sprite = Rectangle(iteraX * ancho, iteraY * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 2, alto * 2);
		//Dibujamos
		g->DrawImage(b, zoom, sprite, GraphicsUnit::Pixel);
		iteraX++;
		if (iteraX > 5) {
			iteraX = 0;
		}
	}

	void mover(int jx, int jy, Graphics^ g, Bitmap^ b) override {
		//Logica de persecucion 
		// La distancia en 2D se calcula con la distancia Euclidiana 
		double distancia = sqrt(pow(jx - x, 2) + pow(jy - y, 2));
		if (distancia > 150) {
			//Derecha
			if (x < jx) {
				x += dx;
				iteraY = 2;
			}
			//Izquierda
			else if (x > jx) {
				x -= dx;
				iteraY = 3;
			}
			//Abajo
			if (y < jy) {
				y += dy;
				iteraY = 1;
			}
			//Arriba
			else if (y > jy) {
				y -= dy;
				iteraY = 0;
			}
		}
		if (x + ancho > g->VisibleClipBounds.Width) x = g->VisibleClipBounds.Width - ancho;
		if (y + alto > g->VisibleClipBounds.Height) y = g->VisibleClipBounds.Height - alto;
		if (x < 0) x = 0;
		if (y < 0) y = 0;
		dibujar(g, b);
	}
	Rectangle getRectangleEnemigo() override {
		return Rectangle(x, y, ancho * 2, alto * 2);
	}
	void disparar(int Random, int tipo) override {
		if (Random == 20) {
			if (tipo == 0) {
				//Se activa el audio del sonido de la bala 
				sonidoBalaEnemigo = true;
				bala* b = new bala(x, y, iteraY);
				balas.push_back(b);
				iteraX = 6;
			}
			else if (tipo == 1) {
				sonidoBalaEnemigo = true;
				bala* b = new bala(x, y, iteraY, 1);
				balas.push_back(b);
			}
		}
	}

	void setsonidoBalaEnemigo(bool xd) { sonidoBalaEnemigo = xd; }
	bool getsonidosBalaEnemigo() { return sonidoBalaEnemigo; }

};

//=========================================================================================================
class Jefe : public Enemigo {
private:
	vector <Soldado*> soldados;
	bool furia;
	bool rafagaBalas1;
	bool rafagaBalas2;
	bool rafagaBalas3;
public:
	Jefe(int x, int y) : Enemigo(x, y) {
		rafagaBalas1 = false;
		rafagaBalas2 = false;
		rafagaBalas3 = false;
		vida = 150;
		dx = 20;
		dy = 20;
		furia = false;
	}
	~Jefe() {
		for (int i = 0; i < soldados.size(); i++) {
			delete soldados[i];
		}
		soldados.clear();

	}

	void dibujar(Graphics^ g, Bitmap^ b) override {
		ancho = b->Width / 2;
		alto = b->Height / 4;
		//Rectangles
		Rectangle sprite = Rectangle(iteraX * ancho, iteraY * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 3, alto * 3);
		//Dibujamos
		g->DrawImage(b, zoom, sprite, GraphicsUnit::Pixel);


		if (vida <= 80) {
			furia = true;
		}

	}

	void mover(int jx, int jy, Graphics^ g, Bitmap^ b) {

		double distX = jx - x;
		double distY = jy - y;

		double distancia = sqrt(distX * distX + distY * distY);

		if (distancia > 240) {

			// Animación del sprite
			iteraX = (iteraX + 1) % 2;

			// Determinar si moverse mas en X o en Y
			//abs - valor absoluto
			if (abs(distX) > abs(distY)) {

				if (distX > 0) { // derecha
					x += dx;
					iteraY = 2;
				}
				else { // izquierda
					x -= dx;
					iteraY = 3;
				}
			}
			else {

				if (distY > 0) { // abajo
					y += dy;
					iteraY = 1;
				}
				else { // arriba
					y -= dy;
					iteraY = 0;
				}
			}
		}

		// limites de la pantalla
		if (x + ancho > g->VisibleClipBounds.Width)  x = g->VisibleClipBounds.Width - ancho;
		if (y + alto > g->VisibleClipBounds.Height)  y = g->VisibleClipBounds.Height - alto;
		if (x < 0) x = 0;
		if (y < 0) y = 0;

		dibujar(g, b);
	}
	void ControlSoldados(int jx, int jy, Graphics^ g, Bitmap^ soldados, Bitmap^ bala_normal, int random) {
		for (int i = 0; i < this->soldados.size(); i++) {
			//Mover y dibujar
			this->soldados[i]->mover(jx, jy, g, soldados);
			this->soldados[i]->disparar(random, 0);
			this->soldados[i]->ControlBalas(g, bala_normal, bala_normal, bala_normal);

		}

	}

	bool getFuria() {
		return furia;
	}
	void setFuria(bool furia) {
		this->furia = furia;
	}
	void AgregarSoldado(int p) {
		if (p == 60) {
			Soldado* pepito = new Soldado(x, y);
			soldados.push_back(pepito);
		}

	}
	void EliminarSoldado() {

		for (int i = 0; i < soldados.size(); i++) {
			if (soldados[i]->getVida() <= 0) {
				delete soldados[i];
				soldados.erase(soldados.begin() + i);
				i--;
			}

		}


	}
	//Getter del vector
	vector<Soldado*>& getSoldados() {
		return soldados;
	}

	Rectangle getRectangleEnemigo() override {
		return Rectangle(x, y, ancho * 3, alto * 3);
	}
	void RafagaBalas1() {
		balas.push_back(new bala(x + ancho / 2, y + alto / 2, -10, -10, 0));
		balas.push_back(new bala(x + ancho / 2, y + alto / 2, 10, -10, 0));
		balas.push_back(new bala(x + ancho / 2, y + alto / 2, 10, 10, 0));
		balas.push_back(new bala(x + ancho / 2, y + alto / 2, -10, 10, 0));

		rafagaBalas1 = true;
	}


	void RafagaBalas2() {
		int contador = 0;
		// Tramo 1 - arriba
		contador = 0;
		for (int i = 0; i < 4; i++) {
			rafagaBalas2 = true;
			balas.push_back(new bala(x + contador, y, 0, -10, 0));
			contador += 25;
		}

		// Tramo 2 - derecha
		contador = 0;
		for (int i = 0; i < 4; i++) {
			rafagaBalas2 = true;
			balas.push_back(new bala(x + ancho, y + contador, 10, 0, 0));
			contador += 25;
		}

		// Tramo 3 - abajo
		contador = 0;
		for (int i = 0; i < 4; i++) {
			rafagaBalas2 = true;
			balas.push_back(new bala(x + contador, y + alto, 0, 10, 0));
			contador += 25;
		}

		// Tramo 4 - izquierda
		contador = 0;
		for (int i = 0; i < 4; i++) {
			rafagaBalas2 = true;
			balas.push_back(new bala(x, y + contador, -10, 0, 0));
			contador += 25;
		}

	}
	void RafagaBalas3() {
		//Diagonales
		balas.push_back(new bala(x - 10, y - 10, -10, -10, 0));
		balas.push_back(new bala(x, y - 15, -10, -10, 0));
		balas.push_back(new bala(x - 15, y, -10, -10, 0));

		balas.push_back(new bala(x + ancho + 10, y - 1, 10, -10, 0));
		balas.push_back(new bala(x + ancho, y + 15, 10, -10, 0));
		balas.push_back(new bala(x + ancho, y - 15, 10, -10, 0));

		balas.push_back(new bala(x + ancho + 15, y + alto, 10, 10, 0));
		balas.push_back(new bala(x + ancho + 15, y + alto, 10, 10, 0));
		balas.push_back(new bala(x + ancho, y + alto + 15, 10, 10, 0));

		balas.push_back(new bala(x - 10, y + alto + 10, -10, 10, 0));
		balas.push_back(new bala(x, y + alto + 15, -10, 10, 0));
		balas.push_back(new bala(x - 15, y + alto, -10, 10, 0));
		rafagaBalas3 = true;
	}

	void setRafagaBalas1(bool xd) { rafagaBalas1 = xd; }
	bool getRafagaBalas1() { return rafagaBalas1; }
	void setRafagaBalas2(bool xd) { rafagaBalas2 = xd; }
	bool getRafagaBalas2() { return rafagaBalas2; }
	void setRafagaBalas3(bool xd) { rafagaBalas3 = xd; }
	bool getRafagaBalas3() { return rafagaBalas3; }
};
//========================================================================================================
class arania : public Enemigo {
public:
	arania(int x, int y, int dy) : Enemigo(x, y) {
		this->x = x;
		this->y = y;
		iteraX = iteraY = 0;
		this->dy = dy;
		dx = 0;
		vida = 3;
	}
	~arania() {

	}
	void dibujar(Graphics^ g, Bitmap^ b) {
		ancho = b->Width / 6;
		alto = b->Height / 2;
		//Rectangles
		Rectangle sprite = Rectangle(iteraX * ancho, iteraY * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 2, alto * 2);
		//Dibujamos
		g->DrawImage(b, zoom, sprite, GraphicsUnit::Pixel);
	}
	void moverArania(Graphics^ g, Bitmap^ b) {
		//Iteras
		iteraX++;
		if (iteraX > 5) {
			iteraX = 0;
		}
		if (dy == 15) {
			iteraY = 1;
		}
		else if (dy == -15) {
			iteraY = 0;
		}
		//Mover
		y += dy;
		dibujar(g, b);
	}
	Rectangle getRectangleArania() {
		return Rectangle(x, y, ancho * 2, alto * 2);
	}
	void mover(int x, int y, Graphics^ g, Bitmap^ b) {
		//NO SE USA EN ARAÑA PERO SE DEBE DECLARAR
	}
};
//====================================================================================================
class araniaHorizontal : public Enemigo {
private:
	int tipoArania;
public:
	araniaHorizontal(int x, int y, int dy, int tipo) : Enemigo(x, y) {
		Random^ r = gcnew Random();
		this->x = x;
		this->y = y;
		iteraX = iteraY = 0;
		this->dy = dy;
		dx = 0;
		vida = 3;
		tipoArania = tipo;
		System::Threading::Thread::Sleep(10); //<--- importante para los randoms y no se repitan
	}
	~araniaHorizontal() {

	}
	Rectangle getRectangleArania() {
		return Rectangle(x, y, ancho * 2, alto * 2);
	}
	//ARAÑA HORIZONTAL
	void moverAraniaHorizontal() {
		dx = -5;
		iteraX++;
		if (iteraX > 5) {
			iteraX = 0;
		}
		x += dx;
	}
	void dibujarAraniaHorizontal(Graphics^ g, Bitmap^ b1, Bitmap^ b2, Bitmap^ b3, Bitmap^ b4) {
		if (tipoArania == 0) // ARAÑA NORMAL
		{
			ancho = b1->Width / 6;
			alto = b1->Height;
			//Rectangles
			Rectangle sprite = Rectangle(iteraX * ancho, iteraY * alto, ancho, alto);
			Rectangle zoom = Rectangle(x, y, ancho * 1.8, alto * 1.8);
			//Dibujamos
			g->DrawImage(b1, zoom, sprite, GraphicsUnit::Pixel);
		}
		else if (tipoArania == 1) //ARAÑA MORADA
		{
			ancho = b2->Width / 6;  //  --> RECUERDA CAMBIAR JEJE
			alto = b2->Height;     //  --> RECUERDA CAMBIAR JEJE 
			//Rectangles
			Rectangle sprite = Rectangle(iteraX * ancho, iteraY * alto, ancho, alto);
			Rectangle zoom = Rectangle(x, y, ancho * 1.8, alto * 1.8);
			//Dibujamos
			g->DrawImage(b2, zoom, sprite, GraphicsUnit::Pixel);
		}
		else if (tipoArania == 2) // ARAÑA AMARILLA
		{
			ancho = b3->Width / 6;  
			alto = b3->Height;     
			//Rectangles
			Rectangle sprite = Rectangle(iteraX * ancho, iteraY * alto, ancho, alto);
			Rectangle zoom = Rectangle(x, y, ancho * 1.8, alto * 1.8);
			//Dibujamos
			g->DrawImage(b3, zoom, sprite, GraphicsUnit::Pixel);
		}
		else if (tipoArania == 3) // ARAÑA ROJA
		{
			ancho = b4->Width / 6;
			alto = b4->Height;
			//Rectangles
			Rectangle sprite = Rectangle(iteraX * ancho, iteraY * alto, ancho, alto);
			Rectangle zoom = Rectangle(x, y, ancho * 1.8, alto * 1.8);
			//Dibujamos
			g->DrawImage(b4, zoom, sprite, GraphicsUnit::Pixel);
		}


	}
	Rectangle getRectangleArania2() {
		return Rectangle(x, y, ancho * 1.8, alto * 1.8);
	}

	void mover(int x, int y, Graphics^ g, Bitmap^ b) {
		//NO SE USA EN ARAÑA PERO SE DEBE DECLARAR
	}
};
//=========================================================================================
class Acechador : public Enemigo {
public:
	Acechador(int x, int y) : Enemigo(x, y) {
		this->x = x;
		this->y = y;
		vida = 6;
		dx = 5;
		dy = 5;
		iteraX = 0;
		iteraY = 0;
		ancho = 0;
		alto = 0;
	}

	void dibujar(Graphics^ g, Bitmap^ b) override {
		iteraX++;
		if (iteraX > 5) {
			iteraX = 0;
		}
		ancho = b->Width / 6;
		alto = b->Height / 4;
		//Rectangles
		Rectangle sprite = Rectangle(iteraX * ancho, iteraY * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 0.5, alto * 0.5);
		//Dibujamos
		g->DrawImage(b, zoom, sprite, GraphicsUnit::Pixel);
	}

	void mover(int jx, int jy, Graphics^ g, Bitmap^ b) override {

		//Logica de persecucion 
	// La distancia en 2D se calcula con la distancia Euclidiana 
		double distancia = sqrt(pow(jx - x, 2) + pow(jy - y, 2));
		if (distancia > 0) {
			//Derecha
			if (x < jx) {
				x += dx;
				iteraY = 2;
			}
			//Izquierda
			else if (x > jx) {
				x -= dx;
				iteraY = 3;
			}
			//Abajo
			if (y < jy) {
				y += dy;
				iteraY = 1;
			}
			//Arriba
			else if (y > jy) {
				y -= dy;
				iteraY = 0;
			}
		}
		if (x + ancho > g->VisibleClipBounds.Width) x = g->VisibleClipBounds.Width - ancho;
		if (y + alto > g->VisibleClipBounds.Height) y = g->VisibleClipBounds.Height - alto;
		if (x < 0) x = 0;
		if (y < 0) y = 0;
		dibujar(g, b);

	}
	Rectangle getRectangleEnemigo() override {
		return Rectangle(x, y, ancho * 0.5, alto * 0.5);
	}




};

