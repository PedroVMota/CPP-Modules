#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){};

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _eachLine = other._eachLine;
    return *this;
}

BitcoinExchange::BitcoinExchange(std::string const &file)
{
    std::ifstream f(file.c_str());                         // Opening the file
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
            csvLine.push_back(field);
        csvData.push_back(csvLine);
    }
    this->_eachLine = csvData;
};
BitcoinExchange::~BitcoinExchange(){};

void BitcoinExchange::printLines() const
{
    for (std::vector<std::vector<std::string> >::const_iterator line = _eachLine.begin(); line != _eachLine.end(); ++line)
    {
        std::cout << "[";
        for (std::vector<std::string>::const_iterator field = line->begin(); field != line->end(); ++field)
        {
            std::cout << *field << " ";
        }
        std::cout << "]\n";
    }
}
