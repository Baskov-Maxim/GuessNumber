#include <iostream>
#include <ctime>
#include "RandomFunc.h"

int main()
{
	while (true)
	{
		srand(time(NULL));

		std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n";
		short tries = 1;
		int randValue = get_random_value();
		bool guessed = false;

		while (tries < 8)
		{
			int userVlue = 0;

			// User Value Processing
			print_result(userVlue, randValue, tries, guessed);

			if (guessed == 1)
			{
				std::cout << "The correct number was " << randValue << std::endl;
				break;
			}
			if ((guessed == 0) & tries == 8)
				std::cout << "Sorry, you lose. The correct number was " << randValue << std::endl;
		}

		std::cout << "Would you like to play again(y / n) ? ";

		if (!get_answer())	// Checking out of the program
			break;
	}
	return 0;
}