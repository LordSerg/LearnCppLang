#include <iostream>
#include <concepts>

template <typename T>
concept TynyType = requires (T a)
{
    requires sizeof(T)<=4;
};

template <typename T>
requires std::integral<T> && requires (T a){a++;} && requires (T a){requires sizeof(T)<=4;}
T incr(T num)
{
    num++;    
}

auto add (auto a, auto b)
{
    return a+b;
}
int main()
{
    int a{25};
    int b{52};
    TynyType auto result = add(a,b);
    return 0;
}