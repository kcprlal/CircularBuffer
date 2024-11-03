#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

namespace kl
{
    template <class Tbuffer>
    class CircBuffBase
    {
    private:
        int m_size;
        std::string m_name;
        int m_head{};
        int m_tail{-1};
        Tbuffer *m_number_arr;
        int m_elementcount{};

    protected:
        CircBuffBase(int size, const std::string &name);
        void pushNumber_arr(Tbuffer value)
        {
            m_number_arr[m_tail] = value;
            if (!isFull())
            {
                m_elementcount++;
            }
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
        virtual bool push(Tbuffer value) = 0;
        bool pop(Tbuffer &value);
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

template <class Tbuffer>
kl::CircBuffBase<Tbuffer>::CircBuffBase(int size, const std::string &name)
    : m_size(size), m_name(name)
{
    try
    {
        if (size <= 0)
        {
            throw std::invalid_argument("Size of buffer can't be smaller than 1 \n Making default sized buffer(5)");
        }

        m_number_arr = new Tbuffer[m_size];
    }
    catch (std::invalid_argument &error)
    {
        std::cerr << error.what() << std::endl
                  << std::endl;
        m_number_arr = new Tbuffer[5];
    }
}

template <class Tbuffer>
kl::CircBuffBase<Tbuffer>::~CircBuffBase()
{
    delete[] m_number_arr;
    std::cout << "DESTRUCTOR of base" << std::endl;
}

template <class Tbuffer>
void kl::CircBuffBase<Tbuffer>::print_name() const
{
    std::cout << "Buffer name is: " << m_name << std::endl;
}

template <class Tbuffer>
void kl::CircBuffBase<Tbuffer>::printBuff() const
{
    if (isEmpty())
    {
        std::cout << "The " << m_name << " is Empty D:" << std::endl;
    }

    else
    {
        std::cout << "The " << m_name << " is: < ";
        for (int i = 0; i < m_elementcount; ++i)
        {
            std::cout << m_number_arr[(m_head + i) % m_size] << " ";
        }
        std::cout << ">" << std::endl;
    }
}

template <class Tbuffer>
bool kl::CircBuffBase<Tbuffer>::isEmpty() const
{
    return m_elementcount == 0;
}

template <class Tbuffer>
bool kl::CircBuffBase<Tbuffer>::isFull() const
{
    return m_elementcount == m_size;
}

template <class Tbuffer>
bool kl::CircBuffBase<Tbuffer>::pop(Tbuffer &value)
{
    if (isEmpty())
    {
        std::cout << m_name << " IS EMPTY, CAN'T POP!" << std::endl;
        return false;
    }
    value = m_number_arr[m_head];
    m_head = (m_head + 1) % m_size;
    std::cout << "Popping " << value << " from " << m_name << std::endl;
    if (!isEmpty())
    {
        m_elementcount--;
    }
    return true;
}