#pragma once
#include "Enemigo.h"
#include "Principal.h"
#include <vector>
using namespace std;
using namespace System;
using namespace System::Drawing;
class controlador3 {
private:
	Jefe* jefe;
	Principal* jugador;
	int contador;
	bool congelado;
	bool RayoDisparado;
public:
	controlador3() {
		jefe = new Jefe(400, 400);
		jugador = new Principal(0, 0);
		contador = 0;
		congelado = false;
		RayoDisparado = false;



	}
	~controlador3() {
		delete jefe;
		delete jugador;
	}
	void ControlGeneral(Graphics^ g, Bitmap^ jugador, Bitmap^ jefe, Bitmap^ jefe_furia, Bitmap^ soldados, Bitmap^ bala_jugador, Bitmap^ bala_enemigo, Bitmap^ bala_jefe, Bitmap^ bola_fuego, Bitmap^ bola_hielo, Bitmap^ dere, Bitmap^ izqui, Bitmap^ abajo, Bitmap^ arriba) {
		Random r;

		//Principal
		if (!congelado && this->jugador->getDisparandoRayo() == false) {
			this->jugador->moverPrincipal(g, jugador);
			this->jugador->ControlBalas(g, bala_jugador);
		}
		else {
			//Si esta congelado o esta disparando el rayo solo se dibuja no se mueve
			//DIBUJA AL JUGADOR Y AL RAYO
			this->jugador->dibujarPrincipal2(g, jugador, dere, izqui, abajo, arriba);
		}
		//Jefe y soldados
		if (this->jefe->getFuria() == false) {
			//Jefe
			this->jefe->mover(this->jugador->getX(), this->jugador->getY(), g, jefe);
			//Probabilidad de disparar y tipo 0
			this->jefe->disparar(r.Next(0, 50), 0);
			this->jefe->ControlBalas(g, bala_enemigo, bola_fuego, bola_hielo);
			this->jefe->AgregarSoldado(r.Next(0, 500));
			this->jefe->EliminarSoldado();


			//Soldados del vector
			this->jefe->ControlSoldados(this->jugador->getX(), this->jugador->getY(), g, soldados, bala_enemigo, r.Next(0, 100));
		}
		else if (this->jefe->getFuria() == true) {
			//Jefe
			this->jefe->mover(this->jugador->getX(), this->jugador->getY(), g, jefe_furia);
			//Probabilidad de disparar y tipo 1
			this->jefe->disparar(r.Next(0, 150), 1);
			_sleep(2);
			this->jefe->disparar(r.Next(0, 150), 2);
			this->jefe->ControlBalas(g, bala_jefe, bola_fuego, bola_hielo);
			this->jefe->AgregarSoldado(r.Next(0, 300));
			this->jefe->EliminarSoldado();


			//Soldados del vector
			this->jefe->ControlSoldados(this->jugador->getX(), this->jugador->getY(), g, soldados, bala_enemigo, r.Next(0, 80));

		}
		ControlColiciones();

	}
	void ControlColiciones() {
		// Balas del jugador contra el jefe
		for (int i = 0; i < jugador->getBalas().size(); i++) {
			if (jugador->getBalas()[i]->getRectangleBala().IntersectsWith(jefe->getRectangleEnemigo())) {
				jefe->setVida(jefe->getVida() - 1);
				delete jugador->getBalas()[i];
				jugador->getBalas().erase(jugador->getBalas().begin() + i);
				i--;
			}
		}

		//Balas del jugador contra soldados
		for (int i = 0; i < jefe->getSoldados().size(); i++) {
			for (int j = 0; j < jugador->getBalas().size(); j++) {
				if (jugador->getBalas()[j]->getRectangleBala().IntersectsWith(jefe->getSoldados()[i]->getRectangleEnemigo())) {

					jefe->getSoldados()[i]->setVida(jefe->getSoldados()[i]->getVida() - 1);

					delete jugador->getBalas()[j];
					jugador->getBalas().erase(jugador->getBalas().begin() + j);
					j--;

				}
			}
		}

		//Balas del jefe contra el jugador
		for (int i = 0; i < jefe->getBalas().size(); i++) {
			if (jefe->getBalas()[i]->getTipo() == 0) {
				if (jefe->getBalas()[i]->getRectangleBala().IntersectsWith(jugador->getRectanglePrincipal())) {
					jugador->setVida(jugador->getVida() - 1);

					delete jefe->getBalas()[i];
					jefe->getBalas().erase(jefe->getBalas().begin() + i);
					i--;
				}


			}
			else if (jefe->getBalas()[i]->getTipo() == 1) {
				if (jefe->getBalas()[i]->getRectangleBolaFuego().IntersectsWith(jugador->getRectanglePrincipal())) {
					jugador->setVida(jugador->getVida() - 2);

					delete jefe->getBalas()[i];
					jefe->getBalas().erase(jefe->getBalas().begin() + i);
					i--;
				}


			}
			else if (jefe->getBalas()[i]->getTipo() == 2) {
				if (jefe->getBalas()[i]->getRectangleBolaHielo().IntersectsWith(jugador->getRectanglePrincipal())) {
					//Congela al jugador
					congelado = true;
					delete jefe->getBalas()[i];
					jefe->getBalas().erase(jefe->getBalas().begin() + i);
					i--;
				}


			}

		}
		//Rayo - JEFE
		if (jugador->getDisparandoRayo() && jugador->getRayo() != nullptr) {
			if (jugador->getRayo()->getRectangleRayo().IntersectsWith(jefe->getRectangleEnemigo())) {
				//Eliminamos el rayo cuando toca el jefe
				jugador->getRayo()->setTerminado(true);
				jefe->setVida(jefe->getVida() - 35);
			}
		}
	}
	void ControlRafagaBalasJefe() {
		// ATAQUE A LOS 5 SEGUNDOS
		if (contador == 5000) {
			jefe->RafagaBalas2();


		}

		// ATAQUE A LOS 10 SEGUNDOS
		if (contador == 10000) {
			jefe->RafagaBalas3();
		}
		//Sumamos por el intervalo del timer
		contador += 100;
		//Reiniciamos
		if (contador > 11000) {
			contador = 0;
		}

	}
	Principal* getJugador() {
		return jugador;
	}
	Jefe* getJefe() {
		return jefe;
	}
	bool getCongelado() {
		return congelado;
	}
	void setCongelado(bool congelado) {
		this->congelado = congelado;
	}
	void setRayoDisparado(bool r) {
		RayoDisparado = r;
	}
	bool getRayoDisparado() {
		return RayoDisparado;
	}
};