#include "BitcoinExchange.hpp"

long BitcoinExchange::dateToDays(int year, int month, int day) {
    return year * 365 + month * 30 + day;
}

long BitcoinExchange::dateDifference(const BlockChain &a, const BlockChain &b) {
    int daysA = dateToDays(a.year, a.month, a.day);
    int daysB = dateToDays(b.year, b.month, b.day);
    return std::abs(daysA - daysB);
}

static void trimmed(std::string &str)
{
    std::string::size_type first = str.find_first_not_of(" \t\n\r\f\v");
    std::string::size_type last = str.find_last_not_of(" \t\n\r\f\v");
    if (first == std::string::npos)
        str.clear();
    else
        str = str.substr(first, last - first + 1);
}

long toInt(std::string &field)
{
    std::istringstream iss(field);
    long num;

    if (!(iss >> num))
        throw std::runtime_error("Failed to convert string to integer");
    return num;
}

double toDouble(std::string &field)
{
    std::istringstream iss(field);
    double num;

    if (!(iss >> num))
        throw std::runtime_error("Failed to convert string to integer");
    return num;
}

static void getData(std::string const &file, std::vector<std::string> &matrix)
{
    std::ifstream f(file.c_str()); // Opening the file
    std::string line;              // the current line.
    if (!f.is_open())
        throw std::runtime_error("Error opening the file.... Shutting down");
    while (std::getline(f, line))
        matrix.push_back(line);
    f.close();
}

static bool isValidDate(std::string const &date)
{
    std::string day, month, year;
    std::istringstream iss(date);

    std::getline(iss, year, '-');
    std::getline(iss, month, '-');
    std::getline(iss, day);
    for (size_t i = 0; i < year.length(); i++)
        if (year[i] < '0' && year[i] > '9')
            return false;
    for (size_t i = 0; i < month.length(); i++)
        if (month[i] < '0' && month[i] > '9')
            return false;
    for (size_t i = 0; i < day.length(); i++)
    {
        if(day.length() > 2)
            return false;
        if ((int)day[i] < 48 && (int)day[i] > 57)
            return false;
    }
    long t = toInt(day);
    if (t < 0 || t > 31)
        return false;
    t = toInt(month);
    if (t < 0 || t > 12 || (t == 2 && toInt(day) > 28))
        return false;
    t = toInt(year);
    if (t < 2009 || t > 2022)
        return false;
    return true;
}

BlockChain convertToDate(std::string const &_date, std::string &value)
{
    BlockChain database;
    std::istringstream iss(_date);
    std::string text;
    database.day = 0;
    database.month = 0;
    database.year = 0;
    try
    {
        database.value = toDouble(value);
    }
    catch (std::exception &e)
    {
        std::cerr << "BitcoinExchange Error: " << e.what() << "\n";
    }
    getline(iss, text, '-');
    try
    {
        database.year = toInt(text);
    }
    catch (std::exception &e)
    {
        std::cerr << "BitcoinExchange Error: " << e.what() << "\n";
    }
    text.clear();
    getline(iss, text, '-');
    try
    {
        database.month = toInt(text);
    }
    catch (std::exception &e)
    {
        std::cerr << "BitcoinExchange Error: " << e.what() << "\n";
    }
    text.clear();
    getline(iss, text);
    try
    {
        database.day = toInt(text);
    }
    catch (std::exception &e)
    {
        std::cerr << "BitcoinExchange Error: " << e.what() << "\n";
    }
    text.clear();
    return database;
}

static std::string valueValidade(std::string const &value)
{
    bool dot = false;

    if (value.size() >= 10)
        return "TOO LARGE";
    for (size_t i = 0; i < value.size(); i++)
    {
        if (value[i] == '-')
            return "NOT POSITIVE";
        else if (!dot && value[i] == '.')
        {
            dot = !dot;
            continue;
        }
        if (dot && value[i] == '.')
            return "INVALID INPUT";
        else if ((value[i] < '0' || value[i] > '9'))
            return "INVALID INPUT";
    }
    return "";
}

BitcoinExchange::BitcoinExchange(std::string const &file, std::string const &file2)
{
    getData(file, this->db_lines);
    getData(file2, this->flines);

    std::string date, value;

    for (size_t line = 1; line < this->db_lines.size(); line++)
    {
        std::istringstream iss(this->db_lines[line]);
        if(!getline(iss, date, ','))
            break;
        if(!(iss >> value))
            break;
        trimmed(date);
        trimmed(value);
        BlockChain s = convertToDate(date, value);
        this->dbBlockChain.push_back(s);  // Insert at the beginning
    }
};

void BitcoinExchange::init(BlockChain find)
{
    BlockChain* closest = NULL;
    long closestDifference = LONG_MAX;
    for (size_t i = 0; i < dbBlockChain.size(); ++i) {
        BlockChain& current = dbBlockChain[i];
        if ((current.year < find.year) ||
            (current.year == find.year && current.month < find.month) ||
            (current.year == find.year && current.month == find.month && current.day <= find.day)) {

            int currentDifference = dateDifference(find, current);
            if (currentDifference < closestDifference) {
                closest = &current;
                closestDifference = currentDifference;
            }
        }
    }
    

    if (closest) {
        std::cout << find.year << "-" << find.month << "-" << find.day << " => " << find.value << " = " << find.value * closest->value << std::endl;
    } else {
        std::cerr << "No valid past or equal date found." << std::endl;
    }

}

void BitcoinExchange::analize()
{

    std::string date, value, rest;
    std::cout << flines[0][0] << std::endl;
    for (size_t i = 0; i < this->flines.size(); i++)
    {
        int pipes = 0;
        for(size_t j = 0; j < flines[i].size(); j++)
            if(flines[i][j] == '|')
                pipes++;
        if(pipes != 1)
        {
            std::cerr << "Error: bad input => " << flines[i] << std::endl;
            continue;
        }
        std::stringstream iss(flines[i]);
        std::getline(iss, date, '|');
        std::getline(iss, value, '|');
        trimmed(date);
        trimmed(value);
        if (i == 0 && date == "date" && value == "value")
            continue;
        else if (i == 0 && (date != "date" || value != "value"))
            throw std::runtime_error(std::string(RED) + "Invalid input file" + std::string(RESET));
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (valueValidade(value) == "NOT POSITIVE")
        {
            std::cerr << "Error: not a positive number " << value << "\n";
            continue;
        }
        else if (valueValidade(value) == "TOO LARGE")
        {
            std::cerr << "Error: too large number " << value << "\n";
            continue;
        }
        else if (valueValidade(value) == "INVALID INPUT")
        {
            std::cerr << "Error: bad input => " << value << "\n";
            continue;
        }
        BlockChain s = convertToDate(date, value);
        this->init(s);
    }

}

BitcoinExchange::~BitcoinExchange(){};
