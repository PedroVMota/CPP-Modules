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
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <stdexcept>


#ifndef COLORS
#define COLORS

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"

#endif


typedef struct BlockChain{
    int year;
    int month;
    int day;

    double value;
} BlockChain;



class BitcoinExchange
{
private:
    std::vector<std::string> db_lines;
    std::vector<std::string> flines;
    std::vector<BlockChain> dbBlockChain;
    BitcoinExchange &operator=(BitcoinExchange const &);
    long dateToDays(int year, int month, int day);
    long dateDifference(const BlockChain &a, const BlockChain &b);
    BitcoinExchange();
    void init(BlockChain s);
public:
    BitcoinExchange(std::string const &, std::string const &);
    BitcoinExchange(const BitcoinExchange &);
    ~BitcoinExchange();
    void analize();
};
