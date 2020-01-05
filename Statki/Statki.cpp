#include <iostream>
#include <SFML/Graphics.hpp>
#include "Statki.h"
#include "Klasy.h"

using namespace std;

void ship::move(sf::Event event, int board_size)
{
	if (event.key.code == sf::Keyboard::Left)
	{
		for (int i = 0; i < (int)vessel.size(); i++)
		{
			if (!(vessel[i].getPosition().x < default_ship_size+1))
			    vessel[i].move(-40, 0);
			else break;
		}
	}
	else if (event.key.code == sf::Keyboard::Right)
	{
		for (int i = vessel.size()-1; i >=0; i--)
		{
			if (!(vessel[i].getPosition().x > (default_ship_size * board_size) - 1))
				vessel[i].move(40, 0);
			else break;
		}
	}
	else if (event.key.code == sf::Keyboard::Up)
	{
		for (int i = 0; i < (int) vessel.size(); i++)
		{
			if (!(vessel[i].getPosition().y < default_ship_size + 1))
			    vessel[i].move(0, -40);
			else break;
		}
	}
	else if (event.key.code == sf::Keyboard::Down)
	{
		for (int i = (int)vessel.size()-1; i >= 0; i--)
		{
			if (!(vessel[i].getPosition().y > (default_ship_size*board_size) - 1))
			    vessel[i].move(0, 40);
	        else break;
		}
	}
}
