#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
namespace kl
{
    class CircBuffBase
    {
    private:
        int m_size;
        std::string m_name;
        int m_head{};
        int m_tail{-1};
        int *m_number_arr;
        int m_elementcount{};

    protected:
        CircBuffBase(int size, const std::string &name);
        void pushNumber_arr(int value)
        {
            m_number_arr[m_tail] = value;
            m_elementcount++;
        }
        void move_head()
        {
            m_head = (m_head + 1) % m_size;
        }
        void move_tail()
        {
            m_tail = (m_tail + 1) % m_size;
        }

    public:
        virtual ~CircBuffBase();
        virtual bool push(int value) = 0;
        bool pop(int &value);
        bool isEmpty() const;
        bool isFull() const;
        void printBuff() const;
        void print_name() const;

        int getSize() const
        {
            return m_size;
        }
        const std::string &getName() const
        {
            return m_name;
        }
        int getHead() const
        {
            return m_head;
        }
        int getTail() const 
        {
            return m_tail;
        }
        int getCount() const 
        {
            return m_elementcount;
        }
    };
}

kl::CircBuffBase::CircBuffBase(int size, const std::string &name)
    : m_size(size), m_name(name)
{
    try
    {
        if (size <= 0)
        {
            throw std::invalid_argument("Size of buffer can't be smaller than 1 \n Making default sized buffer(5)");
        }

        m_number_arr = new int[m_size];
    }
    catch (std::invalid_argument &error)
    {
        std::cerr << error.what() << std::endl
                  << std::endl;
        m_number_arr = new int[5];
    }
}

kl::CircBuffBase::~CircBuffBase()
{
    delete[] m_number_arr;
    std::cout << "DESTRUCTOR of base" << std::endl;
}

void kl::CircBuffBase::print_name() const
{
    std::cout << "Buffer name is: " << m_name << std::endl;
}

void kl::CircBuffBase::printBuff() const
{
    if (isEmpty())
    {
        std::cout << "The " << m_name << " is Empty D:" << std::endl;
    }

    else
    {
        std::cout << "The " << m_name << " is: < ";
        for(int i = 0; i < m_elementcount; ++i)
        {
            std::cout << m_number_arr[(m_head+i)%m_size] << " ";
        }
        std::cout << ">" << std::endl;
    }
}

bool kl::CircBuffBase::isEmpty() const
{
    return m_elementcount == 0;
}

bool kl::CircBuffBase::isFull() const
{
    return m_elementcount == m_size;
}

bool kl::CircBuffBase::pop(int &value)
{
    if (isEmpty())
    {
        std::cout << m_name << " IS EMPTY, CAN'T POP!" << std::endl;
        return false;
    }
    value = m_number_arr[m_head];
    m_head = (m_head + 1) % m_size;
    std::cout << "Popping " << value << " from " << m_name << std::endl;
    m_elementcount--;
    return true;
}