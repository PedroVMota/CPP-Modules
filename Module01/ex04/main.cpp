#include "replace.hpp"

int main(int ac, char **av)
{
	std::string to_find = av[2];
	std::string to_replace = av[3];

	// fstream is like a fd.
	std::fstream file(av[1]);
	// ostringstream uses a string buffer that contains a sequance of characters.
	std::ostringstream StringStream;
	//this will be where the content of the infile
	std::string content;



	if(ac != 4)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		std::cerr << "./ex04 <filename> <occurance> <replace>" << std::endl;
		return 1;
	}
	if (to_find.empty() || to_replace.empty() || std::string(av[1]).empty())
	{
		std::cerr << "Some of the arguments are empty." << std::endl;
		return 1;
	}
	if (!file)
	{
		std::cerr << "Error: Opening the file: " << av[1] << std::endl;
		return 1;
	}
	//this read all the content of the file at once.
	StringStream << file.rdbuf();
	// gets the content and convert to string.
	content = StringStream.str();
	if (content.empty())
	{
		std::cerr << "The file is empty ... Please put something inside " << std::endl;
		return 1;
	}
	// this is just a string manipulation.
	replace_content(content, to_find, to_replace);

	//creating the outfile by concatenating the infile with a .replace
	std::ofstream outputFile((std::string(av[1]) + ".replace").c_str());
	if (!outputFile)
	{
		std::cerr << "Error: Opening the replacement file" << std::endl;
		return 1;
	}
	outputFile << content;
	outputFile.close();
	file.close();
	return 0;
}