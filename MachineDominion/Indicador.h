#pragma once
using namespace System;
using namespace System::Drawing;

class circulo {
private:
    int x, y;
    int radio;
    int diametro;
    bool visible;  

public:


    circulo(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
        radio = 10;
        diametro = radio * 2;
        visible = false; 
    }


    ~circulo() {
    
    }

    void Dibujar(Graphics^ g, int contador) {
        if (!visible) return;
        int quintos = contador / 400;   
        if (quintos > 5) quintos = 5;
        //Mejora el aspecto visual
        g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
        for (int i = 0; i < quintos; i++) {

            int anguloInicial = i * 72; 

            g->FillPie(Brushes::DarkGreen,x - radio,y - radio,diametro,diametro,anguloInicial,72);
        }
    }
    

    int getX() { return x; }
    int getY() { return y; }
    int getRadio() { return radio; }
    bool getVisible() { return visible; }
    void setX(int _x) { x = _x; }
    void setY(int _y) { y = _y; }
    void setRadio(int r) {
        radio = r;
        diametro = r * 2;
    }
    void setVisible(bool v) { visible = v; }
};