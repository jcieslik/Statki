#pragma once
#include "Field.h"

class gameboard
{
private:
	int size;
	field *game;
public:
	int get_size()
	{
		return size;
	}
	sf::RectangleShape get_field(int i, int j)
	{
		field* temp = game;
		while (temp)
		{
			if (temp->get_coord_x() == i && temp->get_coord_y() == j)
				return temp->get_rectangle();
			temp = temp->get_next();
		}
		return game->get_rectangle();
	}
	gameboard(int size);
	~gameboard();
	void add_field(int x, int y);
	field* find_field(int x, int y);
	bool check_if_sunk(field* found);
	void sink(field* found);
	void mark_missed(field* found);
	bool check_if_won();
};