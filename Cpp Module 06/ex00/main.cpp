# include "conv.hpp"

int main ( void )
{
  // // Testing isChar
  // std::string str = "a";

  // std::cout <<
  //   (ScalarConverter::isChar(str) ? "It is a char " : "It is not a char ") << str
  // << std::endl;

  // // Testing isInt
  // std::string s = "2004";

  // std::cout <<
  //   (ScalarConverter::isInt(s) ? "It is a Int " : "It's not a Int ") << s
  // << std::endl;

  // // Testing isFloat
  // std::string f = "2004.05f";

  // std::cout <<
  //   (ScalarConverter::isFloat(f) ? "It's a correct float Number " : "It's not a float Number ") << f
  // << std::endl;

  // // Testing isDouble
  // std::string d = "2004.05";

  // std::cout <<
  //   (ScalarConverter::isDouble(d) ? "It's a correct double Number " : "It's not a double Number ") << d
  // << std::endl;

  // Testing convertToChar

  {
    // std::string a = "a";
    // std::string b = "b";
    // std::string c = "c";
    // std::string d = "244";
    // std::string e = "hello";
    std::string f = "0";
    // std::string g = "0.0";
    // std::string h = "0.0f";
    // std::string i = "2004.4f";
    // std::string j = "100.4";
    // std::string k = "2147483647";
    // std::string l = "42.0f";

    // ScalarConverter::convertToChar(a);
    // ScalarConverter::convertToChar(b);
    // ScalarConverter::convertToChar(c);
    // ScalarConverter::convertToChar(d);
    // ScalarConverter::convertToChar(e);
    ScalarConverter::convertToChar(f);
    // ScalarConverter::convertToChar(g);
    // ScalarConverter::convertToChar(h);
    // ScalarConverter::convertToChar(i);
    // ScalarConverter::convertToChar(j);
    // ScalarConverter::convertToChar(k);
    // ScalarConverter::convertToChar(l);
  }

  // Testing convertToInt
  // {
  //   std::string i = "-2147483649";
  //   std::string j = "2147483647";
  //   std::string k = "hello";
  //   std::string l = "2147483648";
  //   std::string m = "-2147483648";
  //   std::string n = "2147483649";
  //   std::string o = "0";
  //   std::string p = "0.0";
  //   std::string q = "0.0f";
  //   std::string r = "2004.4f";
  //   std::string s = "2004.4";


  //   ScalarConverter::convertToInt(i);
  //   ScalarConverter::convertToInt(j);
  //   ScalarConverter::convertToInt(k);
  //   ScalarConverter::convertToInt(l);
  //   ScalarConverter::convertToInt(m);
  //   ScalarConverter::convertToInt(n);
  //   ScalarConverter::convertToInt(o);
  //   ScalarConverter::convertToInt(p);
  //   ScalarConverter::convertToInt(q);
  //   ScalarConverter::convertToInt(r);
  //   ScalarConverter::convertToInt(s);
  // }


  // // Testing convertToFloat

  // {
  //   std::string a = "-inff";
  //   std::string b = "+inff";
  //   std::string c = "inff";
  //   std::string d = "nanf";
  //   std::string e = "42.5f";
  //   std::string f = "42.5";
  //   std::string g = "hello";
  //   std::string h = "";
  //   std::string i = "0.0f";
  //   std::string j = "0.0";
  //   std::string k = "0";

  //   ScalarConverter::convertToFloat(a);
  //   ScalarConverter::convertToFloat(b);
  //   ScalarConverter::convertToFloat(c);
  //   ScalarConverter::convertToFloat(d);
  //   ScalarConverter::convertToFloat(e);
  //   ScalarConverter::convertToFloat(f);
  //   ScalarConverter::convertToFloat(g);
  //   ScalarConverter::convertToFloat(h);
  //   ScalarConverter::convertToFloat(i);
  //   ScalarConverter::convertToFloat(j);
  //   ScalarConverter::convertToFloat(k);

  // }

  // {
  //   std::string a = "-inff";
  //   std::string b = "+inff";
  //   std::string c = "inff";
  //   std::string d = "nanf";
  //   std::string e = "nan";
  //   std::string f = "-inf";
  //   std::string g = "+inf";
  //   std::string h = "inf";
  //   std::string i = "42.5f";
  //   std::string j = "42.5";
  //   std::string k = "hello";
  //   std::string l = "";
  //   std::string m = "0.0f";
  //   std::string n = "0.0";
  //   std::string o = "0";

  //   ScalarConverter::convertToDouble(a);
  //   ScalarConverter::convertToDouble(b);
  //   ScalarConverter::convertToDouble(c);
  //   ScalarConverter::convertToDouble(d);
  //   ScalarConverter::convertToDouble(e);
  //   ScalarConverter::convertToDouble(f);
  //   ScalarConverter::convertToDouble(g);
  //   ScalarConverter::convertToDouble(h);
  //   ScalarConverter::convertToDouble(i);
  //   ScalarConverter::convertToDouble(j);
  //   ScalarConverter::convertToDouble(k);
  //   ScalarConverter::convertToDouble(l);
  //   ScalarConverter::convertToDouble(m);
  //   ScalarConverter::convertToDouble(n);
  //   ScalarConverter::convertToDouble(o);

  // }

}