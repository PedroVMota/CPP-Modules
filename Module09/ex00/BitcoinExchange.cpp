#include "BitcoinExchange.hpp"


static void trimmed(std::string &str)
{
    std::string::size_type first = str.find_first_not_of(" \t\n\r\f\v");
    std::string::size_type last = str.find_last_not_of(" \t\n\r\f\v");

    if (first == std::string::npos) {
        // If there are only whitespace characters or the string is empty
        str.clear();
    } else {
        str = str.substr(first, last - first + 1);
    }
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


static std::string valueValidade(std::string const &value)
{
    bool dot = false;


    if(value.size() >= 10)
        return "TOO LARGE";
    for(size_t i = 0; i < value.size(); i++)
    {
        if(value[i] == '-')
            return "NOT POSITIVE";
        else if (!dot && value[i] == '.')
        {
            dot = !dot;
            continue;
        }
        if(dot && value[i] == '.')
            return "INVALID INPUT";
        else if((value[i] < '0' || value[i] > '9'))
            return "INVALID INPUT";
    }
    return "";
}


bool dataValidate(std::string const &date)
{
    std::string day, month, year;
    std::istringstream iss(date);

    std::getline(iss, year, '-');
    std::getline(iss, month, '-');
    std::getline(iss, day);

    for(size_t i = 0; i < year.length(); i++)
    {
        if(year[i] < '0' && year[i] > '9')
            return false;
        long t = toInt(year);
        if( t < 0 || t > 2022 )
            return false;
    }
    for(size_t i = 0; i < month.length(); i++)
    {
        if(month[i] < '0' && month[i] > '9')
            return false;
        long t = toInt(month);
        if(t < 0 || t > 12 || (t == 2 && toInt(day) > 28))
            return false;
    }

    for(size_t i = 0; i < day.length(); i++)
    {    
        if(day[i] < '0' && day[i] > '9')
            return false;
        long t = toInt(day);
        if(t < 0 || t > 31)
            return false;
    }
    return true;
}

BitcoinExchange::BitcoinExchange(){};

static void  getData(std::string const &file, std::vector<std::vector<std::string> > &matrix)
{
    std::ifstream f(file.c_str());                 // Opening the file
    std::vector<std::vector<std::string> > csvData; // Creating a matrix of content.
    std::string line;                              // the current line.
    if (!f.is_open())
        throw std::runtime_error("Error opening the file.... Shutting down");
    while (std::getline(f, line))
    {
        std::vector<std::string> csvLine;
        std::stringstream ss(line);
        std::string field;

        while (std::getline(ss, field, ','))
        {
            trimmed(field);
            csvLine.push_back(field);
        }
        csvData.push_back(csvLine);
    }
    matrix = csvData;
    f.close();
}



BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        db_lines = other.db_lines;
    return *this;
}

BitcoinExchange::BitcoinExchange(std::string const &file, std::string const &file2)
{
    getData(file, this->db_lines);
    getData(file2, this->flines);
};

void BitcoinExchange::Debug() const
{
    std::cout << "--------- Testing the Search file ---------" << std::endl;
    for (size_t i = 0; i < this->flines.size(); i++)
        std::cout << ">>" << this->flines[i][0] << "<<" << std::endl;
}

void BitcoinExchange::analize() const{

    std::string date, value, rest;
    std::cout << flines[0][0] << std::endl;
    for(size_t i = 0; i < this->flines.size(); i++)
    {
        int a = 0;
        for(size_t y = 0; y < flines[i][0].size(); y++)
            if(flines[i][0][y] == '|')
                a++;
        if(a != 1)
            std::cout << "Error: Number of arguments\n";
        std::stringstream iss(flines[i][0]);
        std::getline(iss, date, '|');
        std::getline(iss, value, '|');
        trimmed(date);
        trimmed(value);
        if(i == 0 && date == "date" && value == "value")
            continue;
        else if(i == 0 && (date != "date" || value != "value"))
            throw std::runtime_error(std::string(RED) + "Invalid input file" + std::string(RESET));
        if(!dataValidate(date))
            std::cout << "Error: bad input => " << date << std::endl;
        if(valueValidade(value) == "NOT POSITIVE")
            std::cout << "Error: not a positive number " << value << "\n";
        else if(valueValidade(value) == "TOO LARGE")
            std::cout << "Error: too large number " << value << "\n";
        else if(valueValidade(value) == "INVALID INPUT")
            std::cout << "Error: bad input => " << value << "\n";
        // std::cout << "Selecting Date: {" << date << "}" << std::endl;
        // std::cout << "Selecting Value: {" << value << "}" << std::endl;
    }
}

BitcoinExchange::~BitcoinExchange(){};
