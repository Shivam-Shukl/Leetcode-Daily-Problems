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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }
        temp = head;
        for (int i = 0; i < n / 2 - 1; i++) {
            temp = temp->next;
        }
       
        if(temp -> next == NULL){
            return NULL;
        }else{
            temp->next = temp->next->next;
        }
   

        return head;
    }
};