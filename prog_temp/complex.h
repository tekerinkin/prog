//
// Created by Дима Шестаков on 06.02.2021.
//

#ifndef C___COMPLEX_H
#define C___COMPLEX_H



class complex
{
    double re;
    double im;
public:
    complex(double r, double i) : re(r), im(i)
    {}
    complex(double r) : re(r), im(0)
    {}
    complex() : re(0), im(0)
    {}
    complex& operator +=(complex& z)
    {
        re+=z.re;
        im+=z.im;
        return *this;
    }
    complex& operator-=(complex& z)
    {
        re-=z.re;
        im-=z.im;
        return *this;
    }



    bool operator ==(complex& z) const
    {
        return re == z.re && im == z.im;
    }
    friend complex operator+ (complex& z, complex& z2);
};

complex operator+ (complex& z, complex& z2)
{
    complex z3(z.re + z2.re,z.im + z2.im);
    return z3;
}

bool operator != (complex& z1, complex& z2)
{
    return !(z1 == z2);
}
#endif //C___COMPLEX_H
