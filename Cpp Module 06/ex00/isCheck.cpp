# include "conv.hpp"

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
  if (*end == '.')
    return false;
  return *end == '\0' && val <= INT_MAX && val >= INT_MIN;
}

bool ScalarConverter::isFloat(const std::string& str)
{
  if (str.empty()) return false;
  if (str == "-inff" || str == "+inff" || str == "inff" || str == "nanf")
    return true;

  char *end;
  float val = strtof(str.c_str(), &end);
  if (*end == '.')
    return false;

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
  if (*end == '.')
    return false;

  if (end == str.c_str())
    return false;
  if (*end != '\0')
    return false;
  if (std::isinf(val) || std::isnan(val))
    return false;
  return true;
}
