#include <iostream>
#include "OverwritingCircBuff.hpp"
#include "NonOverwritingCircBuff.hpp"

int main()
{

    std::string value{};

    std::cout << std::endl
              << std::endl;
    int size{3};

    kl::NonOverwritingCircBuff<std::string> object(size);
    object.push("to");
    object.push("jest");
    object.push("overw");
    object.push("bufor");
    object.printBuff();
    object.pop(value);
    std::cout<<value<<std::endl;
    object.printBuff();
    return 0;
}