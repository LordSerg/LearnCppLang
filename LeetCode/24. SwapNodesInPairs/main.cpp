#include <iostream>
/*Given a linked list, swap every two adjacent nodes and return its head. 
You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)*/

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head)
{
    ListNode *a;
    ListNode *b;
    if(head==nullptr)
        return nullptr;
    a=head;
    if(a->next==nullptr)
        return head;
    b=a->next;
    //swap values
    a->val+=b->val;
    b->val=a->val-b->val;
    a->val-=b->val;

    while(true)
    {
        if(b->next!=nullptr)
            a=b->next;
        else
            break;
        if(a->next!=nullptr)
            b=a->next;
        else
            break;
        
        a->val+=b->val;
        b->val=a->val-b->val;
        a->val-=b->val;
    }
    return head;
}

int main()
{
    ListNode* list =new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4))));
    
    return 0;
}