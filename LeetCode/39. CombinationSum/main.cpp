#include <iostream>
#include <vector>

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

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
{

}

int main()
{
    std::vector<int> in{2,3,6,7};
    std::vector<std::vector<int>> ans = combinationSum(in, 7);
    for(auto a : ans)
    {
        for(auto b : a)
        {
            std::cout<<b<<" ";
        }
        std::cout<<"\n";
    }
}