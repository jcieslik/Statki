#include <SFML/Graphics.hpp>
#include <iostream>
#include "Klasy.h"
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