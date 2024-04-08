#include <iostream>
#include <string>
#include <limits.h>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &other);
    ScalarConverter &operator=(ScalarConverter const &other);

    bool isNotNumericOrInifity(std::string const &content) const;
    bool isJustInfinityFloat(std::string const &content) const;
    bool isJustInfinityDoule(std::string const &content) const;
    bool isNan(std::string const &content) const;
    bool isSignal(std::string const &content) const;

    bool checkCharacterValidation(const std::string &content) const;
    bool checkIntegerValidation(const std::string &content) const;
    bool checkFloatValidation(const std::string &content) const;
    bool checkDoubleValidation(const std::string &content) const;
    ~ScalarConverter();


public:
    static void convert(std::string const &content);
};