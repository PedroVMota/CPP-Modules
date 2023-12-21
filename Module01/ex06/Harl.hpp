#include <iostream>
#include <string>

class Harl
{
  public:
	void complain( std::string level );
    Harl(void);
    ~Harl(void);
  private:
	void debug( void );
    void info( void );
    void warning( void );
    void error( void );
    void other( void );
    std::string compLvl[5];
};