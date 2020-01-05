#pragma once
#include "Field.h"

class gameboard
{
private:
	int size;
	class field *game;
public:
	int get_size()
	{
		return size;
	}
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
	bool check_if_sunk(field *found)
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
	void sink(field* found)
	{
		field* temp = found;
		for (int i = 0; i < 4; i++)
		{
			if (found->get_coord_x() + i <= size)
			{
				temp = find_field(found->get_coord_x() + i, found->get_coord_y());
				if (temp->get_state() == state_of_field::Hit)
				{
					for (int j = -1; j < 2; j++)
					{
						for (int k = -1; k < 2; k++)
						{
							if (temp->get_coord_x() + j > 0 && temp->get_coord_y() + k > 0 && temp->get_coord_x() + j <= size && temp->get_coord_y() + k <= size)
							{
								if (find_field(temp->get_coord_x() + j, temp->get_coord_y() + k)->get_state() != state_of_field::Hit)
									find_field(temp->get_coord_x() + j, temp->get_coord_y() + k)->set_state(state_of_field::Miss);
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (found->get_coord_y() + i <= size)
			{
				temp = find_field(found->get_coord_x(), found->get_coord_y() + i);
				if (temp->get_state() == state_of_field::Hit)
				{
					for (int j = -1; j < 2; j++)
					{
						for (int k = -1; k < 2; k++)
						{
							if (temp->get_coord_x() + j > 0 && temp->get_coord_y() + k > 0 && temp->get_coord_x() + j <= size && temp->get_coord_y() + k <= size)
							{
								if (find_field(temp->get_coord_x() + j, temp->get_coord_y() + k)->get_state() != state_of_field::Hit)
									find_field(temp->get_coord_x() + j, temp->get_coord_y() + k)->set_state(state_of_field::Miss);
							}
						}
					}
				}
			}
		}
		for (int i = 0; i > -4; i--)
		{
			if (found->get_coord_x() + i > 0)
			{
				temp = find_field(found->get_coord_x() + i, found->get_coord_y());
				if (temp->get_state() == state_of_field::Hit)
				{
					for (int j = -1; j < 2; j++)
					{
						for (int k = -1; k < 2; k++)
						{
							if (temp->get_coord_x() + j > 0 && temp->get_coord_y() + k > 0 && temp->get_coord_x() + j <= size && temp->get_coord_y() + k <= size)
							{
								if (find_field(temp->get_coord_x() + j, temp->get_coord_y() + k)->get_state() != state_of_field::Hit)
									find_field(temp->get_coord_x() + j, temp->get_coord_y() + k)->set_state(state_of_field::Miss);
							}
						}
					}
				}
			}
		}
		for (int i = 0; i > -4; i--)
		{
			if (found->get_coord_y() + i > 0)
			{
				temp = find_field(found->get_coord_x(), found->get_coord_y() + i);
				if (temp->get_state() == state_of_field::Hit)
				{
					for (int j = -1; j < 2; j++)
					{
						for (int k = -1; k < 2; k++)
						{

							if (temp->get_coord_x() + j > 0 && temp->get_coord_y() + k > 0 && temp->get_coord_x() + j <= size && temp->get_coord_y() + k <= size)
							{
								if (find_field(temp->get_coord_x() + j, temp->get_coord_y() + k)->get_state() != state_of_field::Hit)
									find_field(temp->get_coord_x() + j, temp->get_coord_y() + k)->set_state(state_of_field::Miss);
							}
						}
					}
				}
			}
		}
	}
	bool check_if_won()
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
};