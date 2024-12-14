#include "Serializer.hpp"

// Constructor
Serializer::Serializer() {
    // Initialization
}

// Destructor
Serializer::~Serializer() {
    // Cleanup
}

// Copy Constructor
Serializer::Serializer(const Serializer& other) {
    *this = other;
}

// Assignment Operator Overload
Serializer& Serializer::operator=(const Serializer& other) {
    if (this != &other) {
        // Free existing resources
        // Copy members from 'other'
    }
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t p = reinterpret_cast<uintptr_t>(ptr);
    return p;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data *data = reinterpret_cast<Data*>(raw);

    return data;
}