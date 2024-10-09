# include "conv.hpp"

int main ( void )
{
  // Testing isChar
  std::string str = "a";

  std::cout <<
    (ScalarConverter::isChar(str) ? "It is a char " : "It is not a char ") << str
  << std::endl;

  // Testing isInt
  std::string s = "2004";

  std::cout <<
    (ScalarConverter::isInt(s) ? "It is a Int " : "It's not a Int ") << s
  << std::endl;

  // Testing isFloat
  std::string f = "2004.05f";

  std::cout <<
    (ScalarConverter::isFloat(f) ? "It's a correct float Number " : "It's not a float Number ") << f
  << std::endl;

  // Testing isDouble
  std::string d = "2004.05";

  std::cout <<
    (ScalarConverter::isDouble(d) ? "It's a correct double Number " : "It's not a double Number ") << d
  << std::endl;

  // Testing convertToChar
  char errMssg[100];
  std::string c = "0";
  std::string c1 = "a";
  std::string c2 = "hello";

  if (ScalarConverter::convertToChar(c, errMssg) != 0)
    std::cout << "Char: " << ScalarConverter::convertToChar(c, errMssg) << std::endl;
  else
  {
    std::cout << "Char: " << errMssg << std::endl;
  }

   if (ScalarConverter::convertToChar(c1, errMssg) != 0)
    std::cout << "Char: " << ScalarConverter::convertToChar(c1, errMssg) << std::endl;
  else
  {
    std::cout << "Char: " << errMssg << std::endl;
  }

  if (ScalarConverter::convertToChar(c2, errMssg) != 0)
    std::cout << "Char: " << ScalarConverter::convertToChar(c2, errMssg) << std::endl;
  else
  {
    std::cout << "Char: " << errMssg << std::endl;
  }

}