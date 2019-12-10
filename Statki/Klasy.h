#pragma once
#include "Field.h"


class gameboard
{
private:
	int size;
	class field *game;
public:
	void add_field(int x, int y)
	{
		sf::Color kolor(148, 198, 239);
		field *nowe = new field;
		nowe->set_coord_x(x);
		nowe->set_coord_y(y);
		nowe->Set_Color(kolor);
		nowe->Set_Position(x, y);
		if (game == nullptr)
			game = nowe;
		else
		{
			field* temp = game;
			while (temp->get_next())
			{
				temp = temp->get_next();
			}
			temp->set_next(nowe);
			nowe->set_next(nullptr);
		}

	}
	gameboard(int size);
	sf::RectangleShape get_field(int i, int j)
	{
		field* temp = game;
		while (temp)
		{
			if (temp->get_coord_x() == i && temp->get_coord_y() == j)
				return temp->get_rectangle();
			temp = temp->get_next();
		}
	}
	field* find_field(int x, int y)
	{
		field* temp = game;
		while (temp)
		{
			if (temp->get_coord_x() == x && temp->get_coord_y() == y)
				return temp;
			temp = temp->get_next();
		}
		return nullptr;
	}
};