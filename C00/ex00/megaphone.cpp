#include <iostream>

void megaphone(char *s)
{
	int i = 0;

	while (s[i])
	{
		char letter = s[i];
		if(letter >= 'a' && letter <= 'z')
			letter = s[i] - 32; 
		if(letter >= 'Z' && letter <= 'Z')
			letter = s[i] + 32; 
		std::cout << letter;
		i++;
	}
}


int main(int ac, char **str)
{
	if(ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	else
	{
		for (int x = 1; str[x]; x++)
			megaphone(str[x]);
		std::cout << std::endl;
	}
	
}