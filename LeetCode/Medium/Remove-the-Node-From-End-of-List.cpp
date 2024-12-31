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
        ListNode* tmp = head;
        int sz = 0;
        while (tmp) {
            sz++;
            tmp = tmp -> next;
        }

        ListNode* nodeBeforeRemove = head;
        sz -= n;
        if (sz == 0) {
            head = head -> next;
            delete nodeBeforeRemove;
            return head;
        }

        while (--sz > 0) {
            nodeBeforeRemove = nodeBeforeRemove -> next;
        }

        tmp = nodeBeforeRemove -> next;
        nodeBeforeRemove -> next = tmp -> next;
        delete tmp;
        
        return head;
    }
};
