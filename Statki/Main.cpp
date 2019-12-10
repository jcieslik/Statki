#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Klasy.h"
#include "Field.h"
#include "Funkcje.h"
#include "Statki.h"
#include "Okno.h"
#include "Flota.h"


using namespace std;

int main()
{
	int size;
	cin >> size;
	gameboard pole(size);
	sf::RectangleShape rectangle(sf::Vector2f(40, 40));
	rectangle.setPosition(40, 40);
	sf::Text tekst;
	sf::Font font;
	sf::Color kolor(148, 198, 239);
	if (!font.loadFromFile("coolvetica rg.ttf"))
	{
		return 0;
	}
	sf::RenderWindow window;
	fleet flota = { 0, 0, 0, 0 };
	flota = poczatek(size, font, window);
	flota.create_fleet();
	window.create(sf::VideoMode(40 * (size + 2), 40 * (size + 2)), "Statki", sf::Style::Close);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyReleased)
			{
				int which;
				if (event.key.code == sf::Keyboard::Left)
				{
					which = 0;
					flota.vector_of_battleships[0].move(which, size);
				}
				if (event.key.code == sf::Keyboard::Right)
				{
					which = 1;
					flota.vector_of_battleships[0].move(which, size);
				}
				if (event.key.code == sf::Keyboard::Up)
				{
					which = 2;
					flota.vector_of_battleships[0].move(which, size);
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					which = 3;
					flota.vector_of_battleships[0].move(which, size);
				}
				if (event.key.code == sf::Keyboard::Space)
				{
					for (int i = 0; i < flota.vector_of_battleships.size(); i++)
						pole.find_field(flota.vector_of_battleships[0].get_position(i, 1) / default_ship_size, flota.vector_of_battleships[0].get_position(i, 0) / default_ship_size)->set_state(state_of_field::Taken);
				}
			}
		}
		window.clear();

		for (int i = 1; i <= size; i++)
		{
			for (int j = 1; j <= size; j++)
			{
				field* temp = pole.find_field(i, j);
				if (temp->get_state() == state_of_field::Hit)
					temp->Set_Color(sf::Color::Red);
				else if (temp->get_state() == state_of_field::Taken)
					temp->Set_Color(sf::Color::Blue);
				else if (temp->get_state() == state_of_field::Miss)
					temp->Set_Color(sf::Color::Green);
				window.draw(pole.get_field(i, j));
			}
		}
		sf::Vector2i localPosition = sf::Mouse::getPosition(window);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			localPosition = sf::Mouse::getPosition(window);
			if (((localPosition.y / 40) - 1) >= 0 && ((localPosition.y / 40) - 1) < size && ((localPosition.x / 40) - 1) >= 0 && ((localPosition.x / 40) - 1) < size)
			{
				field* found = pole.find_field(localPosition.x / 40, localPosition.y / 40);
				if (found->get_state() == state_of_field::Empty)
					found->set_state(state_of_field::Miss);
				else if (found->get_state() == state_of_field::Taken)
					found->set_state(state_of_field::Hit);

			}

		}
		flota.get_Battleship()[0].draw_ship(window);
		window.draw(tekst);
		window.display();
	}

	return 0;
}