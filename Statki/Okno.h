#pragma once
#include "Flota.h"

fleet poczatek(int size, sf::Font font, sf::RenderWindow& window);
void place_fleet(sf::RenderWindow& window, fleet &flota, int size, gameboard &pole, sf::Font font);
int game(sf::RenderWindow& window, gameboard& enemy_board);
void change_amount(sf::Vector2i localPosition, int &Patrol_Boat_amount, int &Cruiser_amount, int &Destroyer_amount, int &Battleship_amount, sf::Text number[]);