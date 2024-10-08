#pragma once

# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include <cstdlib>

class ScalarConverter
{
  public:  // don't forget to change to private after testing
    ScalarConverter();

    static bool isChar(const std::string& str);
    static bool isInt(const std::string& str);
    static bool isFloat(const std::string& str);
    static bool isDouble(const std::string& str);

    static void convertToChar(const std::string& str);
    static void convertToInt(const std::string& str);
    static void convertToFloat(const std::string& str);
    static void convertToDouble(const std::string& str);


  public:
    // main function
    static void convert(const std::string& str);

    // Constructors
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);
    ~ScalarConverter();

};