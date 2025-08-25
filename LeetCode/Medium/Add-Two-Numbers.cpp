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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int value, carry = 0;
        ListNode *l1Iter = l1, *l2Iter = l2;
        ListNode *ans = new ListNode(), *ansIter = ans;

        while (l1Iter && l2Iter) {
            value = l1Iter -> val + l2Iter -> val + carry;
            carry = value / 10;
            value %= 10;
            ansIter -> next = new ListNode(value);
            ansIter = ansIter -> next;
            l1Iter = l1Iter -> next;
            l2Iter = l2Iter -> next;
        }

        while (l1Iter) {
            value = l1Iter -> val + carry;
            carry = value / 10;
            value %= 10;
            ansIter -> next = new ListNode(value);
            ansIter = ansIter -> next;
            l1Iter = l1Iter -> next;
        }

        while (l2Iter) {
            value = l2Iter -> val + carry;
            carry = value / 10;
            value %= 10;
            ansIter -> next = new ListNode(value);
            ansIter = ansIter -> next;
            l2Iter = l2Iter -> next;
        }

        if (carry) {
            ansIter -> next = new ListNode(carry);
        }

        ansIter = ans;
        ans = ans -> next;
        delete ansIter;
        return ans;
    }
};

// Simplify
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int value, carry = 0;
        ListNode *l1Iter = l1, *l2Iter = l2;
        ListNode *ans = new ListNode(), *ansIter = ans;

        while (l1Iter || l2Iter || carry) {
            int dig1 = l1Iter ? l1Iter -> val : 0;
            int dig2 = l2Iter ? l2Iter -> val : 0;

            int sum = dig1 + dig2 + carry;
            carry = sum / 10;

            ansIter -> next = new ListNode(sum % 10);
            ansIter = ansIter -> next;

            l1Iter = l1Iter ? l1Iter -> next : nullptr;
            l2Iter = l2Iter ? l2Iter -> next : nullptr;
        }

        ansIter = ans;
        ans = ans -> next;
        delete ansIter;

        return ans;
    }
};
