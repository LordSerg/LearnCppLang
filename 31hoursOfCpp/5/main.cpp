#include <iostream>

int main()
{
    /*
    int val{100};
    auto*p_val{&val};
    std::cout<<"val = "<<val<<std::endl;
    std::cout<<"*p_val = "<<(*p_val)<<std::endl;
    *p_val = 50;
    std::cout<<"val = "<<val<<std::endl;
    std::cout<<"*p_val = "<<(*p_val)<<std::endl;
    return 0;
    */

    //const char * p_msg {"qwerty"};
    //std::cout<<p_msg;

    int n{123};
    int m{555};
    const int* ptr {&n};
    std::cout<<*ptr<<std::endl;
    //*ptr=321;//error
    ptr = &m;
    std::cout<<*ptr<<std::endl;

    int*const ptr1 {&n};
    std::cout<<*ptr1<<std::endl;
    *ptr1=321;
    //ptr1 = &m;//error
    std::cout<<*ptr1<<std::endl;

}