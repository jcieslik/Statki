#pragma once
#include "Plansza.h"

const int default_ship_size = 40;

class ship : public sf::RectangleShape
{
protected:
	std::vector<RectangleShape> vessel;
public:
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
	void Set_Position(int x, int y)
	{
		for (int i = 0; i < vessel.size(); i++)
			vessel[i].setPosition((float)x + i * default_ship_size, (float)y);
	}
	void draw_ship(sf::RenderWindow& window)
	{
		for (int i = 0; i < (int) vessel.size(); i++)
			window.draw(vessel[i]);
	}
	bool are_fields_taken(gameboard& pole, int size);
	void randomize_position(gameboard& pole, int size, bool is_swapped);
	void place_ship(gameboard& pole);
	void move(sf::Event event, int board_size);
	void swap(int board_size);
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