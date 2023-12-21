#include <iostream>
#include <string>
#include "Contact.hpp"

bool isSomethingWrong(const std::string text, bool isPhoneNumber);

Contact::Contact()
{
	_first_name = "";
	_last_name = "";
	_nickname = "";
	_phone_number = "";
	_darkest_secret = "";
}

std::string Contact::getFirstName() { return _first_name; }
std::string Contact::getLastName() { return _last_name; }
std::string Contact::getNickName() { return _nickname; }
std::string Contact::getPhoneNumber() { return _phone_number; }
std::string Contact::getSecret() { return _darkest_secret; }



bool Contact::setFirstName(std::string str)
{
	std::cout << "\033c";
	if(isSomethingWrong(str, false))
		return true;
	_first_name = str;
	return false;
}

bool Contact::setLastName(std::string str)
{
	std::cout << "\033c";
	if(isSomethingWrong(str, false))
		return true;
	_last_name = str;
	return false;
}

bool Contact::setNickName(std::string str)
{
	std::cout << "\033c";
	if(isSomethingWrong(str, false))
		return true;
	_nickname = str;
	return false;
}

bool Contact::setPhoneNumber(std::string str)
{
	std::cout << "\033c";
	if(isSomethingWrong(str, true))
		return true;
	_phone_number = str;
	return false;
}

bool Contact::setSecret(std::string str)
{
	std::cout << "\033c";
	if(isSomethingWrong(str, false))
		return true;
	_darkest_secret = str;
	return false;
}
