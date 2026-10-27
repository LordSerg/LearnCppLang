#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int minMoves2(std::vector<int>& nums) 
{
    int mid = 0;
    std::sort(nums.begin(), nums.end());
    mid = nums[nums.size()/2];
    
    int answer = INT_MAX;
    for(int x = mid-2; x<=mid+2;++x)
    {
        int t_answer = 0;
        for(auto n : nums)
        {
            t_answer+=(n>x)?(n-x):(x-n);
        }
        answer = answer<t_answer?answer:t_answer;
    }
    return static_cast<int>(answer);
}

int main()
{
    std::vector<int> input{1,2,3};
    std::cout<<"there are minimum "<<minMoves2(input)<<" moves to make all elements equal\n";
}