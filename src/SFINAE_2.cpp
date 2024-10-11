#include <iostream>

#include "typeFunctions.h"

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

    // We want to implement operator % only for integer types
    // we have to break the tie between the class template and
    // operator % member function

    // Breaking Tie:
    // By making a member (operator%) function a function template, we can
    // conditionally enable or disable this member function at compile time

    // That is, we break the tie between the class and its member function at compile time,
    // such that we can control its availability conditionally

    // The immediate context for a function means the validity of its template parameter list and its return type
    // If the immediate context of a function is invalid, the said function is disabled or ignored at compile time
    // If type function tInteger_t<S> does not yield a valid type, then this member function is SFINAEd out, i.e. ignored.

    // SFINAE out any non-integral type of S, or
    // if S is not an integral type,
    // then this function disappears at compile time

    // If we want to implement (enable or disable) member function depending on the types of
    // the template arguments, we have to make member functions "template function"

    template <typename S, typename = tInteger_t<S>>
    T operator%(S rhs)
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