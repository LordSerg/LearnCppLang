#include <iostream>

int main()
{
    /*
    std::cout<<"sizeof(size_t) = "<<sizeof(size_t)<<std::endl;
    size_t COUNT{5};
    for(size_t i{}; i < COUNT; ++i)
    {
        std::cout<<"for-loop-output"<<std::endl;
    }
    size_t i{};
    while(i<COUNT)
    {
        std::cout<<"while-loop-output"<<std::endl;
        ++i;
    }
    i = 0;
    do
    {
        std::cout<<"do-loop-output"<<std::endl;
        ++i;
    }while(i<COUNT);
    */
    /*
    int arr[50]{1};
    for(auto value : {1,2,3,4,5,6})
    {
        std::cout<<"arr = "<<value<<std::endl;
    }
    */

    const size_t COUNT{20};
    for(size_t i{0} ; i < COUNT ; ++i ){

        if(i==5)
        {
            std::cout<<"before continue\n";
            continue;
            std::cout<<"after continue\n";
        }

        if(i == 11)
        {
            std::cout<<"before break\n";
            break; // Breaks out of the loop
            std::cout<<"after break\n";
        }
        std::cout << "i : " << i << std::endl;
    }
    std::cout << "Loop done!" << std::endl;
}