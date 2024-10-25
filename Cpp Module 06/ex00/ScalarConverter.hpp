#pragma once

# include <iostream>
# include <string>
# include <cmath>
# include <climits>
# include <cstdlib>
# include <cstring>
# include <iomanip>
# include <cstdlib>


// +--------------------------------+----------------------------------------------------------+
// | Reminder                       |                                                          |
// +--------------------------------+----------------------------------------------------------+
// | Static Member Variables        | Shared among all instances of a class.                   |
// +--------------------------------+----------------------------------------------------------+
// | Static Member Functions        | Can be called on the class itself, without an instance.  |
// +--------------------------------+----------------------------------------------------------+
// | Static Local Variables         | Retain their value between function calls.               |
// +--------------------------------+----------------------------------------------------------+
// | Static Global Variables/Functions | Limited to the file scope.                            |
// +--------------------------------+----------------------------------------------------------+



class ScalarConverter {
  private:
    ScalarConverter();

    static void printConversions(double value);
    static void printChar(double value);
    static void printInt(double value);
    static void printFloat(double value);
    static void printDouble(double value);
    static bool isSpecialValue(const std::string& literal);
    static void handleSpecialValue(const std::string& literal);

  public:
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);
    ~ScalarConverter();

    // Main function
    static void convert(const std::string& literal);
};