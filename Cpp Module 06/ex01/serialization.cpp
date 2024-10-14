# include "serialization.hpp"

/*
    Memory:
    [11110000101010001111000010101000]  <-- These are the actual bits in memory

    As a pointer (Data*):
    0x7ffd5284e9c0  <-- This is how we represent it in hexadecimal

    As an integer (uintptr_t):
    140726091261376  <-- This is the same value, but as a decimal integer
*/


uintptr_t Serializer::serialize(Data* ptr)
{
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
  return reinterpret_cast<Data*>(raw);
}


// Serialization Constructor

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer&) {}

Serializer& Serializer::operator=(const Serializer&) { return *this; }