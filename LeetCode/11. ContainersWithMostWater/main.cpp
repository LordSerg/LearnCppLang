#include <iostream>
#include <vector>

/*
You are given an integer array height of length n. 
There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/

int maxArea(std::vector<int> a)
{
    int maxS{-1};
    int s{0},e{static_cast<int>(a.size())-1};//start & end
    while(s<e)
    {
        if (maxS<(a[s]<a[e]?a[s]:a[e])*(e-s))
            maxS = (a[s]<a[e]?a[s]:a[e])*(e-s);
        if (a[s]<a[e])
            ++s;
        else
            --e;
    }
    return maxS;
}

int main()
{
    std::vector<int> arr{1,8,6,2,5,4,8,3,7};
    std::cout<<"maxArea = "<<maxArea(arr);
    return 0;
}