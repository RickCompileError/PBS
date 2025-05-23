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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        ListNode* ans;
        head = ans = new ListNode();

        while (list1 && list2) {
            if (list1 -> val <= list2 -> val) {
                head -> next = list1;
                list1 = list1 -> next;
                head = head -> next;
            } else {
                head -> next = list2;
                list2 = list2 -> next;
                head = head -> next;
            }
        }

        while (list1) {
            head -> next = list1;
            list1 = list1 -> next;
            head = head -> next;
        }

        while (list2) {
            head -> next = list2;
            list2 = list2 -> next;
            head = head -> next;
        }

        return ans -> next ? ans -> next : nullptr;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        ListNode* ans;
        head = ans = new ListNode();

        while (list1 && list2) {
            if (list1 -> val <= list2 -> val) {
                head -> next = list1;
                list1 = list1 -> next;
            } else {
                head -> next = list2;
                list2 = list2 -> next;
            }
            head = head -> next;
        }

        head -> next = list1 ? list1 : list2;
        return ans -> next;
    }
};
