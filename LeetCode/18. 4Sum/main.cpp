#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
/*Given an array nums of n integers, return an array of all the unique quadruplets 
[nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.

nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.*/

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) 
{
    if(nums.size()<4)
        return std::vector<std::vector<int>>();
    std::vector<std::vector<int>>answer{};
    std::map<std::vector<int>,int>mp;
    std::sort(nums.begin(),nums.end());
    int l,r;
    for(int i{};i<nums.size()-3;++i)
    {
        for(int j{i+1};j<nums.size()-2;++j)
        {
            l = j+1;
            r = nums.size()-1;
            while(l<r)
            {
                long k = static_cast<long>(nums[i])+static_cast<long>(nums[j])+
                static_cast<long>(nums[l])+static_cast<long>(nums[r]);
                if(k == static_cast<long>(target))
                {
                    mp[std::vector<int>{nums[i],nums[j],nums[l],nums[r]}]++;
                    int aboba = nums[l];
                    int abeba = nums[r];
                    while(l<r&&nums[l]==aboba)++l;
                    while(l<r&&nums[r]==abeba)--r;
                }
                else if(k>static_cast<long>(target))
                {
                    --r;
                }
                else //if(nums[i]+nums[j]+nums[l]+nums[r]<target)
                {
                    ++l;
                }
            }
        }
    }
    for(const auto &[key,value]:mp)
    {
        answer.push_back(key);
    }
    return answer;
}

int main()
{
    std::vector<int> a{2,2,2,2,2};
    std::vector<std::vector<int>> res = fourSum(a,8);
    for(auto i : res)
    {
        for(auto j : i)
        {
            std::cout<< j<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}