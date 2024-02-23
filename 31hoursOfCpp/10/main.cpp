#include <iostream>
#include <concepts>

template<typename T>
concept incrementable = requires(T a)
{
    a++;
    ++a;
    a+=1;
    a=a+1;
};

template <typename T>
concept qwerty = requires(T a, T b)
{
    {a+b} -> std::convertible_to<int>;
};

template <typename T>
requires incrementable<T> && std::integral<T>
T add(T a, T b)
{
    return a+b;
}

int main()
{
    double a{10.9};
    double b{20.9};
    auto result = static_cast<char>(add<char>(a, b));
    std::cout<<"result = "<< result <<std::endl;
    std::cout<<"sizeof(result) = "<< sizeof(result)<<std::endl;
    return 0;
}