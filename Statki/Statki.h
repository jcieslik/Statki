#pragma once
#include "Klasy.h"

const int default_ship_size = 40;

class ship : public sf::RectangleShape
{
protected:
	std::vector<RectangleShape> vessel;
public:
	void move(sf::Event event, int board_size);
	RectangleShape& operator[](int i)
	{
		return vessel[i];
	}
	int get_position(int index, int which)
	{
		if (which==0)
		return (int)vessel[index].getPosition().y;
		else return (int)vessel[index].getPosition().x;
	}
	void draw_ship(sf::RenderWindow& window)
	{
		for (int i = 0; i < (int) vessel.size(); i++)
			window.draw(vessel[i]);
	}
	void swap(int board_size)
	{
		if (this->get_position(vessel.size() - 1, 0) == this->get_position(0, 0))   //zmiana na pion
		{
			if (!(vessel[vessel.size()-1].getPosition().y + 40*(vessel.size()-1) > (default_ship_size * board_size)))
			{
				for (int i = 0; i < vessel.size(); i++)
					vessel[i].move(-40 * i, 40 * i);
			}
		}
		else     //zmiana na poziom
		{
			if (!(vessel[vessel.size() - 1].getPosition().x + 40*(vessel.size()-1) > (default_ship_size * board_size)))
			{
				for (int i = 0; i < vessel.size(); i++)
					vessel[i].move(40 * i, -40 * i);
			}
		}
	}
	bool are_fields_taken(gameboard& pole, int size)
	{
		for (int i = 0; i < vessel.size(); i++)
		{
			field* temp = pole.find_field(vessel[i].getPosition().x / default_ship_size, vessel[i].getPosition().y / default_ship_size);
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
	void randomize_position(gameboard& pole, int size, bool is_swapped)
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
	void place_ship(gameboard& pole)
	{

		for (int i = 0; i < vessel.size(); i++)
			pole.find_field(vessel[i].getPosition().x / default_ship_size, vessel[i].getPosition().y / default_ship_size)->set_state(state_of_field::Taken);
		for (int i = 0; i < vessel.size(); i++)
			vessel[i].setPosition(40 * (i+1), 40);
	}
	void Set_Position(int x, int y)
	{
		for (int i = 0; i < vessel.size; i++)
			vessel[i].setPosition((float)x + i * default_ship_size, (float)y);
	}
};

class Battleship : public ship
{
public:
	const int size = 4;
	Battleship()
	{
		RectangleShape field;
		for (int i = 0; i < size; i++)
		{
			vessel.push_back(field);
			vessel[i].setSize(sf::Vector2f(default_ship_size, default_ship_size));
			vessel[i].setPosition((float)default_ship_size * (i + 1), (float)default_ship_size);
		}
	}
};

class Cruiser : public ship
{
public:
	const int size = 3;
	Cruiser()
	{
		RectangleShape field;
		for (int i = 0; i < size; i++)
		{
			vessel.push_back(field);
			vessel[i].setSize(sf::Vector2f(default_ship_size, default_ship_size));
			vessel[i].setPosition((float) default_ship_size * (i + 1), (float) default_ship_size);
		}
	}
};

class Destroyer : public ship
{
public:
	const int size = 2;
	Destroyer()
	{
		RectangleShape field;
		for (int i = 0; i < size; i++)
		{
			vessel.push_back(field);
			vessel[i].setSize(sf::Vector2f(default_ship_size, default_ship_size));
			vessel[i].setPosition((float) default_ship_size * (i + 1), (float) default_ship_size);
		}
	}
};

class Patrol_Boat : public ship
{
public:
	const int size = 1;
	Patrol_Boat()
	{
		RectangleShape field;
		for (int i = 0; i < size; i++)
		{
			vessel.push_back(field);
			vessel[i].setSize(sf::Vector2f(default_ship_size, default_ship_size));
			vessel[i].setPosition((float) default_ship_size * (i + 1), (float) default_ship_size);
		}
	}
};