#pragma once
#include "Principal.h"

class ControladorHistoria3_parte3
{
private:
	Principal* jugador;
public:
	ControladorHistoria3_parte3() 
	{
		jugador = new Principal(500, 600);
	};
	~ControladorHistoria3_parte3() 
	{

	};

	Principal* getJugador() {
		return jugador;
	}


	void colisionObjetos(Graphics^ g, Rectangle obst)
	{
		Rectangle rectPers = jugador->getRectanglePrincipal();
		Rectangle jugadorRect = jugador->getRectanglePrincipal();

		if (!jugadorRect.IntersectsWith(obst))
			return;

		// Retroceder según la dirección
		if (jugador->getDX() > 0) // derecha
			jugador->setX(obst.Left - jugadorRect.Width);

		if (jugador->getDX() < 0) // izquierda
			jugador->setX(obst.Right);

		if (jugador->getDY() > 0) // abajo
			jugador->setY(obst.Top - jugadorRect.Height);

		if (jugador->getDY() < 0) // arriba
			jugador->setY(obst.Bottom);

	}



	void controlador(Graphics^ g, Bitmap^ b, Rectangle e, Rectangle r, Rectangle t)
	{
		jugador->moverPrincipal(g, b);
		colisionObjetos(g, e);
		colisionObjetos(g, r);
		colisionObjetos(g, t);
	}


};
