// Time: O(n), Space: O(1)
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *tmp{head}, *prev{head};
        int sz = 0;
        while (tmp) sz++, tmp = tmp -> next;
        tmp = head;
        if (sz == 1) return NULL;
        sz = sz / 2 - 1;
        while (sz >= 0) {
            prev = tmp;
            tmp = tmp -> next;
            sz--;
        }
        prev -> next = tmp -> next;
        return head;
    }
};

// Time: O(n/2) ~= O(n), Space: O(1)
// fast slow approach
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // size == 1
        if (!head->next) return NULL;

        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* n = NULL;
        // slow step is 1, fast step is 2, so slow will right in the middle when fast arrive to the end
        while (fast && fast->next) {
            n = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // situation one, if fast is NULL, means the size of the list is odd
        if (fast == NULL) {
            n->next = slow->next;
            delete slow;
            return head;
        }
        // situation two, if fast is not NULL, means the size of the list is even 
        if (fast->next == NULL) {
            ListNode* m = slow->next;
            slow->next = m->next;
            delete m;
            return head;
        }
        return head;
    }
};