#include <iostream>


int main()
{

	std::string msg = "Hi THIS IS BRAIN";

	std::string *stringPTR = &msg;
	std::string &stringREF = msg;

	std::cout << "MemoryAddress of \'msg\': " << &msg << std::endl;
	std::cout << "MemoryAddress of \'stringPTR\': " << stringPTR << std::endl;
	std::cout << "MemoryAddress of \'stringREF\': " << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "Value of \'msg\': " << msg << std::endl;
	std::cout << "Value of \'stringPTR\': " << *stringPTR << std::endl;
	std::cout << "Value of \'stringREF\': " << stringREF << std::endl;
	std::cout << std::endl;
	
	msg = "Hi THIS IS BRAIN 2";
	std::cout << "Value of \'msg\': " << msg << std::endl;
	std::cout << "Value of \'stringPTR\': " << *stringPTR << std::endl;
	std::cout << "Value of \'stringREF\': " << stringREF << std::endl;
}