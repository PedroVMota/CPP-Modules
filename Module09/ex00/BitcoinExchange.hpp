#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>

typedef struct dateType
{

    int _day;
    int _month;
    int _year;

    dateType() : _day(0), _month(0), _year(0) {}
    dateType(int _day, int _month, int _year) : _day(_day), _month(_month), _year(_year) {}
    bool isvalid() const
    {
        if ((_day < 1 || _day > 31))
        {
            std::cout << "Invalid day" << std::endl;
            return false;
        }
        if (_month < 1 || _month > 12)
        {
            std::cout << "Invalid month" << std::endl;
            return false;
        }
        if (_year < 2000 || _year > 2024)
        {
            std::cout << "Invalid year" << std::endl;
            return false;
        }
        return true;
    }
} dateType;

class BitcoinExchange
{
private:
    std::vector<std::vector<std::string> > _eachLine;
    std::vector<std::vector<std::string> > _eachLine_to_search;

    dateType *_date;
    dateType *_date2;

public:
    BitcoinExchange();
    BitcoinExchange(std::string const &, std::string const &);
    BitcoinExchange(const BitcoinExchange &);
    ~BitcoinExchange();

    BitcoinExchange &operator=(BitcoinExchange const &);
    void Debug() const;
};
