#include <iostream>
#include "Board.h"

// using namespace std;

int main()
{
	Board b;
	int turns, turnsAi, terr, turnNum = 1;
	char diffic, show, again;

	while (true)
	{
		b.random();
		b.set_BoardOut();
		b.set_BoardOutAi();

		std::cout << std::endl;
		std::cout << "***** ROB The MOB ! *****" << std::endl;
		std::cout << std::endl;
		std::cout << "Would you like difficulty to be easy, medium or hard? (e/m/h) "; std::cin >> diffic;
		std::cout << std::endl;

		while (((diffic != 'e') && (diffic != 'm') && (diffic != 'h')) && ((diffic != 'E') && (diffic != 'M') && (diffic != 'H')))
		{
			std::cout << "Please enter 'e', 'm', or 'h'. "; std::cin >> diffic;
			std::cout << std::endl;
		}

		if (diffic == 'e' || diffic == 'E')
		{
			b.set_BoardValueE();
			b.set_BoardValueAiE();
		}
		else if (diffic == 'm' || diffic == 'M')
		{
			b.set_BoardValueM();
			b.set_BoardValueAiM();
		}
		else
		{
			b.set_BoardValueH();
			b.set_BoardValueAiH();
		}

		std::cout << "How many turns would you like? "; std::cin >> turns;
		std::cout << std::endl;
		std::cout << "How many territories would you like to rob? "; std::cin >> terr;

		while (terr > 49)
		{
			std::cout << "Please enter a number less than 49."; std::cin >> terr;
		}

		std::cout << std::endl;

		while (terr > turns)
		{
			std::cout << "You can only rob one territory per turn! Please enter a number of territories less than the number of turns. "; std::cin >> terr;
		}

		std::cout << "Show the passwords? (y/n) "; std::cin >> show;
		std::cout << std::endl;

		while (((show != 'y') && (show != 'n')) && ((show != 'Y') && (show != 'N')))
		{
			std::cout << "Please enter 'y' or 'n'. "; std::cin >> show;
			std::cout << std::endl;
		}

		if (show == 'y' || show == 'Y')
		{
			b.show_BoardValue();
			std::cout << std::endl;
			b.show_BoardValueAi();
			std::cout << std::endl;
		}

		while (turns > 0)
		{
			std::cout << "Turn #" << turnNum << std::endl;
			std::cout << std::endl;
			std::cout << "***YOUR TURN***" << std::endl;
			std::cout << std::endl;

			b.AttackAi();
			std::cout << std::endl;
			b.show_BoardOutAi();
			std::cout << std::endl;

			system("pause");
			std::cout << std::endl;

			std::cout << "***MOB'S TURN***" << std::endl;
			std::cout << std::endl;

			if (diffic == 'e' || diffic == 'E')
			{
				b.AttackMeE();
			}
			else if (diffic == 'm' || diffic == 'M')
			{
				b.AttackMeE();
			}
			else
				b.AttackMeH();
			std::cout << std::endl;

			b.show_BoardOut();
			std::cout << std::endl;

			system("pause");
			std::cout << std::endl;

			turns--;

			if (b.get_DestroyedAi() == terr)
			{
				std::cout << "You have robbed all territories!" << std::endl;
				std::cout << std::endl;
				break;
			}
			else if (b.get_DestroyedMe() == terr)
			{
				std::cout << "All of your territories have been robbed!" << std::endl;
				std::cout << std::endl;
				break;
			}

			turnNum += 1;
		}

		if (b.get_DestroyedAi() > b.get_DestroyedMe())
		{
			std::cout << "You win!" << std::endl;
		}
		else if (b.get_DestroyedAi() < b.get_DestroyedMe())
		{
			std::cout << "You lose!" << std::endl;
		}
		else
		{
			std::cout << "It is a tie!" << std::endl;
		}

		std::cout << std::endl;

		std::cout << "Play again? (y/n) "; std::cin >> again;
		std::cout << std::endl;

		while (((again != 'y') && (again != 'n')) && ((again != 'Y') && (again != 'N')))
		{
			std::cout << "Please enter 'y' or 'n'. "; std::cin >> show;
			std::cout << std::endl;
		}

		if (again == 'y' || again == 'Y')
		{
			continue;
		}
		else
			break;
	}

	return 0;
}



