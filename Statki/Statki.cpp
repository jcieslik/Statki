#include <iostream>
#include <SFML/Graphics.hpp>
#include "Statki.h"

using namespace std;

void ship::move(int which, int board_size)
{
	if (which == 0)
	{
		for (int i = 0; i < (int)vessel.size(); i++)
		{
			if (!(vessel[i].getPosition().x < default_ship_size+1))
			    vessel[i].move(-40, 0);
			else break;
		}
	}
	else if (which == 1)
	{
		for (int i = vessel.size()-1; i >=0; i--)
		{
			if (!(vessel[i].getPosition().x > (default_ship_size * board_size) - 1))
				vessel[i].move(40, 0);
			else break;
		}
	}
	else if (which == 2)
	{
		for (int i = 0; i < (int) vessel.size(); i++)
		{
			if (!(vessel[i].getPosition().y < default_ship_size + 1))
			    vessel[i].move(0, -40);
			else break;
		}
	}
	else if (which == 3)
	{
		for (int i = 0; i < (int) vessel.size(); i++)
		{
			if (!(vessel[i].getPosition().y > (default_ship_size*board_size) - 1))
			    vessel[i].move(0, 40);
	        else break;
		}
	}
}
