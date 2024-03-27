#include <iostream>
/*You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode *n):val(x),next(n){}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
    if(list1==nullptr&&list2==nullptr)
    {
        return nullptr;
    }
    else if(list1==nullptr)
    {
        return list2;
    }
    else if(list2 == nullptr)
    {
        return list1;
    }
    ListNode * h1=list1;
    ListNode * h2=list2;
    ListNode *answer;
    if(h1->val<=h2->val)
    {
        answer = h1;
        h1=h1->next;
    }
    else
    {
        answer = h2;
        h2=h2->next;
    }
    ListNode * tmp = answer;
    while(h1!=nullptr&&h2!=nullptr)
    {
        if(h1->val<h2->val)
        {
            tmp->next = h1;
            tmp = tmp->next;
            h1=h1->next;
        }
        else
        {
            tmp->next = h2;
            tmp = tmp->next;
            h2=h2->next;
        }
    }
    while (h1!=nullptr)
    {
        tmp->next=h1;
        tmp=tmp->next;
        h1=h1->next;
    }
    while (h2!=nullptr)
    {
        tmp->next=h2;
        tmp=tmp->next;
        h2=h2->next;
    }
    return answer;
}
int main()
{
    ListNode *list1 = new ListNode(1,new ListNode(2,new ListNode(4)));
    ListNode *list2 = new ListNode(1,new ListNode(3,new ListNode(4)));
    ListNode *k = mergeTwoLists(list1,list2);
    while (k->next!=nullptr)
    {
        std::cout<<k->val<<" -> ";
        k=k->next;
    }
    std::cout<<k->val;
    
    return 0;
}