#include <iostream>
#include <vector>
/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, 
return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
*/
/*
//my solution
//the idea is to "merge" arrays till the middle
//but we going throug only indexes
//than we check, if result array size is odd or even
//if even - return the number we get in the middle of "merged" array
//if odd - return (middle+next)/2
//the time complexity is O((m+n)/2), but not O(log(m+n)) :(
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) 
{
    size_t n {nums1.size()};
    size_t m {nums2.size()};
    size_t k{((m+n)%2)+(m+n)/2};
    size_t i1{};
    size_t i2{};
    double ans{};
    for(int i{};i<k-1;i++)
    {
        if(i1<n&&i2<m)
        {
            if(nums1[i1]<nums2[i2])
                i1++;
            else
                i2++;
        }
        else if(i1<n)
            i1++;
        else if(i2<m)
            i2++;
    }

    if(i1<n&&i2<m)
    {
        if(nums1[i1]<nums2[i2])
        {
            ans = nums1[i1];
            i1++;
        }
        else
        {
            ans = nums2[i2];
            i2++;
        }
    }
    else if(i1<n)
    {
        ans = nums1[i1];
        i1++;
    }
    else if(i2<m)
    {
        ans = nums2[i2];
        i2++;
    }
    
    if((m+n)%2 == 0)
    {
        if(i1<n&&i2<m)
        {
            if(nums1[i1]<nums2[i2])
                ans += nums1[i1];
            else
                ans += nums2[i2];
            ans/=2;
        }
        else if(i1<n)
        {
            ans += nums1[i1];
            ans/=2;
        }
        else if(i2<m)
        {
            ans += nums2[i2];
            ans/=2;
        }
    }
    return ans;
}
*/

//fast solution
//
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) 
{
    if (nums1.size() > nums2.size()) 
    {
        return findMedianSortedArrays(nums2, nums1);
    }
    //assume nums1 is smaller
    
    int m = nums1.size(), n = nums2.size();
    int left = 0, right = m;
    
    while (left <= right) 
    {
        int partitionA = (left + right) / 2;
        int partitionB = (m + n + 1) / 2 - partitionA;
        
        int maxLeftA = (partitionA == 0) ? INT_MIN : nums1[partitionA - 1];
        int minRightA = (partitionA == m) ? INT_MAX : nums1[partitionA];
        int maxLeftB = (partitionB == 0) ? INT_MIN : nums2[partitionB - 1];
        int minRightB = (partitionB == n) ? INT_MAX : nums2[partitionB];
        
        if (maxLeftA <= minRightB && maxLeftB <= minRightA) 
        {
            if ((m + n) % 2 == 0) 
            {
                return (std::max(maxLeftA, maxLeftB) + std::min(minRightA, minRightB)) / 2.0;
            }
            else 
            {
                return std::max(maxLeftA, maxLeftB);
            }
        } 
        else if (maxLeftA > minRightB) 
        {
            right = partitionA - 1;
        }
        else 
        {
            left = partitionA + 1;
        }
    }
    
    return 0.0;
}

//super fast solution

int main()
{
    std::vector<int> a{1,3,5,7,9};
    std::vector<int> b{2,4,6,8,10,12};
    std::cout<<"median = "<<findMedianSortedArrays(a,b)<<std::endl;
    //std::cout<<"median = "<<findMedianSortedArrays(b,a)<<std::endl;
    return 0;
}