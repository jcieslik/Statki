#pragma once

enum class state_of_field { Empty = 0, Miss = 1, Taken = 2, Hit = 3};

class field : public sf::RectangleShape
{
	RectangleShape rectangle;
	state_of_field state;
	int x;
	int y;
	field* next;
public:
	void set_coord_x(int x)
	{
		this->x = x;
	}
	void set_coord_y(int y)
	{
		this->y = y;
	}
	void set_next(field* next)
	{
		this->next = next;
	}
	int get_coord_x()
	{
		return x;
	}
	int get_coord_y()
	{
		return y;
	}
	field* get_next()
	{
		return next;
	}
	RectangleShape get_rectangle()
	{
		return rectangle;
	}
	void Set_Position(int x, int y)
	{
		rectangle.setPosition((float)40 * x, (float)40 * y);
	}
	void Set_Color(sf::Color Kolor)
	{
		rectangle.setFillColor(Kolor);
	}
	field()
	{
		x = 0;
		y = 0;
		state = state_of_field::Empty;
		rectangle.setSize(sf::Vector2f(40, 40));
		rectangle.setOutlineThickness(1);
		next = nullptr;
	}
	void set_state(state_of_field new_state)
	{
		state = new_state;
	}
	state_of_field get_state() const
	{
		return state;
	}

};