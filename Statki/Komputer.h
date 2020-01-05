#pragma once
#include "Flota.h"

class computer
{
protected:
	fleet enemy_fleet;
public:
	fleet get_fleet()
	{
		return enemy_fleet;
	}
	computer(fleet flota)
	{
		enemy_fleet = flota;
	}
	void place_enemy_fleet(gameboard& pole, int size)
	{
		Battleship Battleship_model;
		Cruiser Cruiser_model;
		Destroyer Destroyer_model;
		Patrol_Boat Patrol_Boat_model;
		bool is_swapped;
		Ships which_used = Ships::No_ship;
		for (int i = 0; i < 10000; i++)
		{
			is_swapped = rand() % 2;
			Battleship_model.randomize_position(pole, size, is_swapped);
			Cruiser_model.randomize_position(pole, size, is_swapped);
			Destroyer_model.randomize_position(pole, size, is_swapped);
			Patrol_Boat_model.randomize_position(pole, size, is_swapped);
			which_used = static_cast<Ships>(rand() % 4 + 1);
			if (is_swapped == true)
			{
				switch (which_used)
				{
				case Ships::Battleship:
					Battleship_model.swap(size);
					break;
				case Ships::Cruiser:
					Cruiser_model.swap(size);
					break;
				case Ships::Destroyer:
					Destroyer_model.swap(size);
					break;
				case Ships::Patrol_Boat:
					Patrol_Boat_model.swap(size);
					break;
				}
			}
			switch (which_used)
			{
			case Ships::Patrol_Boat:
				if (!Patrol_Boat_model.are_fields_taken(pole, size))
				{
					if (enemy_fleet[0] > 0)
					{
						enemy_fleet[0]--;
						Patrol_Boat_model.place_ship(pole);
						which_used = Ships::No_ship;
					}
				}
				break;
			case Ships::Destroyer:
				if (!Destroyer_model.are_fields_taken(pole, size))
				{
					if (enemy_fleet[1] > 0)
					{
						enemy_fleet[1]--;
						Destroyer_model.place_ship(pole);
						which_used = Ships::No_ship;
					}
				}
				break;

			case Ships::Cruiser:
				if (!Cruiser_model.are_fields_taken(pole, size))
				{
					if (enemy_fleet[2] > 0)
					{
						enemy_fleet[2]--;
						Cruiser_model.place_ship(pole);
						which_used = Ships::No_ship;
					}
				}
				break;

			case Ships::Battleship:
				if (!Battleship_model.are_fields_taken(pole, size))
				{
					if (enemy_fleet[3] > 0)
					{
						enemy_fleet[3]--;
						Battleship_model.place_ship(pole);
						which_used = Ships::No_ship;
					}
				}
				break;
			}
		}
	}
	virtual int enemy_turn(sf::RenderWindow& window, int size, gameboard& player_board) = 0;
};

class easy : public computer
{
public:
	easy(fleet flota)
		: computer(flota)
	{ }
	int enemy_turn(sf::RenderWindow& window, int size, gameboard& player_board)
	{
		int x = rand() % size + 1;
		int y = rand() % size + 1;
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
					return 1;
				}
				if (event.type == sf::Event::KeyReleased)
				{
					if (event.key.code == sf::Keyboard::Enter)
					{
						return 0;
					}
				}
			}
			window.clear();
			while (player_board.find_field(x, y)->get_state() == state_of_field::Taken)
			{
				player_board.find_field(x, y)->set_state(state_of_field::Hit);
				x = rand() % size + 1;
				y = rand() % size + 1;
			}
			player_board.find_field(x, y)->set_state(state_of_field::Miss);
			for (int i = 1; i <= player_board.get_size(); i++)
			{
				for (int j = 1; j <= player_board.get_size(); j++)
				{
					field* temp = player_board.find_field(i, j);
					if (temp->get_state() == state_of_field::Hit)
						temp->Set_Color(sf::Color::Red);
					else if (temp->get_state() == state_of_field::Miss)
						temp->Set_Color(sf::Color::Blue);
					window.draw(player_board.get_field(i, j));
				}
			}
			window.display();
		}
	}
};

class normal : public computer
{
public:
	normal(fleet flota)
		: computer(flota)
	{ }
	int enemy_turn(sf::RenderWindow& window, int size, gameboard& player_board)
	{

	}
};

class hard : public computer
{
public:
	hard(fleet flota)
		: computer(flota)
	{ }
	int enemy_turn(sf::RenderWindow& window, int size, gameboard& player_board)
	{

	}
};
