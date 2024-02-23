#include <iostream>

int main()
{
    /*
    int arr[5]{1,0,0,0,0};
    int*ptr{arr};
    std::cout<<"arr = "<<arr<<std::endl;
    std::cout<<"ptr = "<<ptr<<std::endl;
    std::cout<<"arr[0] = "<<arr[0]<<std::endl;
    std::cout<<"ptr[0] = "<<ptr[0]<<std::endl;
    std::cout<<"&arr[0] = "<<&arr[0]<<std::endl;
    std::cout<<"&ptr[0] = "<<&ptr[0]<<std::endl;
    std::cout<<"*arr = "<<*arr<<std::endl;
    std::cout<<"*ptr = "<<*ptr<<std::endl;
    std::cout<<"*(arr+1) = "<<*(arr+1)<<std::endl;
    std::cout<<"*(ptr+1) = "<<*(ptr+1)<<std::endl;
    return 0;
    */

    int arr1[5] {1,1,1,1,1};
    int arr2[5] {2,2,2,2,2};
    int*ptr{nullptr};
    int*pa1{arr1};
    int*pa2{arr2};
    std::cout<<"before:\n";

    std::cout<<"arr1:\n";
    for(auto i:arr1)
        std::cout<<i<<" ";
    std::cout<<std::endl;

    std::cout<<"arr2:\n";
    for(auto i:arr2)
        std::cout<<i<<" ";
    std::cout<<std::endl;

    ptr = pa1;
    pa1=pa2;
    pa2=ptr;

    std::cout<<"after:\n";

    std::cout<<"arr1:\n";
    for(size_t i{};i<std::size(arr1);++i)
        std::cout<<pa1[i]<<" ";
    std::cout<<std::endl;

    std::cout<<"arr2:\n";
    for(size_t i{};i<std::size(arr2);++i)
        std::cout<<pa2[i]<<" ";
    std::cout<<std::endl;
    
}