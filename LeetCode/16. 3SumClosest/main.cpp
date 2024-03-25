#include <iostream>
#include <vector>
#include <algorithm>
/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.
*/
int threeSumClosest(std::vector<int>& nums, int target) 
{
    std::sort(nums.begin(),nums.end());

    int answer {nums[0]+nums[1]+nums[2]};
    int dist {abs(target-answer)};
    if(dist == 0)
        return answer;
    for(int i{};i<nums.size()-2;++i)
    {
        int l=i+1;
        int r=nums.size()-1;
        while(l<r)
        {
            int check = nums[i]+nums[l]+nums[r];
            if(check == target)
                return target;
            else if(check < target)
                l++;
            else
                r--;
            if(dist>abs(check-target)||(dist>=abs(check-target)&&check>answer))
            {
                dist = abs(check-target);
                answer = check;
            }
            int aboba = nums[l];
            int abeba = nums[r];
        }
    }
    return answer;
}
int main()
{
    std::vector<int> a{1,1,1,0};
    std::cout<<"threeSumClosest(a,1) = "<<threeSumClosest(a,100)<<std::endl;
    return 0;
}