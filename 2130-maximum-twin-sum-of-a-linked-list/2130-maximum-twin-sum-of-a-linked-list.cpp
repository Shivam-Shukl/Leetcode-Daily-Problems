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
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }
        temp = head;
        for (int i = 0; i < n / 2; i++) {
            temp = temp->next;
        }
        ListNode* prev = NULL;
        while (temp) {
            ListNode* dump = temp->next;
            temp->next = prev;
            prev = temp;
            temp = dump;
        }
        temp = head;
        int ans = INT_MIN;
        while (prev) {
            int sum = prev->val + temp->val;
            ans = max(ans, sum);
            prev = prev->next;
            temp = temp->next;
        }

        return ans;
    }
};