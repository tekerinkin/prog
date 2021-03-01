//
// Created by Дима Шестаков on 06.02.2021.
//

#ifndef C___VECTOR_H
#define C___VECTOR_H

#endif //C___VECTOR_H
#include <iostream>
template<class T>
class Vector
{
    T* elem;
    size_t sz;
public:
    Vector(size_t s) : elem{new T[s]}, sz(s)
    {
        for(size_t i = 0; i < s; ++i)
            elem[i] = 0;
    }
    Vector(std::initializer_list<T> lst) :
        elem{new T[lst.size()]}, sz(lst.size())
    {

         std::copy(lst.begin(), lst.end(), elem);
    }

    Vector(const Vector& a) : elem{new T[a.sz]}, sz(a.sz)
    {
        for(size_t i = 0; i < sz; ++i)
        {
            elem[i] = a.elem[i];
        }
    }

    Vector& operator=(const Vector& a)
    {
        T* p = new T[a.sz];
        for(size_t i =0; i < a.sz; ++i)
        {
            p[i] = a.elem[i];
        }
        delete [] elem;
        elem = p;
        sz = a.sz;
        return *this;
    }

    Vector(Vector&& a) noexcept
    : elem{a.elem}, sz(a.sz)
    {
        a.elem = nullptr;
        a.sz = 0;
    }

    Vector& operator=(Vector&& a) noexcept
    {
        elem = a.elem;
        sz = a.sz;
        a.elem = nullptr;
        a.sz = 0;
    }

    Vector() : elem{new T[0]}, sz(0)
    {}

    T& operator[](int i)
    {
        return elem[i];
    }

    size_t size() const
    {
        return sz;
    }
    void push_back(T d)
    {
        elem[++sz] = d;
    }

    T* begin()
    {
        return sz ? &elem[0] : nullptr;
    }

    T* end()
    {
        return sz ? &elem[0]+sz : nullptr;
    }
    ~Vector()
    {
        delete [] elem;
    }

};