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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pseudoHead = new ListNode(0, head);
        ListNode* groupHead = head;
        ListNode* beforeGroupHead = pseudoHead;
        ListNode* iter = head;
        ListNode* curr = nullptr;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        int counter = 0;

        while (true) {
            iter = groupHead;
            counter = 0;
            while (iter && counter < k) {
                iter = iter -> next;
                counter++;
            }

            if (counter < k) {
                break;
            }

            curr = groupHead;
            prev = beforeGroupHead;
            for (int i = 0; i < k; i++) {
                nxt = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = nxt;
            }

            beforeGroupHead -> next = prev;
            groupHead -> next = curr;
            beforeGroupHead = groupHead;
            groupHead = curr;
        }

        head = pseudoHead -> next;
        delete pseudoHead;

        return head;
    }
};
