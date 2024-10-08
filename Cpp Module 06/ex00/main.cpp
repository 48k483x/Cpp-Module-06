# include "conv.hpp"

int main ( void )
{
  std::string str = "a";

  std::cout <<
    (ScalarConverter::isChar(str) ? "It is a char" : "It is not a char")
  << std::endl;

  std::string s = "-5";

  std::cout <<
    (ScalarConverter::isInt(str) ? "It is a Int " : "It's not a Int ") << s
  << std::endl;
  ScalarConverter::isInt(s);
}