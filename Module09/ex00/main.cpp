#include <BitcoinExchange.hpp>


int main(int ac, char **av)
{
    (void)av;
    if(ac != 2)
    {
        std::cerr << "Usage: ./btc <input file>" << std::endl;
        return 1;
    }
    try{

    BitcoinExchange data("data.csv", std::string(av[1]));
    data.analize();
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    // data.Debug();
}