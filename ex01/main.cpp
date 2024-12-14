#include "Serializer.hpp"

int main()
{
    Data *data = new Data();
    data->content = 10;
    uintptr_t p = Serializer::serialize(data);
    std::cout <<  "here data content: " << data->content << std::endl;
    std::cout <<  "here data address: " << data << std::endl;
    std::cout <<  "here value of uintptr_t: " << p << std::endl;
    std::cout <<  "here value after deserialzer: " << (Serializer::deserialize(p))<< std::endl;

    delete data;
}