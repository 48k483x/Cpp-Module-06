#pragma once

# include <iostream>
# include <string>
# include <fstream>

/*
  Serialization: is the process of converting an objet's
  state into a format that can be easily stored or transmitted.
            (e.g, to a File of over the network)

  Deserialization: is the reverse process, where the stored
  or transmitted data is used to reconstruct the original object.
*/

struct Data
{
  int x;
  std::string s;
};

class Serializer
{
  private:
    Serializer();

  public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

    // Serialization Constructor
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);
    ~Serializer();
};