#include <iostream>
#include <vector>
#include <queue>
/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int val):val(val),next(nullptr){}
    ListNode(int val, ListNode *next):val(0),next(next){}
};
#if 0
//my slow solution
ListNode* mergeKLists(std::vector<ListNode*>& lists)
{
    if(lists.empty())
        return nullptr;
    std::vector<ListNode*>p(lists);
    for(int i{};i<p.size();++i)
    {
        if(p[i]==nullptr)
        {
            p.erase(p.begin()+i);
            --i;
        }
    }
    if(p.empty())
        return nullptr;
    int imin{0};//pointer to the smallest element
    int min{p[0]->val};//smallest element
    //find first smallest element
    for(int i{};i<p.size();++i)
    {
        if(p[i]->val < min)
        {
            min = p[i]->val;
            imin = i;
        }
    }
    ListNode * answer{p[imin]};
    if(p[imin]->next!=nullptr)
        p[imin] = p[imin]->next;
    else
        p.erase(p.begin()+imin);
    ListNode * t = answer;
    while(p.empty())
    {
        imin=0;
        min=p[0]->val;
        for(int i{};i<p.size();++i)
        {
            if(p[i]->val < min)
            {
                min = p[i]->val;
                imin = i;
            }
        }
        t->next = p[imin];
        t=t->next;
        if(p[imin]->next!=nullptr)
            p[imin] = p[imin]->next;
        else
            p.erase(p.begin()+imin);
    }
    return answer;
}
#endif
//fast solution
ListNode* mergeKLists(std::vector<ListNode*>& lists) 
{
    ListNode dummy(0);
    ListNode* curr = &dummy;
    auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(compare)> minHeap(compare);

    for (ListNode* list : lists)
      if (list != nullptr)
        minHeap.push(list);

    while (!minHeap.empty()) {
      ListNode* minNode = minHeap.top();
      minHeap.pop();
      if (minNode->next)
        minHeap.push(minNode->next);
      curr->next = minNode;
      curr = curr->next;
    }

    return dummy.next;
  }
int main()
{
    std::vector<ListNode*>lst
    {
        new ListNode(1)
    };
    ListNode*a = mergeKLists(lst);
    
    return 0;
}
