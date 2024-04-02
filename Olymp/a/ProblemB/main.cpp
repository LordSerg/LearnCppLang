#include <iostream>
#include <vector>
#include <stack>
/*
https://icpc2023ukr.eolymp.space/uk/compete/08b96vt1t50cn7qv471tkhgu5k
(Breaking bad)
https://icpc2023ukr.eolymp.space/uk/compete/08b96vt1t50cn7qv471tkhgu5k/problem/2

*/

struct TreeNode
{
    int value;
    std::vector<TreeNode *> next;
    std::stack<TreeNode*>output;
    //std::vector<TreeNode *> prev;
    TreeNode():value(0),next(std::vector<TreeNode*>(0)),output(std::stack<TreeNode*>()){} 
    TreeNode(int val):value(val),next(std::vector<TreeNode*>(0)),output(std::stack<TreeNode*>()){} 
    //TreeNode(int val, TreeNode*nxt):value(val),next(std::vector<TreeNode*>()){} 
    void addDistributors(std::vector<int>dist)
    {
        for(int i{};i<dist.size();++i)
        {
            next.push_back(new TreeNode(dist[i]));
        }
    }
    void show()
    {
        std::cout<<value<<" ";
        if(!next.empty())
            for(auto i:next)
                output.push(i);
        while(!output.empty())
        {
            std::cout<<(output.top()->value)<<" ";
            std::vector<TreeNode*>tmp = output.top()->next;
            output.pop();
            if(!tmp.empty())
                for(auto i:tmp)
                    output.push(i);
        }
    }
};

void findMaxInTree(TreeNode*head, int& max)
{
    if(max<head->value)
        max = head->value;
    for(auto it:head->next)
        findMaxInTree(it,max);
}
void shiftTree(TreeNode*head)
{
    TreeNode*dummy = head;
    if(!dummy->next.empty())
    {
        for(auto i:dummy->next)
        {
            dummy->value += i->value;
            i->value = 0;
            shiftTree(i);
        }
    }
}
long long int findMaxVect(std::vector<long long int>a)
{ 
    long long int ans = a[0];
    for(auto i:a)
    {
        if(i>ans)
            ans=i;
    }
    return ans;
}

void shift(std::vector<long long int>&a,std::vector<int>p,long long int &max)
{
    std::vector<long long int>tmp(a.size());
    tmp[0] = a[0];
    for(int i{0};i<p.size();++i)
    {
        tmp[p[i]]+=a[i+1];
        if(tmp[p[i]]>max)
            max = tmp[p[i]];
    }
    a=tmp;
}

int main()
{
    // TreeNode*Jesse=new TreeNode(10);
    // TreeNode*dummy = Jesse;
    // dummy->addDistributors(std::vector<int>{78});
    // dummy = dummy->next[0];
    // dummy->addDistributors(std::vector<int>{19,64});
    // dummy = dummy->next[0];
    // dummy->addDistributors(std::vector<int>{36});
    /*
    TreeNode*Jesse=new TreeNode(25);
    TreeNode*dummy = Jesse;
    dummy->addDistributors(std::vector<int>{29});
    dummy = dummy->next[0];
    dummy->addDistributors(std::vector<int>{27});
    dummy = dummy->next[0];
    dummy->addDistributors(std::vector<int>{20,23});
    dummy = dummy->next[1];
    dummy->addDistributors(std::vector<int>{28});

    std::cout<<std::endl;
    for(int i{};i<5;++i)
    {
        Jesse->show();
        std::cout<<std::endl;
        int max=0;
        findMaxInTree(Jesse,max);
        std::cout<<"max = "<<max<<std::endl;
        shiftTree(Jesse);
        std::cout<<"shift #"<<i<<std::endl;
        Jesse->show();
        std::cout<<std::endl;
    }
    */
    int t{};

    std::cin>>t;
    for(;t>0;--t)
    {
        int n{};
        std::cin>>n;
        std::vector<long long int> a;
        std::vector<int> p;
        if(n==1)
        {
            int fix;
            std::cin>>fix;
        }
        for(int i{};i<n-1;i++)
        {
            int k;
            std::cin>>k;
            p.push_back(k);
        }
        for(int i{};i<n;i++)
        {
            int k;
            std::cin>>k;
            a.push_back(k);
        }
        long long int max{findMaxVect(a)};
        //std::cout<<max<<" ";
        for(int times{};times<n;++times)
        {
            //std::cout<<"shift #"<<times<<std::endl;
            std::cout<<max<<" ";
            shift(a,p,max);
            //for(auto i:a)
            //    std::cout<<i<<" ";
            //std::cout<<std::endl;
            //std::cout<<"max = "<<max<<std::endl;
        }
        std::cout<<std::endl;
    }
    return 0;
}