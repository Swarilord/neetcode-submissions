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
        if(!head){
            return nullptr;
        }
        if(!head -> next){
            delete head;
            head = nullptr;
            return nullptr;
        }
        ListNode* curr = head;
        int length = 1;
        ListNode* prev = head;
        while(curr -> next){
            length++;
            curr = curr -> next;
        }
        int steps = length - n;
        int count = 0;
        curr = head;
        while(count < steps){
            count++;
            prev = curr;
            curr = curr -> next;
        }
        if (steps == 0) {              
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        if(curr -> next){
            prev -> next = curr -> next;
            delete curr;
            curr = nullptr;
        }
        else{
            prev -> next = nullptr;
            delete curr;
            curr = nullptr;
        }
        return head;
    }
};
