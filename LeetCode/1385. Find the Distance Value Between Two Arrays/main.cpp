#include <iostream>
#include <vector>
#include <algorithm>
int findTheDistanceValue_notOptimal(std::vector<int>& arr1, std::vector<int>& arr2, int d)
{
    int answer = 0;
    for(int a:arr1)
    {
        bool flag=true;
        for(int b:arr2)
        {
            int diff = a-b>=0?a-b:b-a;
            if(diff<=d)
            {
                flag=false;
            }
        }
        if(flag)
        {
            answer++;
        }
    }
    return answer;
}

int diff(int a,int b)
{
    return a-b>=0?a-b:b-a;
}

int findTheDistanceValue(std::vector<int>& arr1, std::vector<int>& arr2, int d)
{
    int answer=0;
    std::sort(arr2.begin(), arr2.end());
    for(int a:arr1)
    {
        int l=0,r=arr2.size()-1;
        while(l<=r)
        {
            int m = l+(r-l)/2;
            if(arr2[m] >= a - d && arr2[m] <= a + d)
            {
                answer++;
                break;
            }
            else if(arr2[m] < a - d)
            {
                l = m+1;
            }
            else
            {
                r = m-1;
            }
        }
    }
    
    return arr1.size()-answer;
}

int main()
{
    std::vector<int> a{1,4,2,3};
    std::vector<int> b{-4,-3,6,10,20,30};
    int input = 3;
    std::cout<<"distance = "<<findTheDistanceValue(a,b,input)<<"\n";
}
