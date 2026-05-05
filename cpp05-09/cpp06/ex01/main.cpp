#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Data* d = new Data();
    d->value = 7;
    d->tag = 'A';

    std::cout << "Creating Data on heap:\n";
    std::cout << "  original pointer: " << d << "\n";
    std::cout << "  contents: value=" << d->value << " tag='" << d->tag << "'\n";

    // serialize pointer to integer
    uintptr_t raw = Serializer::serialize(d);
    std::cout << "Serialized (raw uintptr_t): " << raw << "\n";

    // deserialize back to pointer
    Data* recovered = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << recovered << "\n";

    if (recovered == d)
        std::cout << "OK: recovered pointer equals original." << std::endl;
    else
        std::cout << "ERROR: pointers differ." << std::endl;

    std::cout << "Recovered contents: value=" << recovered->value << " tag='" << recovered->tag << "'\n";

    delete d;
    return 0;
}
