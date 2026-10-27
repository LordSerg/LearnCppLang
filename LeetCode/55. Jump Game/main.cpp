#include <iostream>
#include <vector>

bool canJump(std::vector<int>& nums)
{
    int t=0;
    for(int n:nums)
    {
        if(t<0)
        {
            return false;
        }
        else if(n>t)
        {
            t=n;
        }
        t--;
    }
    return true;
}

int main()
{
    std::vector<int> input {2,3,1,1,4};
    std::cout<<canJump(input)<<"\n";
}
