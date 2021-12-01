#pragma once
#include "pointss.h"
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class boule :
    public pointss
{
private:
    int _radius;
    sf::CircleShape _projection;
    int _XP;
    int _YP;
    sf::Color _color;
    float _Vx;
    float _Vy;
    float _Ax;
    float _Ay;

public:
    boule(float r, sf::CircleShape p, int xp, int yp, sf::Color c, pointss yes); //float vx, float vy, float ax, float ay, 
    int radius();
    void radius(int r);
    sf::CircleShape projection();
    void projection(sf::CircleShape shape);
    int XP();
    void XP(int new_xp);
    int YP();
    void YP(int new_yp);
    sf::Color color();
    void color(sf::Color new_c);
    float Vx();
    void Vx(float new_vx);
    float Vy();
    void Vy(float new_vy);
    float Ax();
    void Ax(float new_ax);
    float Ay();
    void Ay(float new_ay);

    void move();
};

