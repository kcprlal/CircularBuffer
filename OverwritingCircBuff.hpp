#pragma once

#include "CircBuffBase.hpp"
namespace kl
{
    class OverwritingCircBuff : public kl::CircBuffBase
    {
    private:
    int m_overw_size{};
    std::string m_overw_name = getName();

    public:
        OverwritingCircBuff(int size);
        ~OverwritingCircBuff();
        bool push(int value) override;
    };
}

kl::OverwritingCircBuff::OverwritingCircBuff(int size)
    : kl::CircBuffBase(size, "_overwriting buffer_")
{
    m_overw_size=size;
}

kl::OverwritingCircBuff::~OverwritingCircBuff(){
    std::cout << "DESTRUCTOR of derieved" << std::endl;
}

bool kl::OverwritingCircBuff::push(int value)
{
    move_tail();
    pushNumber_arr(value);
    
    if (getTail() == getHead() && getCount() == m_overw_size)
    {
        move_head();
    }
    std::cout << "Pushing " << value << " to " << m_overw_name << std::endl;
    return true;
}
