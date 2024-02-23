#include <iostream>

int main()
{
    /*
    int x{};
    int y{};
    int a{};
    int b{};
    int c{};
    std::cout<<(a=b=c=x=y=5)<<std::endl;
    std::cout<<"a = "<<a<<std::endl;
    std::cout<<"b = "<<b<<std::endl;
    std::cout<<"c = "<<c<<std::endl;
    std::cout<<"x = "<<x<<std::endl;
    std::cout<<"y = "<<y<<std::endl;*/

    /*
    std::cout<<"Enter an integer: ";

    int input{};
    std::cin>>input;
    
    std::cout<<"Double "<<input*2<<std::endl;
    std::cout<<"Triple "<<input*3<<std::endl;
    */
    //test 1.x
    
    int a{};
    int b{};

    std::cout<<"Enter an integer: ";
    std::cin>>a;
    std::cout<<"Enter another integer: ";
    std::cin>>b;
    std::cout<<a<<" + "<<b<<" is "<<a+b<<std::endl;
    std::cout<<a<<" - "<<b<<" is "<<a-b<<std::endl;

    return 0;
}