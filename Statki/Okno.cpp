#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Klasy.h"
#include "Field.h"
#include "Funkcje.h"
#include "Statki.h"
#include "Flota.h"
#include "Okno.h"

using namespace std;


fleet poczatek(int size, sf::Font font, sf::RenderWindow& window)
{
	Battleship Battleship_model{};
	Cruiser Cruiser_model{};
	Destroyer Destroyer_model{};
	Patrol_Boat Patrol_Boat_model{};
	window.create(sf::VideoMode(400, 500), "Poczatek", sf::Style::Close);

	int Battleship_amount = 1;
	int Cruiser_amount = 2;
	int Destroyer_amount = 3;
	int Patrol_Boat_amount = 4;

	string temp = to_string(Patrol_Boat_amount);
	sf::Text number;

	number.setFont(font);
	number.setString(temp);
	number.setPosition(320, 80);
	sf::Text instrukcja;
	instrukcja.setFont(font);
	instrukcja.setString("Ustaw ilosc statkow");
	sf::Text plus;
	plus.setFont(font);
	plus.setString("+");
	plus.setPosition(360, 80);
	sf::Text minus;
	minus.setFont(font);
	minus.setString("-");
	minus.setPosition(300, 80);
	instrukcja.setPosition(20, 20);
	Battleship_model.Set_Position(20, 260);
	Cruiser_model.Set_Position(20, 200);
	Destroyer_model.Set_Position(20, 140);
	Patrol_Boat_model.Set_Position(20, 80);
	window.requestFocus();
	while (window.isOpen())
	{
		sf::Event event;
		sf::Vector2i localPosition = sf::Mouse::getPosition(window);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		    else if (event.type == event.MouseButtonReleased)
			{
				localPosition = sf::Mouse::getPosition(window);
				if (localPosition.x > 360 && localPosition.x < 380 && localPosition.y>80 && localPosition.y<120 && Patrol_Boat_amount<99)
				{
					Patrol_Boat_amount++;
					temp = to_string(Patrol_Boat_amount);
					number.setString(temp);
				}
				if (localPosition.x > 300 && localPosition.x < 320 && localPosition.y>80 && localPosition.y < 120 && Patrol_Boat_amount > 0)
				{
					Patrol_Boat_amount--; 
					temp = to_string(Patrol_Boat_amount);
					number.setString(temp);
				}
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Left)
				{
					fleet flota(Patrol_Boat_amount, Patrol_Boat_amount, Patrol_Boat_amount, Patrol_Boat_amount);
					if (flota.check_if_possible(size) == true)
						return flota;
					else cout << "Za duzo statkow";
				}
			}
		}
		window.clear();
		window.draw(instrukcja);
		Battleship_model.draw_ship(window);
		Cruiser_model.draw_ship(window);
		Destroyer_model.draw_ship(window);
		Patrol_Boat_model.draw_ship(window);
		window.draw(plus);
		window.draw(minus);
		window.draw(number);
		window.display();
	}
}