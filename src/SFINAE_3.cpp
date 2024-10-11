#include <iostream>

#include "typeFunctions_a.h"
#include "typeFunctions_b.h"

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

    // The immediate context for a function template consists of its template parameter list and its return type
    // If either its template parameter list or its return type is invalid, the function is SFINAEd out

    // If S in not an integral type, the type function tInteger_t<S> returns nothing, which SFINAEs out the member function
    // If S and T are of the same typ, then the type function tSameType_t<S, T> yields a valid type, otherwise, tSameType_t<S, T> does not
    // return anything, which effectively, SFINAEs out this member function.
    template <typename S, typename = tInteger_t<S>>
    tSameType_t<S, T> operator%(S rhs)
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

    std::cout << a << " % " << b << " = " << (a % b) << "\n";

    // tModulo c{5};
    // short d{3};
    //
    // std::cout << c << " % " << d << " = " << (c % d) << "\n";
    //
    // tModulo m{5};
    // double n{3.0};
    //
    // std::cout << m << "%" << n << " = " << (m % n) << "\n";
    //
    // tModulo x{5.0};
    // double y{3.0};
    //
    // std::cout << x << "%" << y << " = " << (x % y) << "\n";
}