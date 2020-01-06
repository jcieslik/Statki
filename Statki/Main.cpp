#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
#include <Vld.h>
#include <Windows.h>
#include "Plansza.h"
#include "Field.h"
#include "Funkcje.h"
#include "Statki.h"
#include "Okno.h"
#include "Flota.h"
#include "Komputer.h"


using namespace std;

int main()
{
	srand(time(0));
	int size = 10;
	sf::Font font;
	if (!font.loadFromFile("coolvetica rg.ttf"))
	{
		return 0;
	}
	sf::RenderWindow window;
	fleet flota = poczatek(size, font, window);
	gameboard player_board(size);
	gameboard enemy_board(size);
	computer* opponent;
	easy przeciwnik(flota, size);
	opponent = &przeciwnik;
	przeciwnik.place_enemy_fleet(enemy_board);
	window.create(sf::VideoMode(40 * (size + 2), 40 * (size + 2)), "Statki", sf::Style::Close);
	place_fleet(window, flota, size, player_board, font);
	while (true)
	{
		int outcome;
		outcome = game(window, enemy_board);
		if(outcome == 1)
			break;
		else if (outcome == 2)
		{
			cout << "BRAWO";
			break;
		}
		if(opponent->enemy_turn(window, player_board) == 1)
			break;
	}
	return 0;
}