#include <iostream>

int calcfactorial(int number)
{
	if (number == 0)
		return 1;
	else if (number < 0)
	{
		std::cout << "Stop trying to break my code! Please enter a non-negative number next time." << std::endl;
		return 0;
	}
	else
		return number*(calcfactorial(number - 1));
}
