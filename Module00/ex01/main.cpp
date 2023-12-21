#include "Phonebook.hpp"
#include <iostream>
#include <string>
#include <iostream>
#include <limits>

/*
	Method front
	- Returns a reference to the first element in the vector.

	Method back
	- Returns a reference to the last element in the vector.

	Method erase
	- Removes from the vector either a single element (position) or a range of elements ([first,last)).
	- This effectively reduces the container size by the number of elements removed, which are destroyed.
*/

std::string trimString(std::string str)
{
	int start = -1;
	if (str.empty())
		return str;
	std::string trimmedStr;
	while (std::isspace(str[++start]))
		start++;
	while (!std::isspace(str[start]))
		trimmedStr += str[start++];
	return str;
}

std::string Input(std::string promptmsg)
{
	if (!promptmsg.empty())
		std::cout << promptmsg;
	else
		std::cout << "Input: ";
	std::string userInput = std::string();
	std::getline(std::cin, userInput);
	if(std::cin.eof())
		return "EXIT";
	while (userInput.empty())
	{
		std::cout << "Error: Empty field" << std::endl;
		std::cout << "Input: ";
		std::cout << promptmsg;
		std::getline(std::cin, userInput);
		if(std::cin.eof())
			return "EXIT";
	}
	return trimString(userInput);
}

int main(void)
{
	Phonebook phonebook;
	std::string userInput;


	///STUB - This function is just to fill all the contact list at once.
	phonebook.add_test_data();

	userInput = Input("Enter command: ");
	while (userInput != "EXIT" && userInput != "exit")
	{
		if (userInput == "ADD" || userInput == "add")
			phonebook.add();
		else if (userInput == "SEARCH" || userInput == "search")
			phonebook.search();
		else
			std::cout << "Error: Invalid command" << std::endl;
		userInput = Input("Enter command: ");
	}
	return 0;
}