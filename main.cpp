#include <iostream>
#include "OverwritingCircBuff.hpp"
#include "NonOverwritingCircBuff.hpp"

int main()
{

    int value{};
    
    std::cout << std::endl
              << std::endl;
    int size{6};

    kl::NonOverwritingCircBuff object(size);
    object.push(0);
    object.printBuff();


    return 0;
}