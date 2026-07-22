#pragma once
#include "Principal.h"
#include "Balas.h"
#include "Enemigo.h"
#include "chip.h"
#include "Archivos.h"
class Controlador1 {
private:
    Principal* jugador;
    vector<Soldado*> soldados;
    vector<chip*> chips;
    vector<Acechador*> acechadores;
    //Vector que guarda las posiciones de los chips
    vector<pair<int, int>> parametros;
    //Cantidad de chips recolectados por el jugador
    bool sonidoExplosion;
    bool sonidoChip;
    int N;
public:
    Controlador1() {
        CrearArchivoParametros();
        vector<pair<int, int>> parametros = LeerParametros();
        sonidoExplosion = false;
        sonidoChip = false;
        jugador = new Principal(200, 200);
        //Chips
        for (int i = 0; i < parametros.size(); i++) {
            int x = parametros[i].first;
            int y = parametros[i].second;
            chips.push_back(new chip(x, y));
        }
        N = 0;
    }

    ~Controlador1() {
        delete jugador;

        for (int i = 0; i < soldados.size(); i++) {
            delete soldados[i];
        }
        soldados.clear();
        for (int j = 0; j < chips.size(); j++) {
            delete chips[j];
        }
        chips.clear();
        for (int i = 0; i < acechadores.size(); i++) {
            delete acechadores[i];
        }
        acechadores.clear();
    }

    //Agregar soldados (Random)
    void AgregarSoldado(Graphics^ g) {
        Random r;
        int rand = r.Next(0, 120);
        if (rand == 50) {
            Soldado* s = new Soldado(100, 0);
            soldados.push_back(s);
        }
    }
    void AgregarAcechador(Graphics^ g) {
        Random r;
        int rand = r.Next(0, 130);
        if (rand == 50) {
            Acechador* a = new Acechador(650, 0);
            acechadores.push_back(a);
        }
    }
    void dibujarChips(Graphics^ g, Bitmap^ b) {
        for (int i = 0; i < chips.size(); i++) {
            chips[i]->dibujar(g, b);
        }
    }
    //Control Acechadores
    void ControlAcechadores(Graphics^ g, Bitmap^ b) {
        for (int i = 0; i < acechadores.size(); i++) {
            acechadores[i]->mover(jugador->getX(), jugador->getY(), g, b);
        }
    }

    //Control Soldados
    void ControlSoldados(Graphics^ g, Bitmap^ b, Bitmap^ ba) {
        Random r;

        for (int i = 0; i < soldados.size(); i++) {
            soldados[i]->mover(jugador->getX(), jugador->getY(), g, b);
            soldados[i]->disparar(r.Next(1, 50), 0);
            soldados[i]->ControlBalas(g, ba, ba, ba);
        }
    }

    //Control Jugador
    void ControlPrincipal(Graphics^ g, Bitmap^ b, Bitmap^ ba) {
        jugador->moverPrincipal(g, b);
        jugador->ControlBalas(g, ba);
    }

    //Coliciones======================================================================================
    void ControlColisiones(Graphics^ g, bool teclaE_Presionada, Bitmap^ explocion) {
        //Balas jugador - Soldados
        for (int i = jugador->getBalas().size() - 1; i >= 0; i--) {
            for (int j = soldados.size() - 1; j >= 0; j--) {

                if (jugador->getBalas()[i]->getRectangleBala().IntersectsWith(soldados[j]->getRectangleEnemigo())) {
                    //Desactivamos la bala
                    jugador->getBalas()[i]->setActiva(false);
                    //Quitamos vida al soldado
                    soldados[j]->setVida(soldados[j]->getVida() - 1);
                    //Evaluamos a los soldados muertos
                    if (soldados[j]->getVida() <= 0) {
                        delete soldados[j];
                        soldados.erase(soldados.begin() + j);
                    }
                    //Salimos el for 
                    break;
                }
            }
        }
        //Balas soldado - jugador
        for (int i = 0; i < soldados.size(); i++) {
            for (int j = 0; j < soldados[i]->getBalas().size(); j++) {
                if (soldados[i]->getBalas()[j]->getRectangleBala().IntersectsWith(jugador->getRectanglePrincipal())) {
                    soldados[i]->getBalas()[j]->setActiva(false);
                    jugador->setVida(jugador->getVida() - 1);
                }
            }
        }
        //Balas jugador - Acechador
        for (int i = jugador->getBalas().size() - 1; i >= 0; i--) {
            for (int j = acechadores.size() - 1; j >= 0; j--) {

                if (jugador->getBalas()[i]->getRectangleBala().IntersectsWith(acechadores[j]->getRectangleEnemigo())) {
                    //Desactivamos la bala
                    jugador->getBalas()[i]->setActiva(false);
                    //Quitamos vida al soldado
                    acechadores[j]->setVida(acechadores[j]->getVida() - 1);
                    //Evaluamos a los soldados muertos
                    if (acechadores[j]->getVida() <= 0) {
                        delete acechadores[j];
                        acechadores.erase(acechadores.begin() + j);
                    }
                    //Salimos el for 
                    break;
                }
            }
        }
        //Jugador - Chips

        for (int i = 0; i < chips.size(); i++) {
            if (jugador->getRectanglePrincipal().IntersectsWith(chips[i]->getRectangleChip())) {
                chips[i]->ControlColicion(teclaE_Presionada);
                if (chips[i]->getContador() >= 2000) {
                    chips[i]->setActivo(false);

                    sonidoChip = true;
                    delete chips[i];
                    chips.erase(chips.begin() + i);
                    N++;
                    i--;
                }
            }
        }
        //Jugador - Acechador
        for (int i = 0; i < acechadores.size(); i++) {
            if (jugador->getRectanglePrincipal().IntersectsWith(acechadores[i]->getRectangleEnemigo())) {
                //se activa el sonido
                sonidoExplosion = true;
                delete acechadores[i];
                acechadores.erase(acechadores.begin() + i);
                g->DrawImage(explocion, jugador->getX(), jugador->getY(), explocion->Width * 0.3, explocion->Height * 0.3);
                i--;
                jugador->setVida(jugador->getVida() - 2);
            }
        }



    }
    void setsonidoExplosion(bool xd) { sonidoExplosion = xd; }
    bool getsonidosExplosion() { return sonidoExplosion; }
    void setsonidoChip(bool xd) { sonidoChip = xd; }
    bool getsonidosChip() { return sonidoChip; }
    Principal* getJugador() {
        return jugador;
    }
    vector<chip*>& getChips() {
        return chips;
    }
    vector<Soldado*>& getSoldados() {
        return soldados;
    }
};