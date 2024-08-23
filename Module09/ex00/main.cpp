#include "./BitcoinExchange.hpp"
#include <stack>

bool checkFileExtention(string file, string ext = "csv") {
  return file.substr(file.find_last_of(".") + 1) == ext;
}

int main(int ac, char **av) {


  if(ac != 2) {
    std::cerr << "Usage: ./btc <file>\n";
    return 1;
  }
  else if(string(av[1]) == "data.csv") {
    std::cerr << RED << "Error: data.csv is a reserved file.\n" << RESET;
    return 1;
  }
  else if(string(av[1]) == "") {
    std::cerr << RED << "Error: Empty file.\n" << RESET;
    return 1;
  }
  else if(!checkFileExtention(string(av[1]))) {
    std::cerr << RED << "Error: Invalid file extention.\n" << RESET;
    return 1;
  }
  BitcoinExchange center;
  center.Analyze(string(av[1]));
  std::cout << "Exiting...\n";
}
