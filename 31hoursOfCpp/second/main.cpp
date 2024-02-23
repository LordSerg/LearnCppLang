#include <iostream>

const auto Pen{10};
const auto Mouse{20}; 
const auto Car{30}; 
const auto Pencil{40}; 
const auto Scissors{50}; 
const auto Glasses{60}; 
const auto Lamp{70}; 

int main()
{
    int tool{Pen};
    switch(tool)
    {
        case Pen:
        {
            std::cout<<"tool = Pen"<<std::endl;
        }
        break;
        case Mouse:
        {
            std::cout<<"tool = Mouse"<<std::endl;
        }
        break;
        default:
        {
            std::cout<<"tool = undefined"<<std::endl;
        }

    }
    return 0;
}