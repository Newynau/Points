#include "boule.h"
#include <random>

boule::boule(float r, sf::CircleShape p, int xp, int yp, sf::Color c, pointss yes) //float vx, float vy, float ax, float ay, 
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(-3, 3);

	this->_radius = r;
	this->_projection = p;
	this->_XP = xp;
	this->_YP = yp;
	this->_color = c;

	this->Id(yes.Id());
	this->X(yes.X());
	this->Y(yes.Y());

	this->_Vx = distrib(gen);
	this->_Vy = distrib(gen);
}


int boule::radius()
{
	return this->_radius;
}

void boule::radius(int r)
{
	this->_radius = r;
}

sf::CircleShape boule::projection()
{
	return this->_projection;
}

void boule::projection(sf::CircleShape shape)
{
	this->_projection = shape;
}

int boule::XP()
{
	return this->_XP;
}

void boule::XP(int new_xp)
{
	this->_XP = new_xp;
}

int boule::YP()
{
	return this->_YP;
}

void boule::YP(int new_yp)
{
	this->_YP = new_yp;
}

sf::Color boule::color()
{
	return this->_color;
}

void boule::color(sf::Color new_c)
{
	this->_color = new_c;
}

float boule::Vx()
{
	return this->_Vx;
}

void boule::Vx(float new_vx)
{
	this->_Vx = new_vx;
}

float boule::Vy()
{
	return this->_Vy;
}

void boule::Vy(float new_vy)
{
	this->_Vy = new_vy;
}

float boule::Ax()
{
	return this->_Ax;
}

void boule::Ax(float new_ax)
{
	this->_Ax = new_ax;
}

float boule::Ay()
{
	return this->_Ay;
}

void boule::Ay(float new_ay)
{
	this->_Ay = new_ay;
}

void boule::move()
{
	float tempx = this->_XP + this->_Vx;
	float tempy = this->_YP + this->_Vy;

	if (tempx > 850) {
		this->_XP = 850 - (tempx - 850);
		this->_Vx = this->_Vx * -1;
	}
	else if (tempx < 50) {
		this->_XP = 50 + (50 - tempx);
		this->_Vx = this->_Vx * -1;
	}
	else {
		this->_XP = tempx;
	}

	if (tempy > 850) {
		this->_YP = 850 + (850 - tempy);
		this->_Vy = this->_Vy * -1;
	}
	else if (tempy < 50) {
		this->_YP = 50 + (50 - tempy);
		this->_Vy = this->_Vy * -1;
	}
	else {
		this->_YP = tempy;
	}

	
	this->_projection.setPosition(this->_XP, this->_YP);
	
}
