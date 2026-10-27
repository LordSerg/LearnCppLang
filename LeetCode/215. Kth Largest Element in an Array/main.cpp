#include <iostream>
#include <vector>
#include <climits>

int findKthLargest(std::vector<int>& nums, int k) 
{
    int min = INT_MAX;
    int max = INT_MIN;
    for(int n : nums)
    {
        if(n<min) min = n;
        if(n>max) max = n;
    }
    int koef = -min;
    std::vector<int> t(max-min+1);
    for(int n:nums)
    {
        t[koef+n]++;
    }

    int i=max+koef;
    int answer=t[i];
    while(k>0&&i>=0)
    {
        answer=i-koef;
        k-=t[i--];
    }
    return answer;
}

int main()
{
    std::vector<int> input{3,2,3,1,2,4,5,5,6};
    int k = 4;
    std::cout<<k<<"th largest element of array is "<<findKthLargest(input,k)<<"\n";
}