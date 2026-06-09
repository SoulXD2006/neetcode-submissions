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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = l1;
        ListNode* temp = l2;

        while (sum != nullptr) {
            sum->val = sum->val + temp->val;

            if (sum->val / 10 > 0) {
                if (sum->next == nullptr) {
                    ListNode* head = new ListNode(sum->val / 10);
                    sum->next = head;
                    sum->val = sum->val % 10;
                } else {
                    sum-> next-> val =  sum-> next-> val + (sum->val) / 10;
                    sum->val = (sum->val) % 10;
                }
            }
            if (temp->next == nullptr && sum->next!= nullptr ){
                 ListNode* head3 = new ListNode(0);
                 temp -> next = head3;
            }
            if (sum->next == nullptr && temp->next!= nullptr){
                 ListNode* head3 = new ListNode(0);
                 sum -> next = head3;
            }
            temp = temp->next;
            sum = sum->next;
        }
        return l1;
    }
};
