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
  return str.length() == 1 && std::isprint(str[0]);
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

  std::cout << "val: " << val << std::endl;
  std::cout << "end: " << *end << std::endl;


  if (end == str.c_str())
    return false;
  if (*end == '\0')
    return false;
  if ((*end == 'f' || *end == 'F') && *(end + 1) != '\0')
    return false;
  if (std::isinf(val) || std::isnan(val))
    return false;
  return true;
}

bool ScalarConverter::isDouble(const std::string& str)
{
  if (str == "-inf" || str == "+inf" || str == "inf" || str == "nan")
    return true;

  char *end;
  double val = strtod(str.c_str(), &end);

  if (end == str.c_str())
    return false;
  if (*end != '\0')
    return false;
  if (std::isinf(val) || std::isnan(val))
    return false;
  return true;
}

char ScalarConverter::convertToChar(const std::string& str, char errMssg[100])
{
  if (str.length() != 1)
  {
    strcpy(errMssg, "impossible");
    return '\0';
  }
  char c = str[0];
  if ((atoi(str.c_str()) >= 0 && atoi(str.c_str()) <= 9) || !std::isprint(c))
  {
    strcpy(errMssg, "Non displayable");
    return '\0';
  }
  if (ScalarConverter::isChar(str))
    return static_cast<char>(str[0]);
  else return '\0';
}



