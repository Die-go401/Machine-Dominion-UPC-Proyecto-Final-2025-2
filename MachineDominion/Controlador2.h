#pragma once
#include "Enemigo.h"
#include "Principal.h"
#include "Balas.h"
#include "Arbol.h"
class Controlador2 {
private:
    vector <arania*> aranias;
    vector<Arbol*> arboles;
    Principal* jugador;
    int puntos;
    int total;
public:
    //Vector posiciones 
    vector<pair<int, int>> posiciones = {
     {120,100}, {240,100}, {370,100}, {500,100}, {640,100},
    {120,300}, {240,300}, {370,300}, {500,300}, {640,300},
    {120,500}, {240,500}, {370,500}, {500,500}, {640,500}
    };
    Controlador2() {
        jugador = new Principal(60, 100);
        Random r;
        //Creamos los arboles
        for (int i = 0; i < posiciones.size(); i++) {
            //Declaramos una variable de tipo pair<int,int>
            pair<int, int> pos = posiciones[i];
            int x = pos.first;
            int y = pos.second;
            //Random
            int tipo = r.Next(0, 3);  //1 - Desidratado ; 0 - Navidad
            if (tipo == 0 || tipo == 2) {
                Arbol* a = new ArbolDesidratado(x, y);
                arboles.push_back(a);
            }
            else {
                Arbol* a = new ArbolNavidad(x, y);
                arboles.push_back(a);
            }
        }

        //Arañas
        aranias.push_back(new arania(190, 0, 15));
        aranias.push_back(new arania(435, 0, 15));
        aranias.push_back(new arania(310, 700, -15));
        aranias.push_back(new arania(575, 700, -15));
        //Inicializamos los atributos total y puntos
        total = 0;
        for (int i = 0; i < arboles.size(); i++) {
            if (arboles[i]->getTipo() == 1) {
                total++;
            }
        }
        puntos = 0;
    }

    ~Controlador2() {
        for (int i = 0; i < arboles.size(); i++) {
            delete arboles[i];
        }
        arboles.clear();
        for (int i = 0; i < aranias.size(); i++) {
            delete aranias[i];
        }
        aranias.clear();
        delete jugador;
    
    }

    //Dibujar Arboles
    void dibujarArboles(Graphics^ g, Bitmap^ arbol1, Bitmap^ arbol2){
        for (int i = 0; i < arboles.size(); i++){
            if (arboles[i]->getTipo() == 0) { //ArbolNavidad
                arboles[i]->dibujarArbol(g, arbol1);
            }
            else if (arboles[i]->getTipo() == 1) { //ArbolDesidratado
                arboles[i]->dibujarArbol(g, arbol2);
            }
        }
    }
    //================================================================================================
    //Coliciones Araña - jugador
    void colisionConAranias() {
        for (int i = 0; i < aranias.size(); i++) {
            if (jugador->getRectanglePrincipal().IntersectsWith(aranias[i]->getRectangleArania())) {
                jugador->setVida(jugador->getVida() - 1);

                jugador->setX(80);
                jugador->setY(100);

               
                jugador->setDX(0);
                jugador->setDY(0);

                break;
            }
        }
    }
    void colisionLimites(Graphics^ g, Rectangle num1, Rectangle num2, Rectangle num3, Rectangle num4) {
       //Verificamos las coliciones con el jugador
        if (jugador->getRectanglePrincipal().IntersectsWith(num1))
            jugador->setY(num1.Bottom);

        
        if (jugador->getRectanglePrincipal().IntersectsWith(num2))
            jugador->setX(num2.Right);

        
        if (jugador->getRectanglePrincipal().IntersectsWith(num3))
            jugador->setY(num3.Top - jugador->getAlto() - 15);

       
        if (jugador->getRectanglePrincipal().IntersectsWith(num4))
            jugador->setX(num4.Left - jugador->getAncho()- 15);
        //Verificamos las coliciones con las arañas - Mover arañas
        for (int i = 0; i < aranias.size(); i++) {
            if (aranias[i]->getRectangleArania().IntersectsWith(num1)) {
                aranias[i]->setY(num1.Bottom);
                aranias[i]->setDY(15);
            }
                
             

            if (aranias[i]->getRectangleArania().IntersectsWith(num3)) {
                aranias[i]->setY(num3.Top - aranias[i]->getAlto() - 20);
                aranias[i]->setDY(-15);
            }
             
        }
    }

    void colisionArboles(Graphics^ g) {
        for (int i = 0; i < arboles.size(); i++) {
            if (arboles[i]->getTipo() == 1) {
                if (jugador->getRectanglePrincipal().IntersectsWith(arboles[i]->getRectangleArbol()))
                {
                    if (jugador->getDX() == -10) // izquierda
                        jugador->setX(arboles[i]->getRectangleArbol().Right);

                    if (jugador->getDX() == 10) // derecha
                        jugador->setX(arboles[i]->getRectangleArbol().Left - jugador->getRectanglePrincipal().Width);

                    if (jugador->getDY() == -10) // arriba
                        jugador->setY(arboles[i]->getRectangleArbol().Bottom);

                    if (jugador->getDY() == 10) // abajo
                        jugador->setY(arboles[i]->getRectangleArbol().Top - jugador->getRectanglePrincipal().Height);
                }


            }
            else {
                if (jugador->getRectanglePrincipal().IntersectsWith(arboles[i]->getRectangleArbol()))
                {
                    if (jugador->getDX() == -10) // izquierda
                        jugador->setX(arboles[i]->getRectangleArbol().Right);

                    if (jugador->getDX() == 10) // derecha
                        jugador->setX(arboles[i]->getRectangleArbol().Left - jugador->getRectanglePrincipal().Width);

                    if (jugador->getDY() == -10) // arriba
                        jugador->setY(arboles[i]->getRectangleArbol().Bottom);

                    if (jugador->getDY() == 10) // abajo
                        jugador->setY(arboles[i]->getRectangleArbol().Top - jugador->getRectanglePrincipal().Height);
                }
            }
        }
    }
  
    void ControlMundo2(Graphics^ g, Bitmap^ b,
        Rectangle num1, Rectangle num2, Rectangle num3, Rectangle num4,
        Bitmap^ img_arbol1, Bitmap^ img_arbol2, Bitmap^ arania)
    {
        dibujarArboles(g, img_arbol1, img_arbol2);
        colisionArboles(g);
        colisionLimites(g, num1, num2, num3, num4);
        jugador->moverPrincipal(g,b);
        EvaluarPuntos();
        for (int i = 0; i < aranias.size(); i++) {
            aranias[i]->moverArania(g,arania);
        }
        colisionConAranias();


    }
    Principal* getJugador() {
        return jugador;
    }
    vector<Arbol*>& getArboles() {
        return arboles;
    }
    void EvaluarPuntos() {
        int contador = 0;
        for (int i = 0; i < arboles.size(); i++) {
            if (arboles[i]->getTipo() == 1 && arboles[i]->getIteraX() == 3) {
                contador++;
            }
           
        }
        puntos = contador;
    }
    bool victoria() {
      
      if (puntos == total) {
         return true;
      }
        
      return false;
    }

    int getTotal() { return total; }
    int getPuntos() { return puntos; }
};