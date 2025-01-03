/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// O(n), change the pointer value
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head -> next == nullptr) {
            return false;
        }
        
        ListNode *iter = head, *prev;
        while (iter -> next) {
            if (iter -> next -> next == head) {
                return true;
            }

            prev = iter;
            iter = iter -> next;
            prev -> next = head;

        }

        return false;
    }
};

// Floyd's cycle finding algorithm or Hare-Tortoise algorithm
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast -> next && fast -> next -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
            if (fast == slow) {
                return true;
            }
        }

        return false;
    }
};
