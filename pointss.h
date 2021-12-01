#pragma once
class pointss
{
private:
	int _x;
	int _y;
	int _id;

public:
	pointss();
	pointss(int id);
	pointss(int x, int y);
	pointss(int x, int y, int id);
	int X();
	void X(int x);
	int Y();
	void Y(int y);
	int Id();
	void Id(int id);

};
