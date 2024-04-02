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
int main()
{
    // TreeNode*Jesse=new TreeNode(10);
    // TreeNode*dummy = Jesse;
    // dummy->addDistributors(std::vector<int>{78});
    // dummy = dummy->next[0];
    // dummy->addDistributors(std::vector<int>{19,64});
    // dummy = dummy->next[0];
    // dummy->addDistributors(std::vector<int>{36});
    
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
    return 0;
}