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
        vector<int> v; 
        ListNode* temp = head;
        while(temp){
            int value = temp -> val;
            v.push_back(value);
            temp = temp-> next;
        }
        int n = v.size();
        int ans = INT_MIN;
        for(int i =0;i<= (n/2)-1;i++){
            int sum = v[n-1-i] + v[i];
            ans = max(sum , ans);
        }
        return ans;
    }
};