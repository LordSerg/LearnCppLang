#include <iostream>
#include <vector>
/*Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.*/
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void swp(int &a,int &b)
{
    a+=b;
    b=a-b;
    a-=b;
}

ListNode* reverseKGroup(ListNode* head, int k)
{
    if(head==nullptr)
        return head;
    std::vector<ListNode*> a(k);
    a[0]=head;
    for(int i{1};i<k;++i)
    {
        if(a[i-1]->next==nullptr)
            return head;
        else
            a[i]=a[i-1]->next;
    }
    for(int i{};i<k/2;++i)
    {
        swp(a[i]->val,a[k-i-1]->val);
    }
    bool flag=true;
    while(true)
    {
        if(a[k-1]->next==nullptr)
            break;
        else
            a[0] = a[k-1]->next;
        for(int i{1};i<k;++i)
        {
            if(a[i-1]->next==nullptr)
            {
                flag=false;
                break;
            }
            else
                a[i]=a[i-1]->next;
        }
        if(!flag)
            break;
        for(int i{};i<k/2;++i)
        {
            swp(a[i]->val,a[k-i-1]->val);
        }
    }
    return head;
}

int main()
{
    
    return 0;
}