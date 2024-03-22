#include <iostream>
#include <string>

class ScalarConverter{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &other);
        ScalarConverter &operator=(ScalarConverter const &other);

        
    public:
        ~ScalarConverter();
        static void convert(std::string const &content);
};