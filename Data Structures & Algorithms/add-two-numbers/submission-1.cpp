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
        ListNode* x = l1;
        ListNode* y = l2;
        int remainder = 0;
        int sum;
        sum = x -> val + y -> val;
        if(sum >= 10){
            remainder = 1;
            sum -= 10;
        }
        ListNode* res = new ListNode(sum);
        ListNode* prev = res;
        x = x -> next;
        y = y -> next;
        while(x && y){
            sum = x -> val + y -> val;
            ListNode* nv = new ListNode();
            if(sum + remainder >= 10){
                sum -= 10;
                nv -> val = (sum + remainder);
                remainder = 1;
            }
            else{
                nv -> val = (sum + remainder);
                remainder = 0;
            }
            prev -> next = nv;
            prev = prev -> next;
            x = x -> next;
            y = y -> next;
        }
        while(x){
            sum = x->val + remainder;
            if(sum >= 10){
                sum -= 10;
                remainder = 1;
            } else {
                remainder = 0;
            }
            prev->next = new ListNode(sum);
            prev = prev->next;
            x = x->next;
        }
        while(y){
            sum = y->val + remainder;
            if(sum >= 10){
                sum -= 10;
                remainder = 1;
            } else {
                remainder = 0;
            }
            prev->next = new ListNode(sum);
            prev = prev->next;
            y = y->next;
        }
        if(remainder == 1){
            ListNode* nv = new ListNode(remainder);
            prev -> next = nv;
            prev = prev -> next;
        }
        return res;
    }
};
