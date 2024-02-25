/*namespace math
{
    int add(int a, int b)
    {
        return a+b;
    }
    int sub(int a, int b)
    {
        return a-b;
    }
    int mult(int a, int b)
    {
        return a*b;
    }
    int div(int a, int b)
    {
        return a/b;
    }
} // namespace
*/
int add(int a, int b)
{
    return a+b;
}
//qwestion 1, lesson 2.8
#include <iostream>
int getInteger()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;
	return x;
}