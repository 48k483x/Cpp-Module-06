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
  if (str.empty()) return false;
  return str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]);
}

bool ScalarConverter::isInt(const std::string& str)
{
  if (str.empty()) return false;
  char *end;


  long val = strtol(str.c_str(), &end, 10);
  std::cout << "val: " << val << std::endl;

  return *end == '\0' && val <= INT_MAX && val >= INT_MIN;
}

bool ScalarConverter::isFloat(const std::string& str)
{
  if (str.empty()) return false;
  if (str == "-inff" || str == "+inff" || str == "inff" || str == "nanf")
    return true;

  char *end;
  float val = strtof(str.c_str(), &end);

  // std::cout << "val: " << val << std::endl;
  // std::cout << "end: " << *end << std::endl;


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
  if (str.empty()) return false;
  if (str == "-inf" || str == "+inf" || str == "inf" || str == "nan")
    return true;

  char *end;
  double val = strtod(str.c_str(), &end);
  // std::cout << "val: " << val << std::endl;

  if (end == str.c_str())
    return false;
  if (*end != '\0')
    return false;
  if (std::isinf(val) || std::isnan(val))
    return false;
  return true;
}

void ScalarConverter::convertToChar(const std::string& str)
{
  if (str.empty())
  {
    std::cout << "Char: " << "Impossible" << std::endl;
    return;
  }
    if (ScalarConverter::isChar(str))
    {
      std::cout << "Char: " << str << std::endl;
      return;
    }
  char *end;
  float val1 = strtof(str.c_str(), &end);
  int val = static_cast<int>(val1);
  std::cout << "val: " << val << std::endl;

  if (*end != '\0')
  {
    std::cout << "Char: " << "Impossible" << std::endl;
    return;
  }

  if ((val >= 0  && val <= 31) || val == 127)
  {
    std::cout << "Char: " << "Non displayable" << std::endl;
    return;
  }

  if ((val >= 32 && val <= 126) || (val >= 128 && val <= 255))
  {
    std::cout << "Char: " << static_cast<char>(val) << std::endl;
    return;
  }
}

void ScalarConverter::convertToInt(const std::string& str)
{
  if (ScalarConverter::isInt(str))
  {
    int val = atoi(str.c_str());
    std::cout << "Int: " << val << std::endl;
  }
  else std::cout << "Int: " << "impossible" << std::endl;
}

void ScalarConverter::convertToFloat(const std::string& str)
{
  if (ScalarConverter::isFloat(str))
  {
    float val = strtof(str.c_str(), NULL);
    std::cout << "Float: " << std::fixed << std::setprecision(1) <<  val << "f" << std::endl;
  }
  else std::cout << "Float: " << "impossible" << std::endl;
}

void ScalarConverter::convertToDouble(const std::string& str)
{
  if (ScalarConverter::isDouble(str))
  {
    double val = strtod(str.c_str(), NULL);
    std::cout << "Double: " << std::fixed << std::setprecision(1) << val << std::endl;
  }
  else std::cout << "Double: " << "impossible" << std::endl;
}

