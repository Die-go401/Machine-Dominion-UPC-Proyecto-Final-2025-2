#pragma once
using namespace System;
using namespace System::Drawing;
enum Direcciones {
    Arriba,
    Abajo,
    Derecha,
    Izquierda,
    Ninguna
};
class bala {
private:
    int x, y, alto, ancho;
    int dx, dy;
    bool activa;
    int iteraX, iteraY;
    int tipo; // 0 = normal, 1 = Bola fuego o hielo

public:

    //Constructor con tipo (bala de fuego)
    bala(int x, int y, int dir, int tipo) {
        this->x = x;
        this->y = y;

        if (dir == 0) { dx = 0; dy = -10; }
        else if (dir == 1) { dx = 0; dy = +10; }
        else if (dir == 2) { dx = +10; dy = 0; }
        else if (dir == 3) { dx = -10; dy = 0; }

        iteraX = iteraY = 0;
        ancho = alto = 0;
        activa = true;
        this->tipo = tipo;
    }

    //Constructor bala normal
    bala(int x, int y, int dir) {
        this->x = x;
        this->y = y;

        if (dir == 0) { dx = 0; dy = -10; }
        else if (dir == 1) { dx = 0; dy = +10; }
        else if (dir == 2) { dx = +10; dy = 0; }
        else if (dir == 3) { dx = -10; dy = 0; }

        iteraX = iteraY = 0;
        ancho = alto = 0;
        activa = true;
        tipo = 0;
    }
    //Constructor para ataque especial 1
    bala(int x, int y, int dx, int dy, int itera) {
        this->x = x;
        this->y = y;
        this->dx = dx;
        this->dy = dy;
        iteraX = iteraY = itera;
        ancho = alto = 0;
        activa = true;
        tipo = 0;
    }

    ~bala() {}

    int getTipo() { return tipo; }
    int get_Xbala() { return x; }
    int get_Ybala() { return y; }
    bool getActiva() { return activa; }
    void setActiva(bool a) { activa = a; }

    void mover(Graphics^ g, Bitmap^ bala_normal, Bitmap^ bola_fuego, Bitmap^ bola_hielo) {
        iteraX++;
        if (iteraX > 3) {
            iteraX = 0;
        }

        x += dx;
        y += dy;

        if (x < 0 || x > g->VisibleClipBounds.Width ||
            y < 0 || y > g->VisibleClipBounds.Height)
        {
            activa = false;
            return;
        }

        if (tipo == 0) {
            dibujar(g, bala_normal);
        }
        else if (tipo == 1) {
            dibujar_Boladefuego(g, bola_fuego);
        }
        else if (tipo == 2) {
            dibujar_Boladehielo(g, bola_hielo);
        }

    }

    void dibujar(Graphics^ g, Bitmap^ b) {
        ancho = b->Width / 4;
        alto = b->Height;

        Rectangle sprite(iteraX * ancho, 0, ancho, alto);
        Rectangle zoom(x, y, ancho, alto);

        g->DrawImage(b, zoom, sprite, GraphicsUnit::Pixel);
    }

    void dibujar_Boladefuego(Graphics^ g, Bitmap^ b) {
        ancho = b->Width / 4;
        alto = b->Height;

        Rectangle sprite(iteraX * ancho, 0, ancho, alto);
        Rectangle zoom(x, y, ancho * 5, alto * 5);

        g->DrawImage(b, zoom, sprite, GraphicsUnit::Pixel);
    }
    void dibujar_Boladehielo(Graphics^ g, Bitmap^ b) {
        ancho = b->Width / 4;
        alto = b->Height;

        Rectangle sprite(iteraX * ancho, 0, ancho, alto);
        Rectangle zoom(x, y, ancho, alto);

        g->DrawImage(b, zoom, sprite, GraphicsUnit::Pixel);
    }
    Rectangle getRectangleBala() {
        return Rectangle(x, y, ancho, alto);
    }

    Rectangle getRectangleBolaFuego() {
        return Rectangle(x, y, ancho * 5, alto * 5);
    }

    Rectangle getRectangleBolaHielo() {
        return Rectangle(x, y, ancho, alto);
    }
};