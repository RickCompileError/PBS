// Time: O(n), Space: O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode* odd{head};
        ListNode* even{head->next};
        ListNode* firstEven;
        ListNode* nextOdd;
        while (odd && even && even->next) {
            // get the next odd need to be concatenated
            nextOdd = even->next;
            // get the first even in the list which will be pointed from next odd node
            firstEven = odd->next;
            // concatenate odd
            odd->next = nextOdd;
            // concatenate even
            even->next = nextOdd->next;
            // concatenate new odd node and the first even node
            nextOdd->next = firstEven;
            // update odd node and even node
            odd = nextOdd;
            even = even->next;
        }
        return head;
    }
};