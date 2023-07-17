#include <iostream>

class Contacts{
	private:
		std::string _PhoneNumber;
		std::string _FirstName;
		std::string _Lastname;
		std::string _NickName;
		std::string _Secret;
	public:
		void Contacts::FirstNameSet(std::string str){
			this->_FirstName = str;
		}
		void Contacts::LastNameSet(std::string str){
			this->_Lastname = str;
		}
		void Contacts::NickNameSet(std::string str){
			this->_NickName = str;
		}
		void Contacts::SecretSet(std::string str){
			this->_Secret = str;
		}
		void Contacts::PhoneNumberSet(std::string str){
			this->_PhoneNumber = str;
		}
};


class Phonebook{

	public:
		void add(void);
	private:
		Contacts _Contacts[8];
		void err(std::string ErrMsg, std::int32_t index);
};

void Phonebook::err(std::string ErrMsg, int index)
{
	std::cout << ErrMsg;
	this->_Contacts[index].FirstNameSet("");
	this->_Contacts[index].LastNameSet("");
	this->_Contacts[index].NickNameSet("");
	this->_Contacts[index].PhoneNumberSet("");
	this->_Contacts[index].SecretSet("");
}

void Phonebook::add(void)
{
	std::string String;
	std::int32_t index;


	std::cout << "Index Contact" << std::endl;
	std::cin >> index;
	std::cout << "First Name" << std::endl;
	std::cin >> String;
	if(String.length() == 0)
	{
		this->err("First cannot be empty\n", index);
		return ;
	}
	
}