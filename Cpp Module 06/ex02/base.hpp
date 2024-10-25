#pragma once

# include <iostream>
# include <string>
# include <fstream>

/*
+-------------------+-------------------------------------------------------------+
| Cast Type         | Description                                                 |
+-------------------+-------------------------------------------------------------+
| static_cast       | Compile-time conversion between related types               |
|                   | (e.g., int -> float, base -> derived)                       |
+-------------------+-------------------------------------------------------------+
| dynamic_cast      | Runtime safe downcasting in inheritance                     |
|                   | (returns nullptr/throws if fails)                           |
+-------------------+-------------------------------------------------------------+
| const_cast        | Removes/adds const qualifier                                |
|                   | Use rarely for legacy APIs                                  |
+-------------------+-------------------------------------------------------------+
| reinterpret_cast  | Low-level bit reinterpretation                              |
|                   | Use cautiously for hardware access                          |
+-------------------+-------------------------------------------------------------+
*/

class Base
{
  public:
    virtual ~Base() {}
};