#pragma once

#include "CircBuffBase.hpp"

namespace kl
{
    template <class Tbuffer>
    class OverwritingCircBuff : public kl::CircBuffBase<Tbuffer>
    {
    private:
        int m_overw_size{};
        std::string m_overw_name = this->getName();

    public:
        OverwritingCircBuff(int size)
            : kl::CircBuffBase<Tbuffer>(size, "_overwriting buffer_")
        {
            m_overw_size = size;
        }
        ~OverwritingCircBuff()
        {
            std::cout << "DESTRUCTOR of derieved" << std::endl;
        }
        bool push(const Tbuffer &value)
        {
            this->move_tail();
            this->pushNumber_arr(value);

            if (this->getTail() == this->getHead() && this->getCount() == m_overw_size)
            {
                this->move_head();
            }
            std::cout << "Pushing " << value << " to " << m_overw_name << std::endl;
            return true;
        }
    };
}

