#include <iostream>
#include <vector>
#include <algorithm>
/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length)
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums,
 or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/

#if 0
//my genius solution:
int search(std::vector<int>& nums, int target) 
{
    auto i = std::find(nums.begin(),nums.end(),target);
    if(i == nums.end())
        return -1;
    return i-nums.begin();
}
#endif
//lazy, expected solution:
int binarysearch(std::vector<int>& nums, int low, int high, int target)
{
    if(low > high)
        return -1;
    int mid = (low+high)/2;
    if(nums[mid] == target)
        return mid;
    if(nums[low] <= nums[mid])
    {
        if(nums[low] <= target && target < nums[mid])
            return binarysearch(nums, low, mid-1, target);
        else
            return binarysearch(nums, mid+1, high, target);
    }
    else
    {
        if(nums[mid] < target && target <= nums[high])
            return binarysearch(nums, mid+1, high, target);
        else
            return binarysearch(nums, low, mid-1, target);
    }
    return -1;
}
int search(std::vector<int>& nums, int target) 
{
    return binarysearch(nums, 0, nums.size()-1, target);   
}
int main()
{
    std::vector<int> popipo{4,5,6,7,0,1,2};
    std::cout<< search(popipo,3) << std::endl;
    return 0;
}