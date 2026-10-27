#include <iostream>
#include <vector>

bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2) 
{
    return !(rec1[2]<=rec2[0]||rec2[2]<=rec1[0]||rec1[3]<=rec2[1]||rec2[3]<=rec1[1]);
}

int main()
{
    std::vector<int> rec1{0,0,2,2};
    std::vector<int> rec2{1,1,3,3};
    std::cout<<"is rectangles overlap: "<<isRectangleOverlap(rec1,rec2)<<"\n";
}