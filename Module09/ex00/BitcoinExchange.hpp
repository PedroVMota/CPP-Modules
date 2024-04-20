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


class BitcoinExchange{
    private:
        std::vector<std::vector<std::string> > _eachLine;

    public:
        BitcoinExchange();
        BitcoinExchange(std::string const &);
        BitcoinExchange(const BitcoinExchange &);
        ~BitcoinExchange();
        BitcoinExchange &operator=(BitcoinExchange const &);
        void printLines() const;
};
