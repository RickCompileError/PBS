/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// Space: O(N)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }

        map<Node*, Node*> m;
        Node* iter = head;
        m[head] = new Node(head -> val);

        while (iter) {
            // handle next
            if (iter -> next) {
                if (!m[iter -> next]) {
                    m[iter -> next] = new Node(iter -> next -> val);
                }
                m[iter] -> next = m[iter -> next];
            }

            // handle random
            if (iter -> random) {
                if (!m[iter -> random]) {
                    m[iter -> random] = new Node(iter -> random -> val);
                }
                m[iter] -> random = m[iter -> random];
            }

            iter = iter -> next;
        }

        return m[head];
    }
};

// Time: O(n), Space: constant
