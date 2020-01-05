#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
#include <Windows.h>
#include "Klasy.h"
#include "Field.h"
#include "Funkcje.h"
#include "Statki.h"
#include "Okno.h"
#include "Flota.h"
#include "Komputer.h"


using namespace std;

int main()
{
	srand(time(NULL));
	int size;
	cin >> size;
	gameboard player_board(size);
	gameboard enemy_board(size);
	sf::Font font;
	if (!font.loadFromFile("coolvetica rg.ttf"))
	{
		return 0;
	}
	sf::RenderWindow window;
	fleet flota = poczatek(size, font, window);
	computer* opponent;
	easy przeciwnik(flota);
	opponent = &przeciwnik;
	przeciwnik.place_enemy_fleet(enemy_board, size);
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
		if(opponent->enemy_turn(window, size, player_board) == 1)
			break;
	}
	Sleep(1000);
	return 0;
}