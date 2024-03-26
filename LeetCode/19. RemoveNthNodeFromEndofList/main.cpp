#include <iostream>
/*Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode*h1 = head;
    int num=1;
    while(h1->next!=nullptr)
    {
        h1=h1->next;
        ++num;
    }
    n = num-n-1;//now delete n-th element from begin

    h1 = head;
    if(n<0)
        head=head->next;
    else
    {
        while(n>0)
        {
            --n;
            h1=h1->next;
        }
        ListNode *tmp = h1->next->next;
        delete h1->next;
        h1->next = tmp;
    }
    return head;
}
int main()
{
    //ListNode * head = new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5)))));
    ListNode * head = new ListNode(1,new ListNode(2));
    removeNthFromEnd(head,2);

    return 0;
}