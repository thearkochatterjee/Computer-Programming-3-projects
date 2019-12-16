// sfml lab
// programmer: arko chatterjee
//
// purpose: draw shapes using sfml

#include <SFML/Graphics.hpp>
#include <iostream>
#include "dshape.h"
using namespace std;

int main()
{
	int ans;
	int nums;
	float dis[20];
	float area;
	dshape s;
	cout << "Do you want to use a regular shape or a custom shape?\n";
	cout << "1 - Regular\n";
	cout << "2 - Custom\n";
	cin >> ans;
	if (ans == 1)
	{
		char ch;
		cout << "How many sides would you like to include?\n";
		cin >> nums;
		cout << "Would you like to draw it?\n";
		cin >> ch;
		if (ch == 'y')
		{
			double x[5];
			double y[5];
			int i;
			i = 1;
			sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML Lab");
			sf::ConvexShape shape;
			shape.setFillColor(sf::Color::Cyan);
			while (window.isOpen())
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					switch (event.type)
					{
					case sf::Event::Closed:
						window.close();
						break;
					case sf::Event::MouseButtonPressed:
						switch (event.key.code)
						{
						case sf::Mouse::Left:
							if (i < 3)
							{
								x[i] = event.mouseButton.x;
								y[i] = event.mouseButton.y;
								i++;
							}
							else
							{
								shape.setPointCount(4);
								y[3] = y[2];
								x[3] = x[2];
								y[2] = y[1];
								x[2] = x[3];
								x[4] = x[1];
								y[4] = y[3];
								for (int i = 1; i <= 4; i++)
								{
									cout << x[i] << " , " << y[i] << endl;
									shape.setPoint(i - 1, sf::Vector2f(x[i], y[i]));
								}
								s.setpoints(x, y);
								s.findarea();
								s.finddis();
								s.findper();
								cout << s.tostring();
								i = 1;
							}
							break;
						}
						break;
					}
				}
				window.clear();
				window.draw(shape);
				window.display();
			}
		}
		else
		{
			int size;
			cout << "What size would you like it?\n";
			cin >> size;
			sf::CircleShape regshape(size, nums);
			regshape.setFillColor(sf::Color::Cyan);
			sf::RenderWindow window(sf::VideoMode(size * 2, size * 2), "SFML Lab");
			while (window.isOpen())
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					switch (event.type)
					{

					case sf::Event::Closed:
						window.close();
						break;
					}
				}
				window.clear();
				window.draw(regshape);
				window.display();
			}
		}
		
	}
	else
	{
		sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML Lab");
		sf::ConvexShape shape;
		shape.setFillColor(sf::Color::Cyan);
		double x[5];
		double y[5];
		float temp;
		int i;
		i = 0;
		shape.setPointCount(4);
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::MouseButtonPressed:
					switch (event.key.code)
					{
					case sf::Mouse::Left:
						if (i < 5)
						{
							x[i] = event.mouseButton.x;
							y[i] = event.mouseButton.y;
							i++;
						}
						else
						{
							for (int i = 1; i <= 4; i++)
							{
								cout << x[i] << " , " << y[i] << endl;
								shape.setPoint(i - 1, sf::Vector2f(x[i], y[i]));
							}
							s.setpoints(x, y);
							s.findarea();
							s.finddis();
							s.findper();
							cout << s.tostring();

						}
						break;
					}
					break;
				}
			}
			window.clear();
			window.draw(shape);
			window.display();
		}
	}
	return 0;
}
