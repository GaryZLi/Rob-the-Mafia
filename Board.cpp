#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "Board.h"

// using namespace std;

void Board::random()
{
	srand(time(NULL));
}

void Board::set_BoardValueH()
{
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			BoardValue[i][j] = rand() % 2;
		}
	}
}

void Board::set_BoardValueM()
{
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			BoardValue[i][j] = rand() % 5;
		}
	}
}

void Board::set_BoardValueE()
{
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			BoardValue[i][j] = rand() % 10;
		}
	}
}

void Board::set_BoardValueAiE()
{
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			BoardValueAi[i][j] = rand() % 2;
		}
	}
}

void Board::set_BoardValueAiM()
{
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			BoardValueAi[i][j] = rand() % 5;
		}
	}
}

void Board::set_BoardValueAiH()
{
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			BoardValueAi[i][j] = rand() % 10;
		}
	}
}

void Board::set_BoardOut()
{
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			BoardOut[i][j] = 'O';
		}
	}
}

void Board::set_BoardOutAi()
{
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			BoardOutAi[i][j] = 'O';
		}
	}
}

void Board::show_BoardValue()
{
	std::cout << "BOARD : user" << std::endl;

	for (i = 0; i < 7; i++)
	{
		for (a = 0; a < 7; a++)
		{
			std::cout << " - -";
			if (a == 6)
			{
				std::cout << std::endl;
			}
		}

		for (j = 0; j < 7; j++)
		{
			std::cout << "| " << BoardValue[i][j] << " ";
		}
		std::cout << "|" << std::endl;
	}

	for (a = 0; a < 7; a++)
	{
		std::cout << " - -";
		if (a == 6)
		{
			std::cout << std::endl;
		}
	}
}

void Board::show_BoardValueAi()
{
	std::cout << "BOARD : mob" << std::endl;

	for (i = 0; i < 7; i++)
	{
		for (a = 0; a < 7; a++)
		{
			std::cout << " - -";
			if (a == 6)
			{
				std::cout << std::endl;
			}
		}

		for (j = 0; j < 7; j++)
		{
			std::cout << "| " << BoardValueAi[i][j] << " ";
		}
		std::cout << "|" << std::endl;
	}

	for (a = 0; a < 7; a++)
	{
		std::cout << " - -";
		if (a == 6)
		{
			std::cout << std::endl;
		}
	}
}

void Board::show_BoardOut()
{
	std::cout << "BOARD : user" << std::endl;

	for (i = 0; i < 7; i++)
	{
		for (a = 0; a < 7; a++)
		{
			std::cout << " - -";
			if (a == 6)
			{
				std::cout << std::endl;
			}
		}

		for (j = 0; j < 7; j++)
		{
			std::cout << "| " << BoardOut[i][j] << " ";
		}
		std::cout << "|" << std::endl;
	}

	for (a = 0; a < 7; a++)
	{
		std::cout << " - -";
		if (a == 6)
		{
			std::cout << std::endl;
		}
	}
}

void Board::show_BoardOutAi()
{
	std::cout << "BOARD : mob" << std::endl;

	for (i = 0; i < 7; i++)
	{
		for (a = 0; a < 7; a++)
		{
			std::cout << " - -";
			if (a == 6)
			{
				std::cout << std::endl;
			}
		}

		for (j = 0; j < 7; j++)
		{
			std::cout << "| " << BoardOutAi[i][j] << " ";
		}
		std::cout << "|" << std::endl;
	}

	for (a = 0; a < 7; a++)
	{
		std::cout << " - -";
		if (a == 6)
		{
			std::cout << std::endl;
		}
	}
}

void Board::AttackAi()
{
	while (true)
	{
		std::cout << "Choose a street # from 1-7. "; std::cin >> row;
		std::cout << "Choose a intersection # from 1-7. "; std::cin >> column;

		if (BoardOutAi[row - 1][column - 1] == 'X')
		{
			std::cout << "THIS SPOT HAS ALREADY BEEN ROBBED!" << std::endl;
			std::cout << std::endl;
			continue;
		}
		else
		{
			std::cout << "Choose a password from 0-9. "; std::cin >> num;
			std::cout << std::endl;
		}

		if (BoardValueAi[row - 1][column - 1] == num)
		{
			BoardOutAi[row - 1][column - 1] = 'X';

			std::cout << "YOU HIT THE SPOT!" << std::endl;
			std::cout << "TERRITORY IN ROW " << row << " COLUMN " << column << " HAS BEEN ROBBED." << std::endl;

			destroyedAi++;
		}
		else
		{
			std::cout << "YOU MISSED!" << std::endl;
		}

		break;
	}
}

void Board::AttackMeE()
{
	while (true)
	{
		std::cout << "Mob picking a street to attack..." << std::endl; randRow = rand() % 7;
		std::cout << "Mob picking a intersection attack..." << std::endl; randColumn = rand() % 7;

		Sleep(2000);

		if (BoardOut[randRow][randColumn] == 'X')
		{
			std::cout << "THE MOB HAS CHOSEN STREET #" << randRow << " INTERSECTION #" << randColumn << ", BUT IT HAS ALREADY BEEN ROBBED." << std::endl;
			std::cout << std::endl;
			continue;
		}
		else
		{
			std::cout << "Mob attempting to rob you..." << std::endl; randNum = rand() % 10;
			std::cout << std::endl;
		}

		if (BoardValue[randRow][randColumn] == randNum)
		{
			BoardOut[randRow][randColumn] = 'X';

			std::cout << "TERRITORY IN STREET #" << randRow << " INTERSECTION #" << randColumn << " HAS BEEN ROBBED." << std::endl;

			destroyedMe++;
		}
		else
		{
			std::cout << "YOU WERE SAFE FROM THE ROBBERY!" << std::endl;
		}

		Sleep(2000);

		break;
	}
}

void Board::AttackMeM()
{
	while (true)
	{
		std::cout << "Mob picking a street to attack..." << std::endl; randRow = rand() % 7;
		std::cout << "Mob picking a intersection attack..." << std::endl; randColumn = rand() % 7;

		Sleep(2000);

		if (BoardOut[randRow][randColumn] == 'X')
		{
			std::cout << "THE MOB HAS CHOSEN STREET #" << randRow << " INTERSECTION #" << randColumn << ", BUT IT HAS ALREADY BEEN ROBBED." << std::endl;
			std::cout << std::endl;
			continue;
		}
		else
		{
			std::cout << "Mob attempting to rob you..." << std::endl; randNum = rand() % 5;
			std::cout << std::endl;
		}

		if (BoardValue[randRow][randColumn] == randNum)
		{
			BoardOut[randRow][randColumn] = 'X';

			std::cout << "TERRITORY IN STREET #" << randRow << " INTERSECTION #" << randColumn << " HAS BEEN ROBBED." << std::endl;

			destroyedMe++;
		}
		else
		{
			std::cout << "YOU WERE SAFE FROM THE ROBBERY!" << std::endl;
		}

		Sleep(2000);

		break;
	}
}

void Board::AttackMeH()
{
	while (true)
	{
		std::cout << "Mob picking a street to attack..." << std::endl; randRow = rand() % 7;
		std::cout << "Mob picking a intersection attack..." << std::endl; randColumn = rand() % 7;
		Sleep(2000);

		if (BoardOut[randRow][randColumn] == 'X')
		{
			std::cout << "THE MOB HAS CHOSEN STREET #" << randRow << " INTERSECTION #" << randColumn << ", BUT IT HAS ALREADY BEEN ROBBED." << std::endl;
			std::cout << std::endl;
			continue;
		}
		else
		{
			std::cout << "Mob attacking you..." << std::endl; randNum = rand() % 2;
			std::cout << std::endl;
		}

		if (BoardValue[randRow][randColumn] == randNum)
		{
			BoardOut[randRow][randColumn] = 'X';

			std::cout << "TERRITORY IN STREET #" << randRow << " INTERSECTION #" << randColumn << " HAS BEEN ROBBED." << std::endl;

			destroyedMe++;
		}
		else
		{
			std::cout << "YOU WERE SAFE FROM THE ROBBERY!" << std::endl;
		}

		Sleep(2000);

		break;
	}
}

int Board::get_DestroyedAi()
{
	return destroyedAi;
}

int Board::get_DestroyedMe()
{
	return destroyedMe;
}
