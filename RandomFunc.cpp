#include <iostream>

int get_random_value()
{
	int newNum = rand() % 100;

	return newNum;
}

int get_user_value()
{
	int userNum;

	while (true)
	{
		std::cin >> userNum;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "It's not a number.\n";
			continue;
		}
		else
			std::cin.ignore(32767, '\n');
			return userNum;
	}
}

// User Value Processing
void print_result(int& userValue, const int randValue, short& tries, bool& guessed)
{

	std::cout << "Guess #" << tries << ": ";
	userValue = get_user_value();

	if (userValue > randValue)
	{
		std::cout << "Your guess is too high.\n";
		guessed = 0;
		tries++;
	}
	else if (userValue < randValue)
	{
		std::cout << "Your guess is too low.\n";
		guessed = 0;
		tries++;
	}
	else if  (userValue == randValue)
	{
		std::cout << "Correct!You win!\n";
		guessed = 1;
	}

}

// Checking out of the program
bool get_answer()
{
	char choose;

	while (true)
	{
		std::cin >> choose;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "It's not a number.\n";
			continue;
		}
		else
		{
			std::cin.ignore(32767, '\n');
			break;
		}
	}

	switch (choose)
	{
		case 'n':
		case 'N':
			return 0;
		case 'y':
		case 'Y':
			return 1;
	}
}