# include "conv.hpp"


void ScalarConverter::convertToChar(const std::string& str)
{
  if (str.empty())
  {
    std::cout << "Char: " << "Impossible" << std::endl;
    return;
  }
  if (str == "nan" || str == "nanf" || str == "-inf" || str == "+inf" || str == "inf" || str == "-inff" || str == "+inff" || str == "inff")
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

  if (*end != '\0' && (*end != 'f' || *(end + 1) != '\0') && (*end != 'F' || *(end + 1) != '\0'))
{
    std::cout << "Char: Impossible" << std::endl;
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
  std::cout << "Char: " << "Impossible" << std::endl;
}

void ScalarConverter::convertToInt(const std::string& str)
{
  if (str.empty())
  {
    std::cout << "Int: " << "impossible" << std::endl;
    return;
  }

  if (ScalarConverter::isInt(str))
  {
    int val = atoi(str.c_str());
    std::cout << "Int: " << val << std::endl;
    return;
  }

  if (str == "nan" || str == "nanf" || str == "-inf" || str == "+inf" || str == "inf" || str == "-inff" || str == "+inff" || str == "inff")
  {
    std::cout << "Int: " << "impossible" << std::endl;
    return;
  }
  if (ScalarConverter::isFloat(str))
  {
    float val = strtof(str.c_str(), NULL);
    std::cout << "Int: " << static_cast<int>(val) << std::endl;
    return;
  }

  if (ScalarConverter::isDouble(str))
  {
    double val = strtod(str.c_str(), NULL);
    std::cout << "Int: " << static_cast<int>(val) << std::endl;
    return;
  }
  std::cout << "Int: " << "impossible" << std::endl;
}

void ScalarConverter::convertToFloat(const std::string& str)
{
  if (str.empty())
  {
    std::cout << "Float: " << "impossible" << std::endl;
    return;
  }
  if (ScalarConverter::isDouble(str))
  {
    double val = strtod(str.c_str(), NULL);
    std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
    return;
  }
  if (ScalarConverter::isInt(str))
  {
    int val = atoi(str.c_str());
    std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
    return;
  }
  if (ScalarConverter::isFloat(str))
  {
    float val = strtof(str.c_str(), NULL);
    std::cout << "Float: " << std::fixed << std::setprecision(1) <<  val << "f" << std::endl;
  }
  else std::cout << "Float: " << "impossible" << std::endl;
}

void ScalarConverter::convertToDouble(const std::string& str)
{
  if (str.empty())
  {
    std::cout << "Double: " << "impossible" << std::endl;
    return;
  }
  if (ScalarConverter::isInt(str))
  {
    int val = atoi(str.c_str());
    std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(val) << std::endl;
    return;
  }
  if (ScalarConverter::isFloat(str))
  {
    float val = strtof(str.c_str(), NULL);
    std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(val) << std::endl;
    return;
  }
  if (ScalarConverter::isDouble(str))
  {
    double val = strtod(str.c_str(), NULL);
    std::cout << "Double: " << std::fixed << std::setprecision(1) << val << std::endl;
  }
  else std::cout << "Double: " << "impossible" << std::endl;
}

