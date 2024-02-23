/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/
#include <iostream>
struct ListNode 
{
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode *answer = new ListNode(0);
    ListNode *result = answer;
    size_t temp{};
    answer->val = l1->val + l2->val;
    if(answer->val>9)
    {
        temp = 1;
        answer->val-=10;
    }

    while(l1->next&&l2->next)
    {
        answer->next = new ListNode(l1->next->val + l2->next->val + temp);
        l1=l1->next;
        l2=l2->next;
        answer=answer->next;
        temp = 0;
        if(answer->val>9)
        {
            temp = 1;
            answer->val-=10;
        }
    }
    while (l1->next)
    {
        answer->next = new ListNode(l1->next->val+temp);
        l1=l1->next;
        answer=answer->next;
        temp=0;
        if(answer->val>9)
        {
            temp = 1;
            answer->val-=10;
        }
    }
    while (l2->next)
    {
        answer->next = new ListNode(l2->next->val+temp);
        l2=l2->next;
        answer=answer->next;
        temp=0;
        if(answer->val>9)
        {
            temp = 1;
            answer->val-=10;
        }
    }
    if(temp == 1)
        answer->next = new ListNode(1);
    return result;
}

int main()
{
    ListNode* l1 = new ListNode(2,new ListNode(4,new ListNode(3)));
    ListNode* l2 = new ListNode(5,new ListNode(6,new ListNode(4)));
    ListNode* a =addTwoNumbers(l1,l2);
    std::cout<<a->val<<" ";
    
    while(a->next)
    {
        std::cout<<a->next->val<<" ";
        a = a->next;
    }
    return 0;
}