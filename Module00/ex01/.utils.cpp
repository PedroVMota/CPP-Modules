#include <iostream>
#include <string>

bool isSpace(char c){
	return (
		c == ' '  ||
		c == '\t' ||
		c == '\n' ||
		c == '\r' ||
		c == '\f' ||
		c == '\v'
	);
}

bool checkWhiteSpaces(const std::string &input)
{
	for (std::string::size_type i = 0; i < input.length(); ++i)
		if (!isSpace(input[i]))
			return false;
	return true;
}

bool isNumber(std::string const &str)
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
		if (*it < '0' || *it > '9')
			return false;
	return true;
}

bool isSomethingWrong(const std::string text, bool isPhoneNumber)
{
	if(text.empty() || checkWhiteSpaces(text))
	{
		std::cerr << "Input value is empty" << std::endl;
		return true;
	}
	if(isPhoneNumber && !isNumber(text))
	{
		std::cerr << "The Phone number must be all numbers." << std::endl;
		return true;
	}
	return false;
}

std::string removeWhiteSpaces(std::string str)
{
	std::string newStr = "";
	int start = -1;
	while(std::isspace(str[++start]))
		start++;
	while(start < (int)str.size())
		newStr += str[start++];
	return newStr;
}