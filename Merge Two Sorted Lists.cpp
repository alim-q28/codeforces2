#include <bits/stdc++.h>
using namespace std;
struct listNode
{
    int value;
    listNode* next;
    listNode(int x)
    {
        value = x;
        next = NULL;
    }
};
listNode* mergeTwoSortedLists(listNode* l1 , listNode* l2)
{
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    listNode* temp;
    if(l1->value < l2->value)
    {
        temp = new listNode(l1->value);
        temp->next = mergeTwoSortedLists(l1->next , l2);
    }
    else
    {
        temp = new listNode(l2->value);
        temp->next = mergeTwoSortedLists(l1 , l2->next);
    }
    return temp;
}
void print(listNode* head)
{
    while(head)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << '\n';
    return;
}
int main()
{
    listNode* l1 = new listNode(1);
    l1->next = new listNode(2);
    l1->next->next = new listNode(9);
    listNode* l2 = new listNode(1);
    l2->next = new listNode(3);
    l2->next->next = new listNode(4);
    print(mergeTwoSortedLists(l1 , l2));
    return 0;
}
