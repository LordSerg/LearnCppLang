#include <iostream>

int main()
{
    //char msg[10]{'f','u','c','k',' ','y','o','u','!'};
    char msg []{"Fuck you!"};
    /*
    for(auto c:msg)
    {
        std::cout<<c;
    }
    */
    std::cout<<msg<<std::endl;
    std::cout<<"size of array = "<<std::size(msg)<<std::endl;
}