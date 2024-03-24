#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
/*Given an integer array nums, return all the triplets 
[nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/
//slow solution
#if 0

std::map<std::vector<int>,int> allTriples;
std::map<int,int> al;
void do_shit(std::vector<int>& arr, int n, int r, int index, int data[], int i)
{
    if(index == r)
    {
        if(data[0]+data[1]+data[2] == 0)
        {
            //sort
            int dataCopy[3]={data[0],data[1],data[2]};
            std::sort(dataCopy,dataCopy+r);
            //add to count
            //std::cout<<data[0]<<" "<<data[1]<<" "<<data[2]<<std::endl;
            allTriples[std::vector<int>(dataCopy,dataCopy+r)]++;
        }
        return;
    }
    if(i>=n)
        return;
    data[index] = arr[i];
    do_shit(arr,n,r,index+1,data,i+1);
    
    do_shit(arr,n,r,index,data,i+1);
}
std::vector<std::vector<int>> threeSum(std::vector<int>& nums) 
{
    int data[3];
    do_shit(nums, nums.size(), 3, 0, data, 0);
    std::vector<std::vector<int>> answer;
    for(const auto& [key, value] : allTriples)
        answer.push_back(key);
    return answer;
}
#endif
//also slow solution
#if 0
std::vector<std::vector<int>> threeSum(std::vector<int>& nums) 
{
    std::map<std::vector<int>,int> allTriples;
    for(int i{};i<nums.size();++i)
    {
        for(int j{i+1};j<nums.size();++j)
        {
            for(int k{j+1};k<nums.size();++k)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    int dataCopy[3]={nums[i],nums[j],nums[k]};
                    std::sort(dataCopy,dataCopy+3);
                    //add to count
                    //std::cout<<data[0]<<" "<<data[1]<<" "<<data[2]<<std::endl;
                    allTriples[std::vector<int>(dataCopy,dataCopy+3)]++;
                }
            }
        }
    }
    std::vector<std::vector<int>> answer;
    for(const auto& [key, value] : allTriples)
        answer.push_back(key);
    return answer;
}
#endif
std::vector<std::vector<int>> threeSum(std::vector<int>& nums) 
{
    std::map<std::vector<int>,int> allTriples;
    std::vector<std::vector<int>> answer;
    std::sort(nums.begin(),nums.end());
    int l,r;
    for(int i{};i<nums.size()-2;++i)
    {
        if(i>0 && nums[i]==nums[i-1])
            continue;
        l=i+1;
        r=nums.size()-1;
        while(l<r)
        {
            int total = nums[i]+nums[l]+nums[r];
            if(total<0)
                l++;
            else if(total>0)
                r--;
            else
            {
                allTriples[std::vector<int>({nums[i],nums[l],nums[r]})]++;
                //answer.push_back(std::vector<int>());
                int aboba = nums[l];
                int abeba = nums[r];
                while(l<r&&nums[l]==aboba)++l;
                while(l<r&&nums[r]==abeba)--r;
            }
        }
    }
    for(const auto& [key, value] : allTriples)
        answer.push_back(key);
    return answer;
}
int main()
{
    std::vector<int> a{3,0,-2,-1,1,2};
    std::vector<std::vector<int>> b=threeSum(a);
    for(auto x :b)
    {
        for(auto y : x)
        {
            std::cout<<y<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}