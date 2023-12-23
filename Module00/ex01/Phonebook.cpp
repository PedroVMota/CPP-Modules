#include "Phonebook.hpp"
#include <string>
#include <iostream>
#include <limits>

Phonebook::Phonebook()
{
	_index = 0;
	for (int i = 0; i < 8; i++)
		_contact[i] = Contact();
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



void Phonebook::add()
{
	if (_index == 8)
		_index = 0;
	int err = 0;
	std::string olddata[5];
	std::string input;

	olddata[0] = _contact[_index].getFirstName();
	olddata[1] = _contact[_index].getLastName();
	olddata[2] = _contact[_index].getNickName();
	olddata[3] = _contact[_index].getPhoneNumber();
	olddata[4] = _contact[_index].getSecret();

	if(err == 0)
	{
		std::cout << "\033c";
		std::cout << "Enter first name: ";
		std::getline(std::cin, input);
		if(_contact[_index].setFirstName(input))
			err = 1;
	}
	if(err == 0)
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, input);
		if(_contact[_index].setLastName(input))
			err = 1;
	}
	if(err == 0)
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, input);
		if(_contact[_index].setNickName(input))
			err = 1;
	}
	if(err == 0)
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, input);
		if(_contact[_index].setPhoneNumber(input))
			err = 1;
	}
	if(err == 0)
	{
		std::cout << "Tell me want you really desire: ";
		std::getline(std::cin, input);
		if(_contact[_index].setSecret(input))
			err = 1;
	}
	err == 1 ? _contact[_index].setFirstName(olddata[0]) : 0;
	err == 1 ? _contact[_index].setLastName(olddata[1]) : 0;
	err == 1 ? _contact[_index].setNickName(olddata[2]) : 0;
	err == 1 ? _contact[_index].setPhoneNumber(olddata[3]) : 0;
	err == 1 ? _contact[_index].setSecret(olddata[4]) : 0;
	_index += 1;
}

void Phonebook::search()
{
	// Show all the contacts in the phonebook
	std::cout << "┌──────────────────────────────────────────┐\n";
	for (int i = 0; i < 8; i++)
	{
		if(_contact[i].getFirstName().empty())
			break ;
		std::cout << "│    " << i << "    │";
		std::cout << std::setw(10) << trim(_contact[i].getFirstName(), 9)<< "│";
		std::cout << std::setw(10) << trim(_contact[i].getLastName(), 9) << "│";
		std::cout << std::setw(10) << trim(_contact[i].getNickName(), 9) << "│\n";
	}
	std::cout << "└──────────────────────────────────────────┘\n";


	// Ask the user to select a contact
	std::string userInput;
	std::cout << "Enter index: ";

	int index = -1;
	std::cin >> index;
	if (std::cin.fail())
		std::cerr << "The input given is not a number" << std::endl;
	else if(index < 0 || index > 7)
		std::cerr << "The given input is out of range" << std::endl;
	else
	{
		std::cout << "First Name:" << _contact[index].getFirstName() << std::endl;
		std::cout << "Last Name:" << _contact[index].getLastName() << std::endl;
		std::cout << "Nickname:" << _contact[index].getNickName() << std::endl;
		std::cout << "PhoneNumber:" << _contact[index].getPhoneNumber() << std::endl;
		std::cout << "Deppest Secrete:" << _contact[index].getSecret() << std::endl;
	}
	std::cin.clear();
	std::cin.ignore(2147483648, '\n');
}

void Phonebook::add_test_data()
{
	for(int i = 0; i < 8; i++)
	{
		_contact[i].setFirstName("Automatic function feature Fill");
		_contact[i].setLastName("Automatic function feature Fill");
		_contact[i].setNickName("Automatic function feature Fill");
		_contact[i].setPhoneNumber("9999999999");
		_contact[i].setSecret("Automatic function feature Fill");
	}
}