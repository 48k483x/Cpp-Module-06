# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
  if (literal.empty()) {
    std::cout << "Error: Empty input" << std::endl;
    return ;
  }

  if (isSpecialValue(literal)) {
    handleSpecialValue(literal);
    return ;
  }

  std::string pasebaleString = literal;
  if (literal.length() > 1) {
    char lastChar = literal[literal.length() - 1];
    if (lastChar == 'F' || lastChar == 'f') {
      pasebaleString = literal.substr(0, literal.length() - 1);
    }
  }

  char *end;
  double value = strtod(pasebaleString.c_str(), &end);
  if (*end != '\0') {
    if (literal.length() == 1) {
      value = static_cast<char>(literal[0]);
    }
    else {
      std::cout << "Error: Invalid input" << std::endl;
      return ;
    }
  }

  printConversions(value);
}

bool ScalarConverter::isSpecialValue(const std::string& literal) {
  return (literal == "nan" || literal == "nanf" ||
      literal == "inf" || literal == "inff" ||
      literal == "+inf" || literal == "+inff" ||
      literal == "-inf" || literal == "-inff");
}

void ScalarConverter::handleSpecialValue(const std::string& literal) {
    if (literal == "nan" || literal == "nanf") {
      std::cout << "Float: nanf" << std::endl;
      std::cout << "Double: nan" << std::endl;
    }
    else if (literal == "-inf" || literal == "-inff") {
      std::cout << "Float: -inff" << std::endl;
      std::cout << "Double: -inf" << std::endl;
    }
    else {
      std::cout << "Float: +inff" << std::endl;
      std::cout << "Double: +inf" << std::endl;
    }
}

void ScalarConverter::printConversions(double value) {
  printChar(value);
  printInt(value);
  printFloat(value);
  printDouble(value);
}

void ScalarConverter::printChar(double value) {
  if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max()) {
    std::cout << "char: impossible" << std::endl;
  }
  else if (!std::isprint(static_cast<char>(value))) {
    std::cout << "char: Non displayable" << std::endl;
  }
  else {
    std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
  }
}

void ScalarConverter::printInt(double value) {
  if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || std::isnan(value)) {
    std::cout << "int: impossible" << std::endl;
  }
  else {
    std::cout << "int: " << static_cast<int>(value) << std::endl;
  }
}

void ScalarConverter::printFloat(double value) {
  std::cout << "float: ";
  if (value != value) {
    std::cout << "nanf" << std::endl;
  }
  else if (value == std::numeric_limits<float>::infinity()) {
    std::cout << "+inff" << std::endl;
  }
  else if (value == -std::numeric_limits<float>::infinity()) {
    std::cout << "-inff" << std::endl;
  }
  else {
    std::cout << std::fixed << std::setprecision(7)
                  << static_cast<float>(value) << "f" << std::endl;
  }
}

void ScalarConverter::printDouble(double value)
{
    std::cout << "double: ";
    if (value != value) { // Check for NaN
        std::cout << "nan" << std::endl;
    } else if (value == std::numeric_limits<double>::infinity()) {
        std::cout << "+inf" << std::endl;
    } else if (value == -std::numeric_limits<double>::infinity()) {
        std::cout << "-inf" << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(7)
                  << value << std::endl;
    }
}