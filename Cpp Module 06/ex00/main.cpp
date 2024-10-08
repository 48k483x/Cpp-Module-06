# include "conv.hpp"

int main ( void )
{
  std::string str = "a";

  std::cout <<
    (ScalarConverter::isChar(str) ? "It is a char" : "It is not a char")
  << std::endl;

  std::string s = "-2147483649";

  std::cout <<
    (ScalarConverter::isInt(s) ? "It is a Int " : "It's not a Int ") << s
  << std::endl;

  std::string f = "308097979797979797979797977808080808080808080808.2222222222222222222222222222f";

  std::cout <<
    (ScalarConverter::isFloat(f) ? "It's a correct float Number " : "It's not a float Number ") << f
  << std::endl;
}