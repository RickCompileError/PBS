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
// Stack version, time complexity O(n)
class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        ListNode* iter = head;
        ListNode* tmp;

        int counter = 0;
        while (iter) {
            counter++;
            s.push(iter);
            iter = iter -> next;
        }
        counter /= 2;

        iter = head;
        while (counter--) {
            tmp = iter -> next;
            iter -> next = s.top();
            iter -> next -> next = tmp;
            iter = tmp;
            s.pop();
        }

        iter -> next = nullptr;
    }
};

class Solution {
public:
    ListNode* splitList(ListNode* head) {
        ListNode* left;
        ListNode* right;
        left = right = head;

        while (left -> next && left -> next -> next) {
            left = left -> next -> next;
            right = right -> next;
        }

        if (right -> next) {
            left = right;
            right = right -> next;
            left -> next = nullptr;
        }

        return right;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev;
        ListNode* curr;
        curr = prev = nullptr;
        while (head) {
            curr = head;
            head = head -> next;
            curr -> next = prev;
            prev = curr;
        }

        return curr;
    }

    // left size always larger than right size
    void mergeList(ListNode* left, ListNode* right) {
        ListNode *l = left, *r = right, *tmp = nullptr;
        while (r) {
            tmp = l -> next;
            l -> next = r;
            r = r -> next;
            l -> next -> next = tmp;
            l = tmp;
        }
    }

    void reorderList(ListNode* head) {
        if (!head -> next) return;
        ListNode* tail = splitList(head);
        tail = reverseList(tail);
        mergeList(head, tail);
    }
};
