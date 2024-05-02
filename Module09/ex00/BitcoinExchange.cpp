#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){};

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _eachLine = other._eachLine;
    return *this;
}

BitcoinExchange::BitcoinExchange(std::string const &file, std::string const &file2)
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
            csvLine.push_back(field);
        csvData.push_back(csvLine);
    }
    this->_eachLine = csvData;
    this->_date = new dateType[this->_eachLine.size()];
    f.close();
    for (size_t i = 0; i < this->_eachLine.size(); i++)
    {
        std::string date = this->_eachLine[i][0];
        std::stringstream ss(date);
        std::string field;
        int j = 0;
        while (std::getline(ss, field, '-'))
        {
            try
            {
                if (j == 2)
                    this->_date[i]._day = std::stoi(field);
                if (j == 1)
                    this->_date[i]._month = std::stoi(field);
                if (j == 0)
                    this->_date[i]._year = std::stoi(field);
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            j++;
        }
    }

    std::fstream f2(file2.c_str());
    std::vector<std::vector<std::string> > csvData2;
    std::string line2;
    if (!f2.is_open())
        throw std::runtime_error("Error opening the file.... Shutting down");
    while (std::getline(f2, line2))
    {
        std::vector<std::string> csvLine2;
        std::stringstream ss2(line2);
        std::string field2;
        while (std::getline(ss2, field2, '|'))
            csvLine2.push_back(field2);
        csvData2.push_back(csvLine2);
    }
    this->_eachLine_to_search = csvData2;
    this->_date2 = new dateType[csvData2.size()];
    f2.close();
    for (size_t i = 0; i < csvData2.size(); i++)
    {
        std::string date = csvData2[i][0];
        std::stringstream ss(date);
        std::string field;
        int j = 0;
        while (std::getline(ss, field, '-'))
        {
            try
            {
                if (j == 2)
                    this->_date2[i]._day = std::stoi(field);
                if (j == 1)
                    this->_date2[i]._month = std::stoi(field);
                if (j == 0)
                    this->_date2[i]._year = std::stoi(field);
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            j++;
        }
    }

    

};

void BitcoinExchange::Debug() const
    {
        for (size_t i = 0; i < _eachLine.size(); i++)
        {
            if(!_date[i].isvalid())
                std::cout << "Invalid date: Date: " << i << std::endl;
            else
                std::cout << "Valid date" << std::endl;
        }
        std::cout << "--------- Testing the Search file ---------" << std::endl;
        for (size_t i = 0; i < this->_eachLine_to_search.size(); i++)
        {
            std::cout <<">>"<< this->_eachLine_to_search[i][0] << "<<" << std::endl;
        }
    }
BitcoinExchange::~BitcoinExchange(){};
