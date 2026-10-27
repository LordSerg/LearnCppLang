#include <iostream>
#include <vector>

std::vector<int> sortArrayByParity(std::vector<int>& nums) 
{
    int even_index=0;
    int odd_index=nums.size()-1;
    std::vector<int> answer(static_cast<int>(nums.size()),0);

    for(int i=0;i<nums.size();++i)
    {
        if(nums[i]%2==0)
        {
            answer[even_index++] = nums[i];
        }
        else
        {
            answer[odd_index--] = nums[i];
        }
    }
    return answer;
}

void printVector(std::vector<int> num)
{
    for(int n:num)
    {
        std::cout<<n<<" ";
    }
    std::cout<<"\n";
}

int main()
{
    std::vector<int> input{3,1,2,4};
    std::cout<<"array before odd sort: ";
    printVector(input);
    std::cout<<"array after odd sort: ";
    printVector(sortArrayByParity(input));
}