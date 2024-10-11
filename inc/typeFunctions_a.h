#pragma once

// Main template class
template <typename T>
struct tInteger
{
    static const bool value = false;
};

// Full specialization for type int
template <>
struct tInteger<int>
{
    static const bool value = true;
    using type = int;
};

// Full specialization for type short
template <>
struct tInteger<short>
{
    static const bool value = true;
    using type = short;
};

// Full specialization for type long
template <>
struct tInteger<long>
{
    static const bool value = true;
    using type = long;
};

// Full specialization for type long long
template <>
struct tInteger<long long>
{
    static const bool value = true;
    using type = long long;
};

// Full specialization for type unsigned int
template <>
struct tInteger<unsigned int>
{
    static const bool value = true;
    using type = unsigned int;
};

// Full specialization for type unsigned short
template <>
struct tInteger<unsigned short>
{
    static const bool value = true;
    using type = unsigned short;
};

// Full specialization for type unsigned long
template <>
struct tInteger<unsigned long>
{
    static const bool value = true;
    using type = unsigned long;
};

// Full specialization for unsigned long long
template <>
struct tInteger<unsigned long long>
{
    static const bool value = true;
    using type = unsigned long long;
};

// Value template
template <typename T>
constexpr bool isInteger = tInteger<T>::value;

// Using template - type alias
// Type function - an abstract concept in C++.
// A using template can yield (or return) different types depending on its template arguments
// Therefore, a type function is a using template that yields types with one primary class template
// and full and/or partial class template specializations.
template <typename T>
using tInteger_t = typename tInteger<T>::type;