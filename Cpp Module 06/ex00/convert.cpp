# include "conv.hpp"


void ScalarConverter::convert(const std::string& str)
{
  ScalarConverter::convertToChar(str);
  ScalarConverter::convertToInt(str);
  ScalarConverter::convertToFloat(str);
  ScalarConverter::convertToDouble(str);
}