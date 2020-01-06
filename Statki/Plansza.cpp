#include <SFML/Graphics.hpp>
#include <iostream>
#include "Plansza.h"
#include "Field.h"

using namespace std;

gameboard::gameboard(int size)
{
	sf::Color kolor(148, 198, 239);
	this->size = size;
	this->game = nullptr;
	for (int i = 1; i <= size; i++)
		for (int j = 1; j <= size; j++)
			this->add_field(i, j);
}

gameboard::~gameboard()
{
	while (game)
	{
		field* temp = game->get_next();
		delete game;
		game = temp;
	}
}

void gameboard::add_field(int x, int y)
{
	sf::Color kolor(148, 198, 239);
	field* nowe = new field;
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

field* gameboard::find_field(int x, int y)
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

bool gameboard::check_if_sunk(field* found)
{
	field* temp = found;
	for (int i = 1; i < 4; i++)
	{
		if (found->get_coord_x() + i <= size)
		{
			temp = find_field(found->get_coord_x() + i, found->get_coord_y());
			if (temp->get_state() == state_of_field::Taken)
				return false;
			else if (temp->get_state() == state_of_field::Miss || temp->get_state() == state_of_field::Empty)
				break;
		}
	}
	for (int i = 1; i < 4; i++)
	{
		if (found->get_coord_y() + i <= size)
		{
			temp = find_field(found->get_coord_x(), found->get_coord_y() + i);
			if (temp->get_state() == state_of_field::Taken)
				return false;
			else if (temp->get_state() == state_of_field::Miss || temp->get_state() == state_of_field::Empty)
				break;
		}
	}
	for (int i = -1; i > -4; i--)
	{
		if (found->get_coord_x() + i > 0)
		{
			temp = find_field(found->get_coord_x() + i, found->get_coord_y());
			if (temp->get_state() == state_of_field::Taken)
				return false;
			else if (temp->get_state() == state_of_field::Miss || temp->get_state() == state_of_field::Empty)
				break;
		}
	}
	for (int i = -1; i > -4; i--)
	{
		if (found->get_coord_y() + i > 0)
		{
			temp = find_field(found->get_coord_x(), found->get_coord_y() + i);
			if (temp->get_state() == state_of_field::Taken)
				return false;
			else if (temp->get_state() == state_of_field::Miss || temp->get_state() == state_of_field::Empty)
				break;
		}
	}
	return true;
}

void gameboard::sink(field* found)
{
	field* temp = found;
	for (int i = 0; i < 4; i++)
	{
		if (found->get_coord_x() + i <= size)
		{
			temp = find_field(found->get_coord_x() + i, found->get_coord_y());
			mark_missed(temp);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (found->get_coord_y() + i <= size)
		{
			temp = find_field(found->get_coord_x(), found->get_coord_y() + i);
			mark_missed(temp);
		}
	}
	for (int i = 0; i > -4; i--)
	{
		if (found->get_coord_x() + i > 0)
		{
			temp = find_field(found->get_coord_x() + i, found->get_coord_y());
			mark_missed(temp);
		}
	}
	for (int i = 0; i > -4; i--)
	{
		if (found->get_coord_y() + i > 0)
		{
			temp = find_field(found->get_coord_x(), found->get_coord_y() + i);
			mark_missed(temp);
		}
	}
}

void gameboard::mark_missed(field* found)
{
	field* temp = found;
	if (temp->get_state() == state_of_field::Hit)
	{
		for (int j = -1; j < 2; j++)
		{
			for (int k = -1; k < 2; k++)
			{
				if (temp->get_coord_x() + j > 0 && temp->get_coord_y() + k > 0 && temp->get_coord_x() + j <= size && temp->get_coord_y() + k <= size)
				{
					if (find_field(temp->get_coord_x() + j, temp->get_coord_y() + k) -> get_state() != state_of_field::Hit)
						find_field(temp->get_coord_x() + j, temp->get_coord_y() + k) -> set_state(state_of_field::Miss);
				}
			}
		}
	}
}

bool gameboard::check_if_won()
{
	field* temp = game;
	while (temp)
	{
		if (temp->get_state() == state_of_field::Taken)
			return false;
		temp = temp->get_next();
	}
	return true;
}

