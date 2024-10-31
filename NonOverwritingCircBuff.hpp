#pragma once
#include "CircBuffBase.hpp"
namespace kl
{
    class NonOverwritingCircBuff : public kl::CircBuffBase
    {
    private:
        int m_nonover_size{};
        std::string m_nonoverw_name = getName();

    public:
        NonOverwritingCircBuff(int size);
        ~NonOverwritingCircBuff();
        bool push(int value) override;
    };
}

kl::NonOverwritingCircBuff::NonOverwritingCircBuff(int size)
    : kl::CircBuffBase(size, "_non overwriting buffer_")
{
    m_nonover_size = size;
}

kl::NonOverwritingCircBuff::~NonOverwritingCircBuff()
{
    std::cout << "DESTRUCTOR of derieved" << std::endl;
}

bool kl::NonOverwritingCircBuff::push(int value)
{
    if (isFull())
    {
        std::cout << m_nonoverw_name << " IS FULL!" << std::endl;
        return false;
    }
    move_tail();
    pushNumber_arr(value);
    std::cout << "Pushing " << value << " to " << m_nonoverw_name << std::endl;
    return true;
}