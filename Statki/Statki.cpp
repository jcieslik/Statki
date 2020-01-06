#include <iostream>
#include <SFML/Graphics.hpp>
#include "Statki.h"
#include "Plansza.h"

using namespace std;

bool ship::are_fields_taken(gameboard& pole, int size)
{
	for (int i = 0; i < vessel.size(); i++)
	{
		field* temp = pole.find_field((int)vessel[i].getPosition().x / default_ship_size, (int)vessel[i].getPosition().y / default_ship_size);
		for (int j = -1; j < 2; j++)
		{
			for (int k = -1; k < 2; k++)
			{
				if (temp->get_coord_x() + j > 0 && temp->get_coord_y() + k > 0 && temp->get_coord_x() + j <= size && temp->get_coord_y() + k <= size)
				{
					if (pole.find_field(temp->get_coord_x() + j, temp->get_coord_y() + k)->get_state() == state_of_field::Taken)
						return true;
				}
			}
		}
	}
	return false;
}

void ship::randomize_position(gameboard& pole, int size, bool is_swapped)
{
	int x = 0;
	int y = 0;
	if (is_swapped == false)
	{
		x = (rand() % (size - vessel.size() + 1) + 1) * default_ship_size;
		y = (rand() % size + 1) * default_ship_size;
	}
	else
	{
		x = (rand() % size + 1) * default_ship_size;
		y = (rand() % (size - vessel.size() + 1) + 1) * default_ship_size;
	}
	for (int i = 0; i < vessel.size(); i++)
		vessel[i].setPosition((float)x + i * default_ship_size, (float)y);
}

void ship::place_ship(gameboard& pole)
{
	for (int i = 0; i < vessel.size(); i++)
		pole.find_field((int)vessel[i].getPosition().x / default_ship_size, (int)vessel[i].getPosition().y / default_ship_size)->set_state(state_of_field::Taken);
	for (int i = 0; i < vessel.size(); i++)
		vessel[i].setPosition((float)40 * (i + 1), 40);
}

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
		for (int i = (int)vessel.size()-1; i >=0; i--)
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

void ship::swap(int board_size)
{
	if (this->get_position((int)vessel.size() - 1, 0) == this->get_position(0, 0))   //zmiana na pion
	{
		if (!(vessel[vessel.size() - 1].getPosition().y + 40 * (vessel.size() - 1) > (default_ship_size * board_size)))
		{
			for (int i = 0; i < vessel.size(); i++)
				vessel[i].move((float)-40 * i, (float)40 * i);
		}
	}
	else     //zmiana na poziom
	{
		if (!(vessel[vessel.size() - 1].getPosition().x + 40 * (vessel.size() - 1) > (default_ship_size * board_size)))
		{
			for (int i = 0; i < vessel.size(); i++)
				vessel[i].move((float)40 * i, (float)-40 * i);
		}
	}
}
