#include <iostream>

int main()
{
    /*
    int arr[]{1,2,3,4,5,6,7,8,9};
    auto *ptr1{arr};
    auto *ptr2{arr+5};
    std::cout<<ptr1<<std::endl;
    std::cout<<ptr2<<std::endl;
    std::cout<<ptr1-ptr2<<std::endl;
    std::cout<<ptr2-ptr1<<std::endl;
    std::cout<<(ptr1>ptr2)<<std::endl;
    std::cout<<(ptr1<ptr2)<<std::endl;
    std::ptrdiff_t pos_diff = ptr1-ptr2;
    std::ptrdiff_t neg_diff = ptr2-ptr1;
    std::cout<<pos_diff<<std::endl;
    std::cout<<neg_diff<<std::endl;
    std::cout << "sizeof(std::ptrdiff_t) : " << sizeof(std::ptrdiff_t) << std::endl;
    */

    /*
    int*ptr{new int{5}};
    std::cout<<*ptr<<std::endl;

    delete ptr;
    ptr=nullptr;
    ptr = new int{9};
    std::cout<<*ptr<<std::endl;
    */

    int *ptr{nullptr};
    for(auto i : {1,2,3,4,5,6,7,8})
    {
        ptr = new int{i};
        std::cout<<*ptr<<std::endl;
        //delete ptr;
        //ptr = nullptr;
    }
    return 0;

}