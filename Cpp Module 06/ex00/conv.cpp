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

  return *end == '\0' && val <= INT_MAX && val >= INT_MIN;
}

bool ScalarConverter::isFloat(const std::string& str)
{
  if (str == "-inff" || str == "+inff" || str == "inff" || str == "nanf")
    return true;

  char *end;
  float val = strtof(str.c_str(), &end);

  std::cout << "Val: " << val << std::endl;
  std::cout << "End: " << end << std::endl;
  std::cout << "Str: " << str << std::endl;

  if (end == str.c_str())
    return false;
  if ((*end == 'f' || *end == 'F') && *(end + 1) != '\0')
    return false;
  if (std::isinf(val) || std::isnan(val))
    return false;
  return true;
}

// void ScalarConverter::convert(const std::string& str)
// {

// }