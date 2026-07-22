#pragma once
#include "Enemigo.h"
#include "Principal.h"
#include "coco.h"
#include "vector"
using namespace std;
class controlador2_2 {
private:
	bool explosivo;
	bool normal;
	Principal* jugador;
	vector<araniaHorizontal*> aranias;
	vector<coco*> cocos;
	bool victoria;
	bool derrota;
public:
	controlador2_2() {
		jugador = new Principal(190, 300);
		victoria = false;
		derrota = false;

		normal = false;
		explosivo = false;
	}
	~controlador2_2() {
		for (int i = 0; i < aranias.size(); i++) {
			delete aranias[i];
		}
		aranias.clear();
		for (int i = 0; i < cocos.size(); i++) {
			delete cocos[i];
		}
		cocos.clear();
		delete jugador;

	}
	void colisionLimites(Rectangle num1, Rectangle num2) {
		//Verificamos las coliciones con el jugador
		if (jugador->getRectanglePrincipal().IntersectsWith(num1))
			jugador->setY(num1.Bottom);
        
		if (jugador->getRectanglePrincipal().IntersectsWith(num2))
			jugador->setY(num2.Top - jugador->getAlto() - 15);


		
		//Verificamos las coliciones de los rectangles con loc cocos
		for (int i = 0; i < cocos.size(); i++) {
			if (cocos[i]->getRectangleCoco().IntersectsWith(num1)) {
				cocos[i]->setDY(cocos[i]->getDY() * -1);
			}
			if (cocos[i]->getRectangleCoco().IntersectsWith(num2)) {
				cocos[i]->setDY(cocos[i]->getDY() * -1);
			}

		}
	}
	void AgregarCocos() {
		if (cocos.size() < 7) {
			Random r;
			if (r.Next(0, 15) == 2) {
				coco* c = new coco(jugador->getX() + 95, jugador->getY() + 8, 1);
				cocos.push_back(c);
			}
			else {
				coco* c = new coco(jugador->getX() + 95, jugador->getY() + 8, 0);
				cocos.push_back(c);
			}


		}
	}
	void ControlJugador(Graphics^g, Bitmap^b) {
		jugador->moverPrincipal2(g, b);
	}
	void AgregarAranias() {
		Random r;
		if (r.Next(0, 31) == 10) {
			int posicionesY[5] = { 194,270,360,440,520 };
			int idx = r.Next(0, 5);

			araniaHorizontal* a = new araniaHorizontal(700, posicionesY[idx], 0, r.Next(0,4));
			aranias.push_back(a);
		}
		_sleep(3);
	}
	void ControlAranias(Graphics^ g, Bitmap^ b1, Bitmap^ b2, Bitmap^ b3, Bitmap^ b4) {
		for (int i = 0; i < aranias.size(); i++) {
			aranias[i]->moverAraniaHorizontal();
			aranias[i]->dibujarAraniaHorizontal(g, b1,b2,b3,b4);
		}

		for (int i = aranias.size() - 1; i >= 0; i--) {
			if (aranias[i]->getRectangleArania().X <= 260) {
				delete aranias[i];
				aranias.erase(aranias.begin() + i);

				derrota = true;
			}
		}
	}
	void ControlCocos(Graphics^ g, Bitmap^ b, Bitmap^ explocion) {

		// Primero eliminar cocos inactivos (pero de atrás hacia adelante)
		for (int i = cocos.size() - 1; i >= 0; i--) {
			if (!cocos[i]->getActivo()) {
				delete cocos[i];
				cocos.erase(cocos.begin() + i);
			}
		}

		// Dibujar y mover cocos
		for (int i = 0; i < cocos.size(); i++) {
			cocos[i]->moverCoco(g);
			cocos[i]->dibujarCoco(g, b);
		}
		//Yagolpeo indica si ya hiso daño
		//huboColiicon nos indica si hay contacto
		// Colisiones
		for (int i = cocos.size() - 1; i >= 0; i--) {
			bool huboColision = false;
			for (int j = aranias.size() - 1; j >= 0; j--) {

				if (cocos[i]->getRectangleCoco().IntersectsWith(aranias[j]->getRectangleArania())) {
					huboColision = true;
					
					if (!cocos[i]->getYaGolpeo()) {

						if (cocos[i]->getTipo() == 1) {  // explosivo
							explosivo = true;
							aranias[j]->setVida(aranias[j]->getVida() - 3);
							g->DrawImage(explocion, cocos[i]->getX(), cocos[i]->getY() - 20,explocion->Width * 0.3, explocion->Height * 0.3);
							cocos[i]->setActivo(false);
						}
						else { // normal
							normal = true;
							aranias[j]->setVida(aranias[j]->getVida() - 1);
						}

						cocos[i]->setCambiar(true);
						cocos[i]->setYaGolpeo(true);

						if (aranias[j]->getVida() <= 0) {
							delete aranias[j];
							aranias.erase(aranias.begin() + j);
						}
					}

					break; 
				}
				if (!huboColision) {
					cocos[i]->setYaGolpeo(false);
				}
			}

		}
	}

	void setNormal(bool xd) { normal = xd; }
	bool getNormal() { return normal; }

	void setExplosion(bool xd) { explosivo = xd; }
	bool getExplosivo() { return explosivo; }

	bool getVictoria() { return victoria; }
	bool getDerrota() { return derrota; }
	Principal* getJugador() {
		return jugador;
	}


};
