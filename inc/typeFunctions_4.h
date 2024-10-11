// Main class template
// If we want to initialize template parameter then we have to
// provide default parameter at primary class template
template<bool TEST, typename ReturnType = void>
struct tEnableTrue
{
    static const bool value = TEST;
    // Here type is undefined
};

// Partial specialization
template<typename ReturnType>
struct tEnableTrue <true, ReturnType>
{
    static const bool value = true;
    using type = ReturnType;
};

template<bool TEST, typename ReturnType>
using tEnableTrue_t = typename tEnableTrue<TEST, ReturnType>::type;