#include <iostream>

template <typename T>
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

    tModulo x{5.0};
    double y{3.0};

    std::cout << x << "%" << y << " = " << (x % y) << "\n";
}