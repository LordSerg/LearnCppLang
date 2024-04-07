#include <iostream>
#include <vector>
/*Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
*/
int searchInsert(std::vector<int>& nums, int target)
{
    int i=static_cast<int>(nums.size());
    int l,r;
    l=0;
    r=i-1;
    i/=2;
    if(l==r)
    {
        if(target<=nums[i])
            return 0;
        else
            return 1;
    }
    while(l!=r)
    {
        if(r-l==1)
        {
            if(nums[r]==target)
                return r;
            else if(nums[l]==target)
                return l;
            else if(nums[r]>target&&nums[l]>target)
                return (l-1)<0?(0):(l-1);
            else if(nums[r]<target&&nums[l]<target)
                return r+1;
            else //if(nums[r]<target&&nums[l]>target)
                return r;
            break;
        }
        if(nums[i]==target)
            return i;
        if(nums[i]>target)
        {
            r=i;
            i=(l+r)/2;
        }
        else //if(nums[i]<target)
        {
            l=i;
            i=(l+r)/2;
        }
        
    }
    return i;
}
int main()
{
    
    return 0;
}