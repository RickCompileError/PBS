/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// Time: O(n), amount of nodes
class Solution {
public:
    unordered_map<int, Node*> nodes;

    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        
        if (nodes[node -> val]) {
            return nodes[node -> val];
        }

        Node* cNode = new Node(node -> val);
        nodes[node -> val] = cNode;

        vector<Node*> _neighbors;
        for (auto& i: node -> neighbors) {
            _neighbors.push_back(cloneGraph(i));
        }

        cNode -> neighbors = _neighbors;

        return cNode;
    }
};
