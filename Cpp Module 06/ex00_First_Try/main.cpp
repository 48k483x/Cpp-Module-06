// # include "conv.hpp"

// int main ( void )
// {
//   // // Testing isChar
//   // std::string str = "a";

//   // std::cout <<
//   //   (ScalarConverter::isChar(str) ? "It is a char " : "It is not a char ") << str
//   // << std::endl;

//   // // Testing isInt
//   // std::string s = "2004";

//   // std::cout <<
//   //   (ScalarConverter::isInt(s) ? "It is a Int " : "It's not a Int ") << s
//   // << std::endl;

//   // // Testing isFloat
//   // std::string f = "2004.05f";

//   // std::cout <<
//   //   (ScalarConverter::isFloat(f) ? "It's a correct float Number " : "It's not a float Number ") << f
//   // << std::endl;

//   // // Testing isDouble
//   // std::string d = "2004.05";

//   // std::cout <<
//   //   (ScalarConverter::isDouble(d) ? "It's a correct double Number " : "It's not a double Number ") << d
//   // << std::endl;

//   // Testing convertToChar

//   {
//     std::string a = "a";
//     std::string b = "b";
//     std::string c = "c";
//     std::string d = "244";
//     std::string e = "hello";
//     std::string f = "0";
//     std::string g = "0.0";
//     std::string h = "0.0f";
//     std::string i = "2004.4f";
//     std::string j = "100.4";
//     std::string k = "2147483647";
//     std::string l = "42.55f";

//     ScalarConverter::convertToChar(a); // a
//     ScalarConverter::convertToChar(b);  // b
//     ScalarConverter::convertToChar(c); // c
//     ScalarConverter::convertToChar(d);
//     ScalarConverter::convertToChar(e);
//     ScalarConverter::convertToChar(f);
//     ScalarConverter::convertToChar(g);
//     ScalarConverter::convertToChar(h);
//     ScalarConverter::convertToChar(i);
//     ScalarConverter::convertToChar(j);
//     ScalarConverter::convertToChar(k);
//     ScalarConverter::convertToChar(l);
//   }

//   // Testing convertToInt
//   // {
//   //   std::string i = "-2147483649";
//   //   std::string j = "2147483647";
//   //   std::string k = "hello";
//   //   std::string l = "2147483648";
//   //   std::string m = "-2147483648";
//   //   std::string n = "2147483649";
//   //   std::string o = "0";
//   //   std::string p = "0.0";
//   //   std::string q = "0.0f";
//   //   std::string r = "2004.4f";
//   //   std::string s = "2004.4";


//   //   ScalarConverter::convertToInt(i);
//   //   ScalarConverter::convertToInt(j);
//   //   ScalarConverter::convertToInt(k);
//   //   ScalarConverter::convertToInt(l);
//   //   ScalarConverter::convertToInt(m);
//   //   ScalarConverter::convertToInt(n);
//   //   ScalarConverter::convertToInt(o);
//   //   ScalarConverter::convertToInt(p);
//   //   ScalarConverter::convertToInt(q);
//   //   ScalarConverter::convertToInt(r);
//   //   ScalarConverter::convertToInt(s);
//   // }


//   // // Testing convertToFloat

//   // {
//   //   std::string a = "-inff";
//   //   std::string b = "+inff";
//   //   std::string c = "inff";
//   //   std::string d = "nanf";
//   //   std::string e = "42.5f";
//   //   std::string f = "42.5";
//   //   std::string g = "hello";
//   //   std::string h = "";
//   //   std::string i = "0.0f";
//   //   std::string j = "0.0";
//   //   std::string k = "0";

//   //   ScalarConverter::convertToFloat(a);
//   //   ScalarConverter::convertToFloat(b);
//   //   ScalarConverter::convertToFloat(c);
//   //   ScalarConverter::convertToFloat(d);
//   //   ScalarConverter::convertToFloat(e);
//   //   ScalarConverter::convertToFloat(f);
//   //   ScalarConverter::convertToFloat(g);
//   //   ScalarConverter::convertToFloat(h);
//   //   ScalarConverter::convertToFloat(i);
//   //   ScalarConverter::convertToFloat(j);
//   //   ScalarConverter::convertToFloat(k);

//   // }

//   // {
//   //   std::string a = "-inff";
//   //   std::string b = "+inff";
//   //   std::string c = "inff";
//   //   std::string d = "nanf";
//   //   std::string e = "nan";
//   //   std::string f = "-inf";
//   //   std::string g = "+inf";
//   //   std::string h = "inf";
//   //   std::string i = "42.5f";
//   //   std::string j = "42.5";
//   //   std::string k = "hello";
//   //   std::string l = "";
//   //   std::string m = "0.0f";
//   //   std::string n = "0.0";
//   //   std::string o = "0";

//   //   ScalarConverter::convertToDouble(a);
//   //   ScalarConverter::convertToDouble(b);
//   //   ScalarConverter::convertToDouble(c);
//   //   ScalarConverter::convertToDouble(d);
//   //   ScalarConverter::convertToDouble(e);
//   //   ScalarConverter::convertToDouble(f);
//   //   ScalarConverter::convertToDouble(g);
//   //   ScalarConverter::convertToDouble(h);
//   //   ScalarConverter::convertToDouble(i);
//   //   ScalarConverter::convertToDouble(j);
//   //   ScalarConverter::convertToDouble(k);
//   //   ScalarConverter::convertToDouble(l);
//   //   ScalarConverter::convertToDouble(m);
//   //   ScalarConverter::convertToDouble(n);
//   //   ScalarConverter::convertToDouble(o);

//   // }

// }

// #include "conv.hpp"
// #include <iostream>
// #include <string>
// #include <iomanip>

// void printHeader(const char* title)
// {
//     std::cout << "\n=== Testing " << title << " ===\n";
// }

// void runTest(const std::string& input, void (*convertFunc)(const std::string&))
// {
//     std::cout << "Input: " << std::setw(15) << std::left << input << " | Result: ";
//     convertFunc(input);
// }

// int main()
// {
//     printHeader("convertToChar");
//     {
//         const char* inputs[] = {"42.f", "42.0.0", "c", "244", "hello", "0", "0.0", "0.0f", "2004.4f", "100.4", "2147483647", "42.55f"};
//         for (int i = 0; i < 12; ++i)
//         {
//             runTest(inputs[i], ScalarConverter::convertToChar);
//         }
//     }

//     printHeader("convertToInt");
//     {
//         const char* inputs[] = {"42.f", "42.0.9", "hello", "2147483648", "-2147483648", "2147483649", "0", "0.0", "0.0f", "2004.4f", "2004.4"};
//         for (int i = 0; i < 11; ++i)
//         {
//             runTest(inputs[i], ScalarConverter::convertToInt);
//         }
//     }

//     printHeader("convertToFloat");
//     {
//         const char* inputs[] = {"42.f", "42.0.0", "inff", "nanf", "42.5f", "42.5", "hello", "", "0.0f", "0.0", "0"};
//         for (int i = 0; i < 11; ++i)
//         {
//             runTest(inputs[i], ScalarConverter::convertToFloat);
//         }
//     }

//     printHeader("convertToDouble");
//     {
//         const char* inputs[] = {"42.f", "42.0.9", "inff", "nanf", "nan", "-inf", "+inf", "inf", "42.5f", "42.5", "hello", "", "0.0f", "0.0", "0"};
//         for (int i = 0; i < 15; ++i)
//         {
//             runTest(inputs[i], ScalarConverter::convertToDouble);
//         }
//     }

//     return 0;
// }

// #include "conv.hpp"
// #include <iostream>
// #include <iomanip>

// void printHeader(const char* title)
// {
//     std::cout << "\n" << std::string(40, '=') << std::endl;
//     std::cout << title << std::endl;
//     std::cout << std::string(40, '=') << std::endl;
// }

// void runTest(const char* input)
// {
//     std::cout << "\nInput: " << std::setw(15) << std::left << input << std::endl;
//     std::cout << std::string(30, '-') << std::endl;
//     ScalarConverter::convert(input);
//     std::cout << std::string(30, '-') << std::endl;
// }

// int main()
// {
//     printHeader("Character Tests");
//     const char* charTests[] = {"a", "z", "A", "Z", "*"};
//     for (int i = 0; i < 5; ++i)
//         runTest(charTests[i]);

//     printHeader("Integer Tests");
//     const char* intTests[] = {"0", "42", "-42", "2147483647", "-2147483648"};
//     for (int i = 0; i < 5; ++i)
//         runTest(intTests[i]);

//     printHeader("Float Tests");
//     const char* floatTests[] = {"0.0f", "4.2f", "-4.2f", "inff", "-inff", "nanf"};
//     for (int i = 0; i < 6; ++i)
//         runTest(floatTests[i]);

//     printHeader("Double Tests");
//     const char* doubleTests[] = {"0.0", "4.2", "-4.2", "inf", "-inf", "nan"};
//     for (int i = 0; i < 6; ++i)
//         runTest(doubleTests[i]);

//     printHeader("Edge Cases");
//     const char* edgeCases[] = {"", "hello", "42.f", "42.0.0", "0xFF", "1e6"};
//     for (int i = 0; i < 6; ++i)
//         runTest(edgeCases[i]);

//     return 0;
// }


// # include "conv.hpp"
// int main (void)
// {
//   std::string str = "42.0.97979.0f";
//   ScalarConverter::convertToFloat(str);

//   float val = 42.f;
//   std::cout << "val: " << val << std::endl;
// }



# include "conv.hpp"

int main (int ac, char *av[])
{
  if (ac != 2)
  {
    std::cout << "Usage: ./convert [value]" << std::endl;
    return 1;
  }
  ScalarConverter::convert(av[1]);
  return 0;
}