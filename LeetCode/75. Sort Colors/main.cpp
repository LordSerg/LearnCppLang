#include <iostream>
#include <vector>

void sortColors(std::vector<int>& nums) 
{
    int r=0,w=0,b=0;
    for(int n : nums)
    {
        if(n==0){++r;}
        else if(n==1){++w;}
        else {++b;}
    }
    int i=0;
    for(;i<r;++i) nums[i] = 0;
    for(;i<r+w;++i) nums[i] = 1;
    for(;i<r+w+b;++i) nums[i] = 2;
}

int main()
{
    std::vector<int> input{2,0,2,1,1,0};
    std::cout<<"before sorting colors:\n";
    for(int i:input)
    {
        std::cout<<i<<" ";
    }
    std::cout<<"\n";
    sortColors(input);
    std::cout<<"after sorting colors:\n";
    for(int i:input)
    {
        std::cout<<i<<" ";
    }
    std::cout<<"\n";
}