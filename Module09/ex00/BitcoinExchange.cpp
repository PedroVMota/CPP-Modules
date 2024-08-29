#include "./BitcoinExchange.hpp"


template <class Type>
Type convertTo(const std::string &_content)
{
    std::istringstream content(_content);
    Type value;
    try
    {
        content >> value;
        if (content.fail())
            throw std::runtime_error("Conversion failed");
    }
    catch (std::exception &e) { (void)e; };
    return value;
}

/* Get the error stat and returns a string for the error */
const char *errorToString(ERROR error)
{
    switch (error)
    {
    case NEGATIVE:
        return "Negative number not allowed";
    case RANGE:
        return "Value out of range";
    case UNKNOWN:
        return "Unknown error";
    case F_CHARACTER:
        return "'f' character issues";
    case EMPTY:
        return "Empty string";
    case DOT_ERROR:
        return "Dot error";
    default:
        return "Unknown error";
    }
}

std::string removeComment(const std::string &input) {
    size_t commentPos = input.find('#');
    if (commentPos != std::string::npos) {
        return input.substr(0, commentPos);
    }
    return input;
}

bool isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool isValidDay(int month, int day, int year)
{
    static const int daysInMonth[12] = {31, 28, 31, 30, 31, 30,
                                        31, 31, 30, 31, 30, 31};
    if (month < 1 || month > 12)
        return false;
    int maxDays = daysInMonth[month - 1];
    if (month == 2 && isLeapYear(year))
        maxDays = 29;
    return day >= 1 && day <= maxDays;
}

std::string trim(const std::string &str)
{
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}



std::map<string, double> split(const std::string &_line, char delimiter,
                               bool toConvert = false)
{
    std::map<string, double> splitted;
    std::string key_str, value_str;
    std::istringstream keyValueStream(_line);
    std::getline(keyValueStream, key_str, delimiter);
    std::getline(keyValueStream, value_str);
    double Value = 0;
    if (toConvert)
    {
        try
        {
            Value = convertTo<double>(trim(value_str));
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            Value = 0;
        }
    }
    splitted[trim(key_str)] = Value;
    return splitted;
}

bool BitcoinExchange::fetchDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr
            << "Unfortunately, the file couldn't be opened! Could you please "
               "check "
            << "if the file is correct (like data.csv) or if the file exists?\n";
        return false;
    }

    std::string bufferPlacement;
    while (getline(file, bufferPlacement))
    {
        bufferPlacement = trim(bufferPlacement);
        if (bufferPlacement.empty())
            continue;
        std::map<std::string, double> cur = split(bufferPlacement, ',', true);
        _database.insert(cur.begin(), cur.end());
        
    }
    return true;
}

void BitcoinExchange::printDatabase()
{
    std::map<std::string, double>::const_iterator it;
    for (it = _database.begin(); it != _database.end(); ++it)
        std::cout << "Key: " << it->first << ", Value: " << it->second
                  << std::endl;
}

ERROR BitcoinExchange::parseDate(const std::string &date)
{
    
    if (date.size() != 10)
        return DATE_ERROR;
    int dashes = 0;
    for (size_t i = 0; i < date.size(); ++i)
    {
        if (date[i] == '-')
        {
            dashes++;
            if (i != 4 && i != 7)
                return DATE_ERROR;
        }
        else if (!isdigit(date[i]))
            return DATE_ERROR;
    }
    if (dashes != 2)
        return DATE_ERROR;
    std::istringstream dateStream(date);
    int year = 0, month = 0, day = 0;
    char dash1, dash2;
    dateStream >> year >> dash1 >> month >> dash2 >> day;
    if (dateStream.fail() || dateStream.get() != EOF)
        return DATE_ERROR;
    if((dash1 == '-' && dash2 == '-') &&  !isValidDay(month, day, year))
        return DATE_ERROR; 
    return OK;
}

ERROR BitcoinExchange::checkValue(double value)
{
    if (value < 0)
        return NEGATIVE;
    if (value > 2147483647)
        return RANGE;
    return OK;
}

ERROR BitcoinExchange::checkValue(const std::string &s)
{
    bool dot_found = false;
    bool digit_found = false;
    bool f_found = false;

    if (s.empty())
        return EMPTY;
    if (s.size() == 1 && (s[0] == 'f' || s[0] == '.'))
        return UNKNOWN;
    size_t start = 0;
    if (s[0] == '+' || s[0] == '-')
        start = 1;
    for (size_t index = start; index < s.size(); ++index)
    {
        char ch = s[index];
        if (ch == '.')
        {
            if (dot_found)
                return DOT_ERROR;
            dot_found = true;
        }
        else if (ch == 'f')
        {
            if (f_found || index != s.size() - 1)
                return F_CHARACTER;
            
            f_found = true;
        }
        else if (std::isdigit(ch))
            digit_found = true;
        else
            return UNKNOWN;
    }
    if (!digit_found)
        return UNKNOWN;
    return OK;
}

int BitcoinExchange::daysSinceEpoch(int year, int month, int day)
{
    static const int daysInMonth[12] = {31, 28, 31, 30, 31, 30,
                                        31, 31, 30, 31, 30, 31};
    int days = 0;
    for (int y = 0; y < year; ++y)
        days += (isLeapYear(y) ? 366 : 365);
    for (int m = 0; m < month - 1; ++m)
    {
        days += daysInMonth[m];
        if (m == 1 && isLeapYear(year))
            days++; 
    }
    days += day;
    return days;
}

int BitcoinExchange::daysBetweenDates(const std::string &date1, const std::string &date2)
{
    int *date1Parts = getDate(date1);
    int *date2Parts = getDate(date2);
    if (!date1Parts || !date2Parts)
    {
        std::cerr << "Invalid dates provided." << std::endl;
        return -1; 
    }
    int days1 = daysSinceEpoch(date1Parts[0], date1Parts[1], date1Parts[2]);
    int days2 = daysSinceEpoch(date2Parts[0], date2Parts[1], date2Parts[2]);
    return abs(days2 - days1);
}

int *BitcoinExchange::getDate(const std::string &date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cerr << "Invalid date format." << std::endl;
        return NULL;
    }
    static int dateParts[3];
    std::istringstream dateStream(date);
    char dash;
    dateStream >> dateParts[0] >> dash >> dateParts[1] >> dash >> dateParts[2];
    if (dateStream.fail() || dateStream.get() != EOF)
    {
        std::cerr << "Error parsing date." << std::endl;
        return NULL;
    }
    return dateParts;
}

map::iterator BitcoinExchange::getClosest(string date)
{
    int *dateParts = getDate(date);
    if (!dateParts)
        return _database.end();
    int days = daysSinceEpoch(dateParts[0], dateParts[1], dateParts[2]);
    int minDiff = INT_MAX;
    map::iterator it;
    map::iterator closest = _database.end();
    for (it = _database.begin(); it != _database.end(); ++it)
    {
        if (it->first == "date")
            continue;
        int *curDateParts = getDate(it->first);
        if (!curDateParts)
            continue;
        int curDays = daysSinceEpoch(curDateParts[0], curDateParts[1], curDateParts[2]);
        int diff = abs(curDays - days);
        if(curDays > abs(days))
            break;
        if (diff < minDiff)
        {
            minDiff = diff;
            closest = it;
        }
    }
    return closest;
}

BitcoinExchange::BitcoinExchange()
{
    if (!this->fetchDatabase("data.csv"))
    {
        std::cerr << "Error fetching database." << std::endl;
        throw std::runtime_error("Error fetching database.");
    }
}

int BitcoinExchange::printError(ERROR error, int nLine, string &line, map &m) {
    switch (error) {
    case NEGATIVE:
        std::cerr << "Line: " << nLine << RED << " Error: " << errorToString(error) << ": " << m.begin()->second << RESET << std::endl;
        break;
    case RANGE:
        std::cerr << "Line: " << nLine << RED << " Error: " << errorToString(error) << ": " << m.begin()->second << RESET << std::endl;
        break;
    case UNKNOWN:
        std::cerr << "Line: " << nLine << RED << " Error: " << errorToString(error) << ": " << line << RESET << std::endl;
        break;
    case F_CHARACTER:
        std::cerr << "Line: " << nLine << RED << " Error: " << errorToString(error) << ": " << line << RESET << std::endl;
        break;
    case EMPTY:
        std::cerr << "Line: " << nLine << RED << " Error: " << errorToString(error)  << RESET << std::endl;
        break;
    case DOT_ERROR:
        std::cerr << "Line: " << nLine << RED << " Error: " << errorToString(error) << ": " << line << RESET << std::endl;
        break;
    case DATE_ERROR:
        std::cerr << "Line: " << nLine << RED << " Error: " << errorToString(error) << ": " << m.begin()->first << RESET << std::endl;
        break;
    default:
        std::cerr << "Line: " << nLine << RED << " Error: " << errorToString(UNKNOWN) << RESET << std::endl;
        break;
    }
    return error;
}

bool BitcoinExchange::handleErrorAndContinue(ERROR error, int nline, string sline, std::map<std::string, double> &cur) {
    if (error != OK) {
        this->printError(error, nline, sline, cur);
        return true;
    }
    return false;
}

void BitcoinExchange::Analyze(const std::string &input)
{
    file inputFile(input.c_str());

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening input file." << std::endl;
        return;
    }
    std::string bufferPlacement;
    int line = 0;
    while (getline(inputFile, bufferPlacement))
    {
        line++;
        bufferPlacement = trim(bufferPlacement);
        bufferPlacement = removeComment(bufferPlacement);
        int numberofPipes = 0;
        if(bufferPlacement.empty())
            continue;
        for (size_t i = 0; i < bufferPlacement.size(); ++i)
            if (bufferPlacement[i] == '|')
                numberofPipes++;
        if(numberofPipes != 1)
        {
            std::cerr << "Line: " << line << RED << " Error: Number of arguments " << bufferPlacement << RESET << std::endl;
            continue;
        }
        std::map<std::string, double> cur = split(bufferPlacement, '|', true);
        if (bufferPlacement.empty() || cur.size() == 0)
            continue;
        if ("date" == cur.begin()->first)
            continue;
        if (handleErrorAndContinue(parseDate(cur.begin()->first), line, bufferPlacement, cur))
            continue;
        string valr_str = trim(bufferPlacement.substr(bufferPlacement.find_first_of('|') + 1));
        if (handleErrorAndContinue(checkValue(valr_str), line, bufferPlacement, cur))
            continue;
        if(handleErrorAndContinue(checkValue(cur.begin()->second), line, bufferPlacement, cur))
            continue;
        map::iterator closest = getClosest(cur.begin()->first);
        if (closest == _database.end())
        {
            std::cerr << "Error: Couldn't find the closest date." << std::endl;
            continue;
        }
        std::cout << GREEN << "(" << cur.begin()->first << ", " << cur.begin()->second << ")" << RESET << " -> "
                  << YELLOW << "(" << closest->first << ", " << closest->second << ")" << RESET << " -> "
                  << CYAN << closest->second * cur.begin()->second << RESET << std::endl;
    }
}