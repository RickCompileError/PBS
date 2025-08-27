/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * }
 */

// Compare one by one
// Time: O(m*n), Space: O(n)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(1e5);
        ListNode* tail = head;
        int sz = lists.size();

        while (true) {
            int minList = -1;
            ListNode* tmp = nullptr;
            for (int i = 0; i < sz; i++) {
                if (lists[i] == nullptr) {
                    continue;
                }

                if (minList < 0 || lists[i] -> val < lists[minList] -> val) {
                    minList = i;
                }
            }

            if (minList < 0) {
                break;
            }

            tmp = lists[minList];
            lists[minList] = lists[minList] -> next;
            tmp -> next = nullptr;
            tail -> next = tmp;
            tail = tail -> next;
        }

        tail = head;
        head = head -> next;
        delete tail;

        return head;
    }
};

// Compare by PQ
// Time: O(nlogn), Space: O(k)
#define PIL pair<int, ListNode*>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(1e5);
        ListNode* tail = head;
        int sz = lists.size();
        priority_queue<PIL, vector<PIL>, greater<PIL>> pq;

        for (int i = 0; i < sz; i++) {
            if (lists[i] != nullptr) {
                pq.push({lists[i] -> val, lists[i]});
            }
        }

        while (pq.size() > 0) {
            PIL tmp = pq.top(); pq.pop();
            if (tmp.second -> next != nullptr) {
                pq.push({tmp.second -> next -> val, tmp.second -> next});
            }

            tail -> next = tmp.second;
            tail = tail -> next;
        }

        tail = head;
        head = head -> next;
        delete tail;
        return head;
    }
};

// Merge List
// Time: O(nlogk), Space: O(logk)
class Solution {
public:
    ListNode* mergeList(ListNode *left, ListNode *right) {
        ListNode *head = new ListNode();
        ListNode *tail = head;
        while (left && right) {
            if (left -> val <= right -> val) {
                tail -> next = left;
                left = left -> next;
            } else {
                tail -> next = right;
                right = right -> next;
            }
            tail = tail -> next;
        }

        tail -> next = left ? left : right;

        tail = head;
        head = head -> next;
        delete tail;
        return head;
    }

    ListNode* divideAndConquer(vector<ListNode*>& lists, int low, int high) {
        if (low > high) {
            return nullptr;
        }

        if (low == high) {
            return lists[low];
        }

        int mid = low + (high - low) / 2;
        ListNode *left = divideAndConquer(lists, low, mid);
        ListNode *right = divideAndConquer(lists, mid + 1, high);
        return mergeList(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return divideAndConquer(lists, 0, lists.size() - 1);
    }
};
