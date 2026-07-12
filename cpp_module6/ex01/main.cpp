#include "./Serializer.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Kalın (Bold) Renkler
#define BOLD_RED    "\033[1;31m"
#define BOLD_GREEN  "\033[1;32m"
#define BOLD_YELLOW "\033[1;33m"
#define BOLD_CYAN   "\033[1;36m"

int main(void)
{
    Data    newData;
    newData.id    = 1;
    newData.name = "Alp";

    std::cout << BOLD_GREEN << "--- START EXERCISE ---" << RESET << std::endl;
    std::cout << YELLOW << "Original address: " << RESET << BOLD_CYAN << &newData << RESET << std::endl;

    uintptr_t serializedValue = Serializer::serialize(&newData);
    std::cout << YELLOW << "Serialized value: " << RESET << BOLD_CYAN << serializedValue << RESET << std::endl;

    Data* deserializedData = Serializer::deserialize(serializedValue);
    std::cout << YELLOW << "Deserialized address: " << RESET << BOLD_CYAN << deserializedData << RESET << std::endl;

    std::cout << std::endl;
    if (deserializedData == &newData)
    {
        std::cout << GREEN << "SUCCESS: Pointers are identical!" << RESET << std::endl;
        std::cout << "Data ID: " << deserializedData->id << std::endl;
        std::cout << "Data Name: " << deserializedData->name << std::endl;
    }
    else
    {
        std::cout << RED << "ERROR: Pointers do not match!" << RESET << std::endl;
        return (1);
    }

    return (0);
}
