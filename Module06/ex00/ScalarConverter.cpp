#include <ScalarConverter.hpp>

#include <sstream>
#include <iomanip>

static int scalar_atoi(std::string &content)
{
    int newContent;
    std::stringstream l(content);
    
    l >> newContent;
    return newContent;
}

static float scalar_atof(std::string &content)
{
    float newContent;
    std::stringstream l(content);
    
    l >> newContent;
    return newContent;
}

static double scalar_atod(std::string &content)
{
    double newContent;
    std::stringstream l(content);
    
    l >> newContent;
    return newContent;
}

enum dataType {
    _charcater,
    _integer,
    _floatn,
    _doublen,
    _error,
};

static bool checkCharacterValidation(const std::string &content)
{
    if(content.length() != 1)
        return false;
    return true;
}

static bool checkIntegerValidation(const std::string &content){

    int start = 0;


    if(content[start] == '-' || content[start] == '+')
        start = 1;
    while(start < content.length())
    {
        if(!std::isdigit(content[start]))
            return false;
        start++;
    }
    return true;
}

static bool checkDoubleValidation(const std::string &content)
{
    int start = 0;
    bool read = false;
    int decimals = 0;
    if(content == "-inf" || content == "+inf" || content == "nan")
        return false;
    if(content[start] == '-' || content[start] == '+')
        start = 1;
    while(start < content.length())
    {
        if(content.at(start) == '.')
            read = true;
        if(!std::isdigit(content[start]))
            return false;
        if(read && content.at(start) != '.')
            decimals++;
        start++;
    }
    if(decimals < 15)
        return false;
    return true;
}

static bool checkFloatValidation(const std::string &content)
{
    int start = 0;
    bool read = false;
    int decimals = 0;
    if(content == "-inf" || content == "+inf" || content == "nan")
        return false;
    if(content[start] == '-' || content[start] == '+')
        start = 1;
    while(start < content.length())
    {
        if(content.at(start) == '.')
            read = true;
        if(!std::isdigit(content[start]))
            return false;
        if(read && content.at(start) != '.')
            decimals++;
        start++;
    }
    if(decimals > 15)
        return false;
    return true;
}




void ScalarConverter::convert(std::string const &content)
{
    dataType type;
    if(checkCharacterValidation(content))
        type = _charcater;
    else if(checkIntegerValidation(content))
        type = _integer;
    else if(checkDoubleValidation(content))
        type = _doublen;
    else if(checkFloatValidation(content))
        type = _floatn;
    else
        type = _error;

}