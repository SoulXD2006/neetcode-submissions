/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* m1 = head;
         ListNode* m2 = head;
         ListNode* m3 = head;
         int j = 0;   
        while(m1!=nullptr){
            m1= m1->next;
            j++;
        }
        if (j == 1){return nullptr;}
        int m = j - n-1;
        if ( j == n){ head = head->next;
        return head; }
        while(m!=0){
            m2 = m2->next;
            m3 = m3->next;
            m--;
        }
        m3 = m3->next->next;
        m2->next= m3;
        return head;

        
        
        
        
        
        
        
        }
};
