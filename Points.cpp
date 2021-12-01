#include <iostream>
#include <fstream>
#include <string>
#include "pointss.h"
#include <sstream>
#include <vector>
#include "pointss.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include "boule.h"


using namespace std;
using namespace sf;

void displaying(RenderWindow& window, vector<boule>& boules, Clock& clock, string buff, Time oldelpaso);

void fillVector(vector<pointss> tab, vector<CircleShape>& circles, vector<boule>& boules) {
	//fill
	int S = tab.size();
	CircleShape temp;
	for (int j = 0; j < S; j++) {
		int x = tab[j].X();
		int y = tab[j].Y();
		float _x = x / 10;
		float _y = y / 10;
		_x += 50;
		_y += 50;
		temp.setPosition(_x, _y);
		temp.setRadius(5.f);
		temp.setFillColor(Color::Red);
		circles.push_back(temp);

		boule temp2(temp.getRadius(), temp, _x, _y, temp.getFillColor(), tab[j]);
		boules.push_back(temp2);
	}
}

void drawPoints(vector<boule> boules) {
	Clock clock;

	RenderWindow window(VideoMode(1000, 900), "SFML works!");
	bool isFocused = true;

	Time elapsedDuringNonFocus;
	elapsedDuringNonFocus = seconds(0.0f);

	Text ouiahah;
	string str;
	bool ui = false;
	

	while (window.isOpen())
	{
		Event event;
		
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case Event::Closed:
				window.close();
				break;
			case Event::LostFocus:
				cout << "lost focus" << endl;
				isFocused = false;
				
				break;
			case Event::GainedFocus:
				cout << "gained focuz" << endl;
				isFocused = true;
				
				break;
			case sf::Event::TextEntered:
				if (event.text.unicode < 128)
				{
					if (isFocused) {
						str += static_cast<char>(event.text.unicode);
						ouiahah.setString(str);
					}
				}
				cout << str << endl;
				break;
			default:
				break;
			}

		}


		if (isFocused == true) {
			displaying(window, boules, clock, str, elapsedDuringNonFocus);
		}
		else {

			elapsedDuringNonFocus = clock.getElapsedTime();
		}

		
	}

}

void displaying(RenderWindow& window, vector<boule>& boules, Clock& clock, string buff, Time oldelpaso){
	window.clear();

	RectangleShape rectangle(Vector2f(800, 800));

	rectangle.setFillColor(Color::Black);

	rectangle.setPosition(50, 50);
	rectangle.setOutlineThickness(5);
	rectangle.setOutlineColor(Color(180, 185, 194));

	window.draw(rectangle);
	///////


	RectangleShape timeRectangle(Vector2f(150, 70));
	timeRectangle.setFillColor(Color::White);
	timeRectangle.setPosition(900, 0);

	window.draw(timeRectangle);



	//put circle in oui
	int _S = boules.size();
	for (int i = 0; i < _S; i++) {
		window.draw(boules[i].projection());
	}


	Font font;
	font.loadFromFile("D:\\CPPprojects\\Points\\Debug\\arial.ttf");

	Text text;

	Time elapsed = clock.getElapsedTime();
	elapsed -= oldelpaso;


	float supercool = round(elapsed.asSeconds() * 100) / 100;

	string encore = to_string(supercool);

	text.setString(encore.substr(0, 5));

	text.setFont(font);

	text.setFillColor(Color::Black);

	text.setCharacterSize(20);

	text.setPosition(905, 10);

	Text buffd;
	buffd.setString(buff);
	buffd.setFont(font);
	buffd.setFillColor(Color::Black);
	buffd.setCharacterSize(20);
	buffd.setPosition(905, 30);

	

	window.draw(buffd);
	window.draw(text);


	window.display();

	for (int i = 0; i < _S; i++) {
		boules[i].move();

		for (int j = 0; j < _S; j++) {
			if ((boules[i].XP() == boules[j].XP() || boules[i].XP() == (boules[j].XP() + boules[j].radius()) || boules[i].XP() == (boules[j].XP() - boules[j].radius())) && (boules[i].YP() == boules[j].YP() || boules[i].YP() == (boules[j].YP() + boules[j].radius()) || boules[i].YP() == (boules[j].YP() - boules[j].radius()))) {
				boules[i].Vx(boules[i].Vx() * -1);
				boules[i].Vy(boules[i].Vy() * -1);

				boules[j].Vx(boules[i].Vx() * -1);
				boules[j].Vy(boules[j].Vy() * -1);
			}
		}
	}
}

int main()
{
	int count = 0;
	vector<pointss> points;
	vector<CircleShape> circles;
	vector<boule> boules;

	std::ifstream file;
	std::string line;
	file.open("initial.txt");


	if (file.is_open())
	{
		while (file)
		{
			std::getline(file, line);

			string delimiter = ";";

			string token;
			int place = 0;
			pointss temp;


			token = line.substr(0, line.find(delimiter));

			place = atoi(token.c_str());
			
			
			line.erase(0, line.find(delimiter) + delimiter.length());


			token = line.substr(0, line.find(delimiter));
			int x = atoi(token.c_str());
			
				
			

			line.erase(0, line.find(delimiter) + delimiter.length());
			token = line.substr(0, line.find(delimiter));
			int y = atoi(token.c_str());
			line.erase(0, line.find(delimiter) + delimiter.length());

			temp.Id(place);
			temp.X(x);
			temp.Y(y);

			points.insert(points.begin() + place, temp);
	

		};
	}
	else {
		std::cout << "Couldn't open file\n";
	}
	file.close();

	fillVector(points, circles, boules);
	drawPoints(boules);








	//file.open("move1.txt");

	//if (file.is_open())
	//{
	//	while (file)
	//	{
	//		std::getline(file, line);

	//		string delimiter = ";";

	//		string token;
	//		int place = 0;

	//		//id
	//		token = line.substr(0, line.find(delimiter));
	//		place = atoi(token.c_str());
	//		line.erase(0, line.find(delimiter) + delimiter.length());

	//		//x
	//		token = line.substr(0, line.find(delimiter));
	//		int temp = atoi(token.c_str());
	//		int x = points[place].X();
	//		if (x + temp > 8000) {
	//			x = 8000 + (8000 - x + temp);
	//			points[place].X(x);
	//		}
	//		else {
	//			points[place].X(x + temp);
	//		}

	//		line.erase(0, line.find(delimiter) + delimiter.length());
	//		//y
	//		token = line.substr(0, line.find(delimiter));
	//		temp = atoi(token.c_str());
	//		int y = points[place].Y();
	//		if (y + temp > 8000) {
	//			y = 8000 + (8000 - y + temp);
	//			points[place].Y(y);
	//		}
	//		else {
	//			points[place].Y(y + temp);
	//		}
	//		line.erase(0, line.find(delimiter) + delimiter.length());
	//	}
	//}
	//else {
	//	std::cout << "Couldn't open file\n";
	//}
	//file.close();


	return 0;
}