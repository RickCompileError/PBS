// Time: O(n) for each function call, Space: O(t) the number of Nodes
class Node {
public:
    unordered_map<char, Node*> childs;
    bool isWord;

    Node() {
        isWord = false;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* nxt = root;

        for (auto& i: word) {
            if (nxt -> childs[i] == nullptr) {
                nxt -> childs[i] = new Node();
            }
            nxt = nxt -> childs[i];
        }

        nxt -> isWord = true;
    }
    
    bool search(string word) {
        Node* nxt = root;

        for (auto& i: word) {
            if (nxt -> childs[i] == nullptr) {
                return false;
            }
            nxt = nxt -> childs[i];
        }

        return nxt -> isWord;
    }
    
    bool startsWith(string prefix) {
        Node* nxt = root;

        for (auto& i: prefix) {
            if (nxt -> childs[i] == nullptr) {
                return false;
            }
            nxt = nxt -> childs[i];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
