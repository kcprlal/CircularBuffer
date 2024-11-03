#include <iostream>
#include "OverwritingCircBuff.hpp"
#include "NonOverwritingCircBuff.hpp"

int main()
{

    int value{};

    std::cout << std::endl
              << std::endl;
    int size{3};

    kl::OverwritingCircBuff<int> object(size);
    object.push(1);
    object.push(2);
    object.push(3);
    object.push(4);
    object.push(5);
    object.push(6);
    object.push(1);
    object.push(2);
    object.push(3);
    object.push(4);
    object.push(5);
    object.push(6);
    object.printBuff();

    return 0;
}