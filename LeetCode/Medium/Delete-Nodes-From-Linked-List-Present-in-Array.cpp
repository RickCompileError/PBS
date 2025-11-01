// Time: O(n), Space: O(n)
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> valuesToRemove(nums.begin(), nums.end());

        ListNode* tmpHead = new ListNode(0, head);
        ListNode* curr = tmpHead;

        while (curr -> next != nullptr) {
            if (valuesToRemove.contains(curr -> next -> val)) {
                ListNode* tmp = curr -> next;
                curr -> next = curr -> next -> next;
                // delete tmp;
            } else {
                curr = curr -> next;
            }
        }

        curr = tmpHead -> next;
        // delete tmpHead;

        return curr;
    }
};
