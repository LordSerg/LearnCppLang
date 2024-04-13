#include <iostream>
#include <vector>
/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/
std::vector<int> searchRange(std::vector<int>& nums, int target)
{
    int n{static_cast<int>(nums.size())};
    int l{},r{n-1};
    int m{(l+r)/2};
    bool flag{false};
    while(l<=r)
    {
        if(nums[m]==target)
        {
            flag = true;
            l=m;
            r=m;
            break;
        }
        else if(nums[l]==target)
        {
            flag = true;
            r=l;
            break;
        }
        else if(nums[r]==target)
        {
            flag = true;
            l=r;
            break;
        }
        else
        {
            if(nums[m]>target)
                r=m;
            else if(nums[m]<target)
                l=m;
            if(m==(l+r)/2)
                break;
            else
                m=(l+r)/2;
        }
    }
    if(flag)
    {
        while(l>0&&nums[l-1]==target)--l;
        while((r<n-1)&&nums[r+1]==target)++r;
        return std::vector<int>{l,r};
    }
    else
        return std::vector<int>{-1,-1};

}
int main()
{
    std::vector<int>input{1,4};
    std::vector<int>output{searchRange(input,4)};
    for(auto i:output)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    return 0;
}