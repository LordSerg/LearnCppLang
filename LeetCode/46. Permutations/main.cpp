#include <iostream>
#include <vector>

std::vector<std::vector<int>> answer;

void swap(std::vector<int>& v, int a, int b)
{
    int t = v[a];
    v[a] = v[b];
    v[b] = t;
}

void permutations(std::vector<int> v, int a)
{
    if(a==v.size()-1) 
    {
        answer.push_back(v);
        return;
    }
    for(int b=a;b<v.size();++b)
    {
        swap(v,a,b);
        permutations(v,a+1);
    }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) 
{
    answer.clear();
    if(nums.size()<2)
    {
        answer.push_back(nums);
        return answer;
    }
    permutations(nums,0);
    return answer;
}

int main()
{
    std::vector<int> input{1,2,3};
    std::cout<<"vector: { ";
    for(int i:input)
    {
        std::cout<<i<<" ";
    }
    std::cout<<"}\n";

    std::cout<<"all permutations:\n";
    auto answer = permute(input);
    for(auto v:answer)
    {
        std::cout<<"{ ";
        for(auto i:v)
        {
            std::cout<<i<<" ";
        }
        std::cout<<"}\n";
    }
}