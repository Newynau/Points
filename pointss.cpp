#include "pointss.h"

pointss::pointss()
{
	this->_x = 0;
	this->_y = 0;
	this->_id = 0;
}

pointss::pointss(int id)
{
	this->_id = id;
	this->_x = 0;
	this->_y = 0;
}

pointss::pointss(int x, int y)
{
	this->_x = x;
	this->_y = y;
	this->_id = 0;
}

pointss::pointss(int x, int y, int id)
{
	this->_x = x;
	this->_y = y;
	this->_id = id;
}

int pointss::X()
{
	return this->_x;
}

void pointss::X(int x)
{
	this->_x = x;
}

int pointss::Y()
{
	return this->_y;
}

void pointss::Y(int y)
{
	this->_y = y;
}

int pointss::Id()
{
	return this->_id;
}

void pointss::Id(int id)
{
	this->_id = id;
}