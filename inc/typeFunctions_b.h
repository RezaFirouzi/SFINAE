
// Main class template
template <typename T1, typename T2>
struct tSameType
{
    static const bool value = false;
};

// Partial specialization
template <typename T>
struct tSameType<T, T>
{
    static const bool value = true;
    using type = T;
};

// Value template
template <typename T1, typename T2>
constexpr bool isSameType = tSameType<T1, T2>::value;

// Using template - type alias
template <typename T1, typename T2>
using tSameType_t = typename tSameType<T1, T2>::type;