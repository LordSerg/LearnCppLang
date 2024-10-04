#include <iostream>
#include <vector>
#include <algorithm>
/*
Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations 
that sum up to target is less than 150 combinations for the given input.
*/


std::vector<std::vector<int>> answer;

void f(std::vector<int>& candidates, int target, int& curr, std::vector<int>& temp_array)
{
    for(int i=0;i<candidates.size();++i)
    {
        temp_array.push_back(candidates[i]);
        curr+=candidates[i];
        if(curr > target)
        {
            //return curr;
            curr-=temp_array[temp_array.size()-1];
            temp_array.pop_back();
            return;
        }
        else if(curr < target)
        {
            //temp_array.push_back(candidates[i]);
            //return f(candidates,target,candidates[i]+curr,temp_array);
            f(candidates,target,curr,temp_array);
            curr-=temp_array[temp_array.size()-1];
            temp_array.pop_back();
        }
        else if(curr == target)
        {
            
            //temp_array.push_back(candidates[i]);
            std::vector<int> sorted{};
            for(auto a : temp_array)
                sorted.push_back(a);
            std::sort(sorted.begin(),sorted.end());
            if(std::count(answer.begin(), answer.end(), sorted) == 0)
            {
                answer.push_back(sorted);
            }
            curr-=temp_array[temp_array.size()-1];
            temp_array.pop_back();
            return;
            //f(candidates,target,candidates[i]+curr,temp_array);
            //return curr;
        }
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
{
    std::vector<int> c = candidates;
    std::sort(c.begin(),c.end());
    std::vector<int> temporary_array{};
    int temp=0;
    f(c, target, temp, temporary_array);
    return answer;
}

int main()
{
    std::vector<int> in{2,3,6,7};
    std::vector<std::vector<int>> ans = combinationSum(in, 7);
    std::cout<<"\n\nAnswer:\n";
    for(auto a : ans)
    {
        for(auto b : a)
        {
            std::cout<<b<<" ";
        }
        std::cout<<"\n";
    }
}