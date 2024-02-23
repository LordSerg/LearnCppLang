#include <iostream>
#include "cylinder.h"

int main()
{
    Cylinder c1(10,10);
    Cylinder *c2 = new Cylinder(10,10);
    //std::cout<<"volume of cylinder("<<c1.get_radius()<<", "<<c1.get_height()<<") = "<<c1.volume()<<std::endl;
    std::cout<<"sizeof(c1) = "<<sizeof(c1)<<std::endl;
    std::cout<<"sizeof(c2) = "<<sizeof(c2)<<std::endl;
    std::cout<<"sizeof(*c2) = "<<sizeof(*c2)<<std::endl;
    return 0;
}