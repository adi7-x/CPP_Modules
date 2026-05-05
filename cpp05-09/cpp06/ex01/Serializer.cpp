#include "Serializer.hpp"

// Convert a Data* to an integer type
uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

// Convert the integer back to Data*
Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
