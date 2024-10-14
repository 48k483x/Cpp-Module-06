# include "serialization.hpp"

int main( void )
{
  Data* ptr = new Data;
  uintptr_t raw;

  ptr->x = 10;
  ptr->s = "Abdurrahamn";

  raw = Serializer::serialize(ptr);

  std::cout << "Pointer: " << ptr << std::endl;
  std::cout << "Serialized: " << raw << std::endl;
  std::cout << "Serialized in Hex: " << std::hex << raw << std::endl;

  ptr = Serializer::deserialize(raw);

  std::cout << "Deserialized: " << ptr->x << " " << ptr->s << std::endl;

  delete ptr;
}