#pragma once


const int default_ship_size = 40;

class ship : public sf::RectangleShape
{
protected:
	bool is_sunk = 0;
	std::vector<RectangleShape> vessel;
public:
	void move(int which, int board_size);
	RectangleShape get_vessel(int i)
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
			vessel[i].setPosition((float) default_ship_size * (i + 1), (float) default_ship_size);
		}
	}
	void Set_Position(int x, int y)
	{
		for (int i = 0; i < size; i++)
			vessel[i].setPosition((float) x + i * default_ship_size, (float) y);
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
	void Set_Position(int x, int y)
	{
		for (int i = 0; i < size; i++)
			vessel[i].setPosition((float) x+i*default_ship_size, (float) y);
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
	void Set_Position(int x, int y)
	{
		for (int i = 0; i < size; i++)
			vessel[i].setPosition((float) x + i * default_ship_size, (float) y);
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
	void Set_Position(int x, int y)
	{
		for (int i = 0; i < size; i++)
			vessel[i].setPosition((float) x + i * default_ship_size, (float) y);
	}

};