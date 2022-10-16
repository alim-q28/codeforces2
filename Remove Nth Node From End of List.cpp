#include <bits/stdc++.h>

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* cur;
        int len = 0;
        
        cur = dummy->next;
        while(cur){
            ++len;
            cur = cur->next;
        }
        
        // cout << "len: " << len << endl;
        
        cur = dummy;
        for(int i = 0; i < len; ++i, cur = cur->next){
            //i is 1-based
            // cout << i << " : " << cur->val << endl;
            if(i == len-n){
                //this is the node previous to the node to be deleted
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
                break;
            }
        }
        
        return dummy->next;
    }
};
