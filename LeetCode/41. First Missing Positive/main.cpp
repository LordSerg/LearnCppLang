#include <iostream>
#include <vector>
#include <map>
/*
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

Constraints:

1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1

*/

int firstMissingPositive(std::vector<int>& nums)
{
    std::map<int, int> m;
    int min = 1;
    for(int i : nums)
    {
        m[i]++;
        if(min == i)
        {
            while (m[++min])
            {
                std::cout<<m[min]<<" "<<min<<"\n";
            }
        }
    }
    return min;
}

int main()
{
    std::vector<int> input = {1,2,3};
    std::cout<<firstMissingPositive(input);
}