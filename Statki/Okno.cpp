#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <Windows.h>
#include "Plansza.h"
#include "Field.h"
#include "Funkcje.h"
#include "Statki.h"
#include "Flota.h"
#include "Okno.h"


using namespace std;


fleet poczatek(int& size, sf::Font font, sf::RenderWindow& window)
{
	Battleship Battleship_model;
	Cruiser Cruiser_model;
	Destroyer Destroyer_model;
	Patrol_Boat Patrol_Boat_model;
	window.create(sf::VideoMode(400, 500), "Poczatek", sf::Style::Close);

	int Battleship_amount = 1;
	int Cruiser_amount = 2;
	int Destroyer_amount = 3;
	int Patrol_Boat_amount = 4;

	sf::Text instruction("Ustaw ilosc statkow", font, 30);
	sf::Text setting_size("Wielkosc pola:", font, 30);

	sf::Text plus[5];
	sf::Text minus[5];
	sf::Text number[5];
	
	for (int i = 0; i < 5; i++)
	{
		plus[i].setFont(font);
		plus[i].setString("+");
		plus[i].setPosition(360,(float) 80 + 60*i);
		minus[i].setFont(font);
		minus[i].setString("-");
		minus[i].setPosition(300, (float)80 + 60*i);
		number[i].setFont(font);
		number[i].setString(to_string(4-i));
		number[i].setPosition(320, (float)80 + 60*i);
	}
	number[4].setString(to_string(size));
	instruction.setPosition(20, 20);
	setting_size.setPosition(20, 320);
	Battleship_model.Set_Position(20, 260);
	Cruiser_model.Set_Position(20, 200);
	Destroyer_model.Set_Position(20, 140);
	Patrol_Boat_model.Set_Position(20, 80);
	window.requestFocus();
	while (window.isOpen())
	{
		sf::Event event;
		sf::Vector2i localPosition = sf::Mouse::getPosition(window);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		    else if (event.type == event.MouseButtonReleased)
			{
				localPosition = sf::Mouse::getPosition(window);
				change_amount(localPosition, Patrol_Boat_amount, Cruiser_amount, Destroyer_amount, Battleship_amount, number, size);
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Enter)
				{
					fleet flota(Battleship_amount, Cruiser_amount, Destroyer_amount, Patrol_Boat_amount);
					if (flota.check_if_possible(size) == true)
						return flota;
					else cout << "Za duzo statkow";
				}
			}
		}
		window.clear();
		window.draw(instruction);
		window.draw(setting_size);
		Battleship_model.draw_ship(window);
		Cruiser_model.draw_ship(window);
		Destroyer_model.draw_ship(window);
		Patrol_Boat_model.draw_ship(window);
		for (int i = 0; i < 5; i++)
		{
			window.draw(plus[i]);
			window.draw(minus[i]);
			window.draw(number[i]);
		}
		window.display();
	}
}

void place_fleet(sf::RenderWindow& window, fleet& flota, int size, gameboard& pole, sf::Font font)
{
	Battleship Battleship_model;
	Cruiser Cruiser_model;
	Destroyer Destroyer_model;
	Patrol_Boat Patrol_Boat_model;

	Ships which_used = Ships::No_ship;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Num1)
				{
					if (flota[0] > 0)
						which_used = Ships::Patrol_Boat;
				}
				if (event.key.code == sf::Keyboard::Num2)
				{
					if (flota[1] > 0)
					    which_used = Ships::Destroyer;
				}
				if (event.key.code == sf::Keyboard::Num3)
				{
					if (flota[2] > 0)
					    which_used = Ships::Cruiser;
				}
				if (event.key.code == sf::Keyboard::Num4)
				{
					if (flota[3] > 0)
					    which_used = Ships::Battleship;
				}
				if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down)
				{
					switch (which_used)
					{
					case Ships::Battleship:
						Battleship_model.move(event, size);
						break;
					case Ships::Cruiser:
						Cruiser_model.move(event, size);
						break;
					case Ships::Destroyer:
						Destroyer_model.move(event, size);
						break;
					case Ships::Patrol_Boat:
						Patrol_Boat_model.move(event, size);
						break;
					}
				}
				if (event.key.code == sf::Keyboard::Space)
				{   
					switch (which_used)
					{
					case Ships::Patrol_Boat:
						if (!Patrol_Boat_model.are_fields_taken(pole, size))
						{
							flota[0]--;
							Patrol_Boat_model.place_ship(pole);
							which_used = Ships::No_ship;
						}
						break;

					case Ships::Destroyer:
						if (!Destroyer_model.are_fields_taken(pole, size))
						{
							flota[1]--;
							Destroyer_model.place_ship(pole);
							which_used = Ships::No_ship;
						}
						break;

					case Ships::Cruiser:
						if (!Cruiser_model.are_fields_taken(pole, size))
						{
							flota[2]--;
							Cruiser_model.place_ship(pole);
							which_used = Ships::No_ship;
						}
						break;

					case Ships::Battleship:
						if (!Battleship_model.are_fields_taken(pole, size))
						{
							flota[3]--;
							Battleship_model.place_ship(pole);
							which_used = Ships::No_ship;
						}
						break;
					}
				}
				if (event.key.code == sf::Keyboard::LShift)
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
				if (event.key.code == sf::Keyboard::Enter)
					return;
			}
		}
		window.clear();

		for (int i = 1; i <= size; i++)
		{
			for (int j = 1; j <= size; j++)
			{
				field* temp = pole.find_field(i, j);
                if (temp->get_state() == state_of_field::Taken)
					temp->Set_Color(sf::Color::Black);
				window.draw(pole.get_field(i, j));
			}
		}
	
		switch (which_used)
		{
		case Ships::Battleship:
			Battleship_model.draw_ship(window);
			break;
		case Ships::Cruiser:
			Cruiser_model.draw_ship(window);
			break;
		case Ships::Destroyer:
			Destroyer_model.draw_ship(window);
			break;
		case Ships::Patrol_Boat:
			Patrol_Boat_model.draw_ship(window);
			break;
		}
		window.display();
	}
}

int game(sf::RenderWindow& window, gameboard& enemy_board)
{
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
			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.key.code == sf::Mouse::Left)
				{
					sf::Vector2i localPosition = sf::Mouse::getPosition(window);
					if (((localPosition.y / 40) - 1) >= 0 && ((localPosition.y / 40) - 1) < enemy_board.get_size()
						&& ((localPosition.x / 40) - 1) >= 0 && ((localPosition.x / 40) - 1) < enemy_board.get_size())
					{
						field* found = enemy_board.find_field(localPosition.x / 40, localPosition.y / 40);
						if (found->get_state() == state_of_field::Empty)
						{
							found->set_state(state_of_field::Miss);
							Sleep(300);
							window.clear();
							return 0;
						}
						else if (found->get_state() == state_of_field::Taken)
						{
							found->set_state(state_of_field::Hit);
							if (enemy_board.check_if_sunk(found))
							{
								enemy_board.sink(found);
								if (enemy_board.check_if_won() == true)
									return 2;
							}
						}
					}
				}
			}
		}
		window.clear();
		for (int i = 1; i <= enemy_board.get_size(); i++)
		{
			for (int j = 1; j <= enemy_board.get_size(); j++)
			{
				field* temp = enemy_board.find_field(i, j);
				if (temp->get_state() == state_of_field::Hit)
					temp->Set_Color(sf::Color::Red);
				else if (temp->get_state() == state_of_field::Miss)
					temp->Set_Color(sf::Color::Blue);
				window.draw(enemy_board.get_field(i, j));
			}
		}
		window.display();
	}
}

void change_amount(sf::Vector2i localPosition, int &Patrol_Boat_amount, int &Cruiser_amount, int &Destroyer_amount, int & Battleship_amount, sf::Text number[], int& size)
{
	if (localPosition.x > 360 && localPosition.x < 380 && localPosition.y>80 && localPosition.y < 120 && Patrol_Boat_amount < 99)
	{
		Patrol_Boat_amount++;
		number[0].setString(to_string(Patrol_Boat_amount));
	}
	if (localPosition.x > 300 && localPosition.x < 320 && localPosition.y>80 && localPosition.y < 120 && Patrol_Boat_amount > 0)
	{
		Patrol_Boat_amount--;
		number[0].setString(to_string(Patrol_Boat_amount));
	}
	if (localPosition.x > 360 && localPosition.x < 380 && localPosition.y>140 && localPosition.y < 180 && Destroyer_amount < 99)
	{
		Destroyer_amount++;
		number[1].setString(to_string(Destroyer_amount));
	}
	if (localPosition.x > 300 && localPosition.x < 320 && localPosition.y>140 && localPosition.y < 180 && Destroyer_amount > 0)
	{
		Destroyer_amount--;
		number[1].setString(to_string(Destroyer_amount));
	}
	if (localPosition.x > 360 && localPosition.x < 380 && localPosition.y>200 && localPosition.y < 240 && Cruiser_amount < 99)
	{
		Cruiser_amount++;
		number[2].setString(to_string(Cruiser_amount));
	}
	if (localPosition.x > 300 && localPosition.x < 320 && localPosition.y>200 && localPosition.y < 240 && Cruiser_amount > 0)
	{
		Cruiser_amount--;
		number[2].setString(to_string(Cruiser_amount));
	}
	if (localPosition.x > 360 && localPosition.x < 380 && localPosition.y>260 && localPosition.y < 300 && Battleship_amount < 99)
	{
		Battleship_amount++;
		number[3].setString(to_string(Battleship_amount));
	}
	if (localPosition.x > 300 && localPosition.x < 320 && localPosition.y>260 && localPosition.y < 300 && Battleship_amount > 0)
	{
		Battleship_amount--;
		number[3].setString(to_string(Battleship_amount));
	}
	if (localPosition.x > 360 && localPosition.x < 380 && localPosition.y>320 && localPosition.y < 360 && size < 20)
	{
		size++;
		number[4].setString(to_string(size));
	}
	if (localPosition.x > 300 && localPosition.x < 320 && localPosition.y>320 && localPosition.y < 360 && size > 8)
	{
		size--;
		number[4].setString(to_string(size));
	}
}