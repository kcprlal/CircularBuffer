#pragma once
#include "CircBuffBase.hpp"

namespace kl
{
    template <class Tbuffer>
    class NonOverwritingCircBuff : public kl::CircBuffBase<Tbuffer>
    {
    private:
        int m_nonover_size{};
        std::string m_nonoverw_name = this->getName();

    public:
        NonOverwritingCircBuff(int size)
            : kl::CircBuffBase<Tbuffer>(size, "_non overwriting buffer_")
        {
            m_nonover_size = size;
        }
        ~NonOverwritingCircBuff()
        {
            std::cout << "DESTRUCTOR of derieved" << std::endl;
        }

        bool push(const Tbuffer &value)
        {
            if (this->isFull())
            {
                std::cout << m_nonoverw_name << " IS FULL!" << std::endl;
                return false;
            }
            this->move_tail();
            this->pushNumber_arr(value);
            std::cout << "Pushing " << value << " to " << m_nonoverw_name << std::endl;
            return true;
        }
    };
}