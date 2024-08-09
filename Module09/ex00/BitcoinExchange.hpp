#pragma once

#include <cctype>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <sys/types.h>

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

typedef std::string string;
typedef std::ifstream file;
typedef std::istringstream buffer;
typedef std::map<string, double> map;

# define INT_MAX 2147483647

typedef enum ERROR
{
  OK,
  NEGATIVE,
  RANGE,
  UNKNOWN,
  F_CHARACTER,
  EMPTY,
  DOT_ERROR,
} ERROR;


const char *errorToString(ERROR error);
bool isLeapYear(int year);
bool isValidDay(int month, int day, int year);
std::string trim(const std::string &str);

class BitcoinExchange
{
private:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &);
  BitcoinExchange &operator=(const BitcoinExchange &);

  map _database;

  bool fetchDatabase(const std::string &filename);
  void printDatabase();
  bool parseDate(const std::string &date);
  ERROR checkValue(double value);
  ERROR checkValue(const std::string &s);
  int daysSinceEpoch(int year, int month, int day);
  int daysBetweenDates(const std::string &date1, const std::string &date2);
  int *getDate(const std::string &date);
  map::iterator getClosest(std::string date);

public:
  BitcoinExchange(const std::string &filename);
  ~BitcoinExchange() {};
  void Analyze(const std::string &input);
};
