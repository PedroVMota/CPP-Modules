#include "Phonebook.hpp"
#include <string>
#include <iostream>
#include <limits>

int ConvertStringToInt(std::string str)
{
	int result = 0;
	for (std::size_t i = 0; i < str.size(); i++)
	{
		if (std::isdigit(str[i]))
			result = result * 10 + (str[i] - '0');
		else
			throw std::invalid_argument("Invalid input");
	}
	return result;
}

static std::string trim(const std::string &str, std::size_t width)
{
	std::string content = "";
	for (std::size_t i = 0; i < str.size() && i < width; i++)
	{
		content += str[i];
		if (i == width - 1)
			content += ".";
	}
	for (std::size_t i = content.size(); i < width + 1; i++)
		content += " ";
	return content;
}

Phonebook::Phonebook()
{
	_index = 0;
	for (int i = 0; i < 8; i++)
		_contact[i] = Contact();
}

void Phonebook::prompt()
{
	const char reset[] = "\033[0m";
	const char bold[] = "\033[1m";
	const char colorCyan[] = "\033[36m";
	const char colorYellow[] = "\033[33m";

	std::cout << "+------------------------------------------------------------------+\n";
	std::cout << "| " << bold << colorCyan << "Welcome to My Awesome Phonebook" << reset << "                                  |\n";
	std::cout << "+------------------------------------------------------------------+\n";
	std::cout << "| "
			  << "Commands: " << bold << colorYellow << "ADD" << reset << ", " << bold << colorYellow << "SEARCH" << reset << ", " << bold << colorYellow << "EXIT" << reset << "                                      |\n";
	std::cout << "+------------------------------------------------------------------+\n";

	// Process the user input as needed
}

static bool CheckParamters(std::string *newdata)
{
	for (int i = 0; i < 5; i++)
	{
		if (newdata[i].empty())
		{
			std::cout << "Error: Empty field" << std::endl;
			return true;
		}
	}
	return false;
}

void Phonebook::add()
{
	if (_index == 8)
		_index = 0;
	int err = 0;
	std::string olddata[5];
	std::string newdata[5];
	olddata[0] = _contact[_index].getFirstName();
	olddata[1] = _contact[_index].getLastName();
	olddata[2] = _contact[_index].getNickName();
	olddata[3] = _contact[_index].getPhoneNumber();
	olddata[4] = _contact[_index].getSecret();

	std::cout << "Enter first name: ";
	std::getline(std::cin, newdata[0]);
	std::cout << "Enter last name: ";
	std::getline(std::cin, newdata[1]);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, newdata[2]);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, newdata[3]);
	std::cout << "Tell me want you really desire: ";
	std::getline(std::cin, newdata[4]);

	if (CheckParamters(newdata))
		err = 1;
	if (err == 0)
	{
		if(_contact[_index].setFirstName(newdata[0]))
			err = 1;
		if(_contact[_index].setLastName(newdata[1]))
			err = 1;
		if(_contact[_index].setNickName(newdata[2]))
			err = 1;
		if(_contact[_index].setPhoneNumber(newdata[3]))
			err = 1;
		if(_contact[_index].setSecret(newdata[4]))
			err = 1;
		_index++;
	}
	if(err == 1)
	{
		_contact[_index].setFirstName(olddata[0]);
		_contact[_index].setLastName(olddata[1]);
		_contact[_index].setNickName(olddata[2]);
		_contact[_index].setPhoneNumber(olddata[3]);
		_contact[_index].setSecret(olddata[4]);
	}
}

/* Function setw
 * Sets the width of the next field to be printed
 * std::setw(10) << std::left << std::setfill(' ') << trim(_contact[i].getFirstName(), 9)
 * ^^^^^^^^^^^^
 * This sets the width of the next field to be printed to 10
 *
 * Function left
 * Sets the alignment of the next field to be printed to left
 * std::setw(10) << std::left << std::setfill(' ') << trim(_contact[i].getFirstName(), 9)
 * ^^^^^^^^^^^^^
 * This sets the alignment of the next field to be printed to left
 *
 * Function setfill
 * Sets the fill character of the next field to be printed to ' '
 * std::setw(10) << std::left << std::setfill(' ') << trim(_contact[i].getFirstName(), 9)
 * ^^^
 */

void Phonebook::search()
{
	const char reset[] = "\033[0m";
	const char bold[] = "\033[1m";
	const char colorCyan[] = "\033[36m";
	const char colorYellow[] = "\033[33m";

	// Show all the contacts in the phonebook
	std::cout << "+------------------------------------------------+\n";
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|    " << i << "    | ";
		std::cout << std::setw(10) << std::left << std::setfill(' ') << trim(_contact[i].getFirstName(), 9) << " | ";
		std::cout << std::setw(10) << std::left << std::setfill(' ') << trim(_contact[i].getLastName(), 9) << " | ";
		std::cout << std::setw(10) << std::left << std::setfill(' ') << trim(_contact[i].getNickName(), 9) << " | \n";
	}
	std::cout << "+------------------------------------------------+\n";\

	// Ask the user to select a contact
	std::string userInput;
	std::cout << "Enter index: ";

}

void Phonebook::add_test_data()
{
	for(int i = 0; i < 8; i++)
	{
		_contact[i].setFirstName("test");
		_contact[i].setLastName("test");
		_contact[i].setNickName("test");
		_contact[i].setPhoneNumber("test");
		_contact[i].setSecret("test");
	}
}