#include <iostream>
#include <string>
#include "Contact.hpp"

void eraselines(int count) {
    if (count > 0) {
        std::cout << "\x1b[2k"; // delete current line
        // i=1 because we included the first line
        for (int i = 1; i < count; i++) {
            std::cout
            << "\x1b[1a" // move cursor up one
            << "\x1b[2k"; // delete the entire line
        }
        std::cout << "\r"; // resume the cursor at beginning of line
    }
}


Contact::Contact()
{
	_first_name = "";
	_last_name = "";
	_nickname = "";
	_phone_number = "";
	_darkest_secret = "";
}

std::string Contact::getFirstName()
{
	return _first_name;
}

std::string Contact::getLastName()
{
	return _last_name;
}

std::string Contact::getNickName()
{
	return _nickname;
}

std::string Contact::getPhoneNumber()
{
	return _phone_number;
}

std::string Contact::getSecret()
{
	return _darkest_secret;
}

bool Contact::setFirstName(std::string str)
{
	if(str.empty())
	{
		std::cout << "Error: Empty field" << std::endl;
		return true;
	}
	_first_name = str;
	eraselines(1);
	return false;
}

bool Contact::setLastName(std::string str)
{
	if(str.empty())
	{
		std::cout << "Error: Empty field" << std::endl;
		return true;
	}
	_last_name = str;
	eraselines(1);
	return false;
}

bool Contact::setNickName(std::string str)
{
	if(str.empty())
	{
		std::cout << "Error: Empty field" << std::endl;
		return true;
	}
	_nickname = str;
	eraselines(1);
	return false;
}

bool Contact::setPhoneNumber(std::string str)
{
	if(str.empty())
	{
		std::cout << "Error: Empty field" << std::endl;
		return true;
	}
	_phone_number = str;
	eraselines(1);
	return false;
}

bool Contact::setSecret(std::string str)
{
	if(str.empty())
	{
		std::cout << "Error: Empty field" << std::endl;
		return true;
	}
	_darkest_secret = str;
	eraselines(1);
	return false;
}
