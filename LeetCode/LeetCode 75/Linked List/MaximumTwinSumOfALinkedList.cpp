// Time: O(n), Space: O(1)
class Solution {
public:
    int pairSum(ListNode* head) {
        int sum = 0;
        // make a half reverse linked list
        ListNode* curr{head};
        ListNode* prev{nullptr};
        ListNode* next;
        ListNode* fast{head->next};
        while (true) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            if (fast->next != nullptr) fast = fast->next->next;
            else break;
        }
        while (curr != nullptr && prev != nullptr) {
            sum = max(sum, prev->val + curr->val);
            curr = curr->next;
            prev = prev->next;
        }
        return sum;
    }
};