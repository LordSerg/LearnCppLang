#include <iostream>

int main()
{
    std::cout<<"sizeof(int) = "<<                                         sizeof(int)<<std::endl;
    std::cout<<"sizeof(sizeof(int)) = "<<                                 sizeof(sizeof(int))<<std::endl;
    std::cout<<"sizeof(sizeof(sizeof(int))) = "<<                         sizeof(sizeof(sizeof(int)))<<std::endl;
    std::cout<<"sizeof(sizeof(sizeof(sizeof(int)))) = "<<                 sizeof(sizeof(sizeof(sizeof(int))))<<std::endl;
    std::cout<<"sizeof(sizeof(sizeof(sizeof(sizeof(int))))) = "<<         sizeof(sizeof(sizeof(sizeof(sizeof(int)))))<<std::endl;
    std::cout<<"sizeof(sizeof(sizeof(sizeof(sizeof(sizeof(int)))))) = "<< sizeof(sizeof(sizeof(sizeof(sizeof(sizeof(int))))))<<std::endl;
    return 0;
}