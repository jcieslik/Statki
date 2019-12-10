#pragma once

class fleet
{
	int Battleship_count;
	int Cruiser_count;
	int Destroyer_count;
	int Patrol_Boat_count;
public:
	std::vector<Battleship> vector_of_battleships;
	std::vector<Cruiser> vector_of_cruisers;
	std::vector<Destroyer> vector_of_destroyers;
	std::vector<Patrol_Boat> vector_of_Patrol_Boats;
	fleet(int Battleship_amount, int Cruiser_amount, int Destroyer_amount, int Patrol_Boat_amount)
	{
		Battleship_count = Battleship_amount;
		Cruiser_count = Cruiser_amount;
		Destroyer_count = Destroyer_amount;
		Patrol_Boat_count = Patrol_Boat_amount;
	}
	fleet(const fleet& flota)
	{
		Battleship_count = flota.Battleship_count; 
		Cruiser_count = flota.Cruiser_count;
		Destroyer_count = flota.Destroyer_count;
		Patrol_Boat_count = flota.Patrol_Boat_count;
	}
	fleet();
	fleet& operator=(const fleet& prawy)
	{
		if (&prawy != this)
		{
			Battleship_count = prawy.Battleship_count;
			Cruiser_count = prawy.Cruiser_count;
			Destroyer_count = prawy.Destroyer_count;
			Patrol_Boat_count = prawy.Patrol_Boat_count;
		}
		return *this;
	}
	bool check_if_possible(int size)
	{
		int temp_Battleship = Battleship_count;
		int temp_Cruiser = Cruiser_count;
		int temp_Destroyer = Destroyer_count;
		int temp_Patrol_Boat = Patrol_Boat_count;

		for (int i = 0; i < size; i = i+2)
		{
			for (int j = 0; j < size; j++)
			{
				if (temp_Battleship > 0 && size - j > 3)
				{
					temp_Battleship--;
					j = j + 4;
				}
				else if (temp_Cruiser > 0 && size - j > 2)
				{
					temp_Cruiser--;
					j = j + 3;
				}
				else if (temp_Destroyer > 0 && size - j > 1)
				{
					temp_Destroyer--;
					j = j + 2;
				}
				else if (temp_Patrol_Boat > 0)
				{
					temp_Patrol_Boat--;
					j++;
				}
			}
		}
		if (temp_Battleship == 0 && temp_Cruiser == 0 && temp_Destroyer == 0 && temp_Patrol_Boat == 0)
			return true;
		else return false;
	}
	void create_fleet()
	{
		std::cout << Battleship_count;
		Battleship nowy{};
		while (Battleship_count > 0)
		{
			vector_of_battleships.push_back(nowy);
			Battleship_count--;
		}
	}
	std::vector<Battleship> get_Battleship()
	{
		return vector_of_battleships;
	}
};