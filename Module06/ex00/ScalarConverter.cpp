#include <ScalarConverter.hpp>

#include <sstream>
#include <iomanip>
#include <iostream>
#include <cmath>

// ============================================================ STATIC FUNCTIONS ============================================================
static int scalar_atoi(std::string const &content)
{
    int newContent;
    std::stringstream l(content);

    l >> newContent;
    return newContent;
}

static float scalar_atof(std::string const &content)
{
    float newContent;
    std::stringstream l(content);

    l >> newContent;
    return newContent;
}

static double scalar_atod(std::string const &content)
{
    double newContent;
    std::stringstream l(content);

    l >> newContent;
    return newContent;
}
// ============================================================ STATIC FUNCTIONS ============================================================

// ============================================================ CONSTRUCTOR ============================================================
ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
// ============================================================ CONSTRUCTOR ============================================================

/*
    ScalarConverter::isNotNumericOrInifity:

    This function checks if the content is not a number or infinity.
    It returns true if the content is not a number or infinity, otherwise it returns false.
*/
bool ScalarConverter::isNotNumericOrInifity(std::string const &content) const
{
    return (this->isJustInfinityDoule(content) || this->isJustInfinityFloat(content) || this->isNan(content));
}

/*
    ScalarConverter::isJustInfinityFloat:

    This function checks if the content is just infinity.
    It returns true if the content is just infinity, otherwise it returns false.
*/
bool ScalarConverter::isJustInfinityFloat(std::string const &content) const
{
    return (content == "-inff" || content == "+inff");
}

/*
    ScalarConverter::isJustInfinityDoule:

    This function checks if the content is just infinity.
    It returns true if the content is just infinity, otherwise it returns false.
*/

bool ScalarConverter::isJustInfinityDoule(std::string const &content) const
{
    return (content == "-inf" || content == "+inf");
}

/*
    ScalarConverter::isNan:

    This function checks if the content is NaN.
    It returns true if the content is NaN, otherwise it returns false.
*/

bool ScalarConverter::isNan(std::string const &content) const
{
    return (content == "nan" || content == "NaN" || content == "NAN");
}

/*
    ScalarConverter::isSignal:

    This function checks if the content is a signal.
    It returns true if the content is a signal, otherwise it returns false.
*/

bool ScalarConverter::isSignal(std::string const &content) const
{
    return (content == "-" || content == "+");
}

enum dataType
{
    _charcater,
    _integer,
    _floatn,
    _doublen,
    _error,
};

bool ScalarConverter::checkCharacterValidation(const std::string &content) const
{
    if (this->isNotNumericOrInifity(content))
        return false;
    if (content.length() != 1)
        return false;
    return true;
}

bool ScalarConverter::checkIntegerValidation(const std::string &content) const
{

    size_t start = 0;

    if(content[start] == '+' || content[start] == '-')
        start = 1;
    if (this->isSignal(content))
        start = 1;
    while (start < content.length())
    {
        if (!std::isdigit(content[start]))
            return false;
        start++;
    }

    return true;
}

bool ScalarConverter::checkDoubleValidation(const std::string &content) const
{
    size_t start = 0;
    bool read = false;
    int decimals = 0;
    if (this->isJustInfinityDoule(content) || this->isNan(content))
        return true;
    if (this->isSignal(content))
        start = 1;
    while (start < content.length())
    {
        if (content.at(start) == '.')
        {
            read = true;
            start++;
        }
        if (!std::isdigit(content[start]))
            return false;
        if (read && content.at(start) != '.')
            decimals++;
        start++;
    }
    if (decimals < 8)
        return false;
    return true;
}

bool ScalarConverter::checkFloatValidation(const std::string &content) const
{
    size_t start = 0;
    bool read = false;
    int decimals = 0;
    if (this->isJustInfinityFloat(content) || this->isNan(content))
        return true;
    if (this->isSignal(content))
        start = 1;
    while (start < content.length())
    {
        if (content.at(start) == '.')
        {
            read = true;
            start++;
        }
        if (!std::isdigit(content[start]))
            return false;
        if (read && content.at(start) != '.')
            decimals++;
        start++;
    }
    if (decimals > 8)
        return false;
    if (content[content.length() - 1] != 'f' || content[content.length() - 1] == 'f')
        return true;
    return true;
}

void showChar(std::string const &content, bool isChar = true)
{
    if (isChar == false)
    {
        try
        {
            int Integer = scalar_atoi(content);
            if (Integer > 122 || Integer < 0)
            {
                std::cout << "Char: impossible\n";
                return;
            }
            if (std::isprint(Integer))
                std::cout << "Char: '" << static_cast<char>(Integer) << "'\n";
            else
                std::cout << "Char: Non displayable\n";
        }
        catch (std::exception &e)
        {
            std::cout << "Fodase\n";
        }
    }
    else
    {
        if (content.length() == 1)
            std::cout << "Char: '" << content[0] << "'\n";
        else
            std::cout << "Char: impossible\n";
    }
}

void showInt(std::string const &content)
{
    int i;
    try
    {
        if (content == "-inf" || content == "+inf" || content == "nan" || content == "-inff" || content == "+inff")
        {
            std::cout << "Int: impossible\n";
            return;
        }
        if (!std::isdigit(content[0]) && content[0] != '-' && content[0] != '+')
        {
            std::cout << "Int: " << static_cast<int>(content[0]) << "\n";
            return;
        }
        else
            i = scalar_atoi(content);
        if (i == INT_MAX || i == INT_MIN)
        {
            std::cout << "int: impossible\n";
            return;
        }
        std::cout << "int: " << i << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Int: impossible\n";
    }
}

void showFloat(std::string const &content)
{
    float f;
    try
    {
        if (!std::isdigit(content[0]) && content != "-inff" && content != "+inff" && content != "nan" && content != "-inf" && content != "+inf" && content[0] != '-' && content[0] != '+')
        {
            std::cout << "Float: " << static_cast<float>(content[0]) << ".0f\n";
            return;
        }
        f = scalar_atof(content);
        if (content != "-inff" && content != "+inff" && content != "nan" && content != "-inf" && content != "+inf")
            std::cout << "Float: " << std::fixed << std::setprecision(8) << f << "\n";
        else
        {
            if (content == "-inff" || content == "-inf")
                std::cout << "Float: " << static_cast<float>(-INFINITY) << "\n";
            else if (content == "+inff" || content == "+inf")
                std::cout << "Float: " << static_cast<float>(INFINITY) << "\n";
            else
                std::cout << "Float: nanf\n";
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Float: impossible\n";
    }
}

void showDouble(std::string const &content)
{
    double d;
    try
    {
        if (!std::isdigit(content[0]) && content != "-inf" && content != "+inf" && content != "nan" && content != "-inff" && content != "+inff"  && content[0] != '-' && content[0] != '+')
        {
            std::cout << "Float: " << static_cast<float>(content[0]) << ".0\n";
            return;
        }
        d = scalar_atod(content);
        if (content != "-inf" && content != "+inf" && content != "nan" && content != "-inff" && content != "+inff")
            std::cout << "Double: " << std::fixed << std::setprecision(8) << d << "\n";
        else
        {
            if (content == "-inf" || content == "-inff")
                std::cout << "Double: " << static_cast<double>(-INFINITY) << "\n";
            else if (content == "+inf" || content == "+inff")
                std::cout << "Double: " << static_cast<double>(INFINITY) << "\n";
            else
                std::cout << "Double: nan\n";
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Double: impossible\n";
    }
}

void ScalarConverter::convert(std::string const &content)
{
    dataType type;

    ScalarConverter sc;
    if (sc.checkIntegerValidation(content))
        type = _integer;
    else if (sc.checkDoubleValidation(content))
        type = _doublen;
    else if (sc.checkFloatValidation(content))
        type = _floatn;
    else if (sc.checkCharacterValidation(content))
        type = _charcater;
    else
        type = _error;
    switch (type)
    {
    case _error:
        std::cout << "Error: Invalid input the input must be a literal ./Scallar <Char | Integer | Float | Double >\n";
        return;
        break;
    case _integer:
        std::cout << "Type: integer\n";
        break;
    case _floatn:
        std::cout << "Type: Float\n";
        break;
    case _doublen:
        std::cout << "Type: Double\n";
        break;
    case _charcater: // Add this case
        std::cout << "Type: Character\n";
        break;
    }
    showChar(content, (type == _charcater));
    showInt(content);
    showFloat(content);
    showDouble(content);
}