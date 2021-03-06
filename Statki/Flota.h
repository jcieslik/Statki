#pragma once

class fleet
{
	int Battleship_count;
	int Cruiser_count;
	int Destroyer_count;
	int Patrol_Boat_count;
public:
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
	fleet()
	{
		Battleship_count = 0;
	    Cruiser_count = 0;
		Destroyer_count = 0;
	    Patrol_Boat_count = 0;
	}
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
	int& operator[](int i)
	{
		switch (i)
		{
		case 0:
			return Patrol_Boat_count;
		case 1:
			return Destroyer_count;
		case 2:
			return Cruiser_count;
		case 3:
			return Battleship_count;
		}
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
};