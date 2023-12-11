#include <iostream>
#include <string>

class Contact
{
private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;

public:
	Contact();
	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
	std::string getPhoneNumber();
	std::string getSecret();
	bool setFirstName(std::string str);
	bool setLastName(std::string str);
	bool setNickName(std::string str);
	bool setPhoneNumber(std::string str);
	bool setSecret(std::string str);
};
