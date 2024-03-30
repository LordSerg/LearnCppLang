#include <iostream>
#include <vector>
/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 
The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. 
The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.
*/
//my solution
#if 0
int removeElement(std::vector<int>& nums, int val)
{
    if(nums.empty())
        return 0;
    int k{};
    while(nums.at(nums.size()-1-k)==val)
    {
        ++k;

        if(static_cast<int>(nums.size())-1-k<0)
            break;
        
    }
    for(int i{0};i<nums.size()-k;++i)
    {
        if(nums[i]==val)
        {
            //swap

            nums[i]+=nums[nums.size()-1-k];
            nums[nums.size()-1-k]=nums[i]-nums[nums.size()-1-k];
            nums[i]-=nums[nums.size()-1-k];
            while(nums.at(nums.size()-1-k)==val)
            {
                ++k;
                if(static_cast<int>(nums.size())-1-k<0)
                    break;
            }
        }
    }
    return nums.size()-k;
}
#endif
//fast solution
int removeElement(std::vector<int>& nums, int val)
{
    int j = 0;
    for(int i: nums)
        if(i != val) nums[j++] = i;
    return j;
}
int main()
{
    std::vector<int>a{2,2,3};
    for(auto i:a)std::cout<<i<<" ";
    std::cout<<std::endl;
    std::cout<<removeElement(a,2);
    std::cout<<std::endl;
    for(auto i:a)std::cout<<i<<" ";
    std::cout<<std::endl;
    return 0;
}