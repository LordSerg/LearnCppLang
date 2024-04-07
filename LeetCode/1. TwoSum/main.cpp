#include <iostream>
#include <vector>
/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

std::vector<int> twoSum(std::vector<int>& nums, int target) 
{
    int n=nums.size();
    std::vector<int> ans;
    for(int i{0};i<n-1;++i)
    {
        for(int j={i+1};j<n;++j)
        {
            if(nums[i]+nums[j]==target)
                {
                    
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                    //std::cout<<"["<<i<<","<<j<<"]";
                }
        }
    }
    return ans;
}
int main()
{
    std::vector<int>a {2,7,11,15};
    int t{9};
    a=twoSum(a,t);
    for(auto i : a)
        std::cout<<i<<" ";
    return 0;
}