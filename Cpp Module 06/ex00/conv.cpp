# include "conv.hpp"

ScalarConverter::ScalarConverter()
{
  std::cout << "ScalarConverter: Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
  std::cout << "ScalarConverter: Copy constructor called" << std::endl;
  *this = src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
  std::cout << "ScalarConverter: Assignation operator called" << std::endl;
  return *this;
}

ScalarConverter::~ScalarConverter()
{
  std::cout << "ScalarConverter: Destructor called" << std::endl;
}

bool ScalarConverter::isChar(const std::string& str)
{
  if (str.length() != 1)
    return false;

  if (str[0] >= 32 && str[0] <= 126) return true;
  else return false;
}

bool ScalarConverter::isInt(const std::string& str)
{
  char *end;

  long val = strtol(str.c_str(), &end, 10);
  std::cout << "end = " << end  << "val = " << val << std::endl;

  std::cout << (*end == '\0' && val <= INT_MAX && val >= INT_MIN) << std::endl;
  return *end == '\0' && val <= INT_MAX && val >= INT_MIN;
}

// void ScalarConverter::convert(const std::string& str)
// {

// }