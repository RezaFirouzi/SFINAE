#include <iostream>

#include "typeFunctions_a.h"

// We want the Modulo class to work only when the T in an integer

// The immediate context for a class template means the "validity of its template parameter list"
// If tInteger_t<T> fails to yield a valid type, then this template parameter list becomes invalid,
// which renders the whole template class Modulo ignored or disappeared during compile time, or
// is called SFINAEd.

template <typename T,
            typename = tInteger_t<T>> // This SFINAE out any non-integral type
struct tModulo
{
private:
    T m_;

public:
    explicit tModulo(T m = T{}) : m_{m} {}

    T operator%(T rhs)
    {
        return m_ % rhs;
    }

    friend std::ostream& operator<<(std::ostream& os, const tModulo& m)
    {
        os << m.m_;
        return os;
    }
};

int main()
{
    // // C++14 - Template argument to be provided
    // tModulo<int> a{5};

    // C++17 - class template argument type deduction
    tModulo a{5};
    int b{3};
    // short b{3};

    std::cout << a << " % " << b << " = " << (a % b) << "\n";

    tModulo m{5};
    double n{3.0};

    std::cout << m << "%" << n << " = " << (m % n) << "\n";

    // tModulo x{5.0};
    // double y{3.0};
    //
    // std::cout << x << "%" << y << " = " << (x % y) << "\n";
}