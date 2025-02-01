// Add operate: O(n), Search Operate: O(26^n), Space: O(26^t), Number of Nodes, depend on the length of word
class Node {
public:
    unordered_map<char, Node*> childs;
    bool isWord;

    Node() {
        isWord = false;
    }
};

class WordDictionary {
private:
    bool backtracking(int idx, string word, Node* node) {
        if (idx == word.size()) {
            return node -> isWord;
        }

        if (word[idx] != '.') {
            return node -> childs[word[idx]] != nullptr && backtracking(idx + 1, word, node -> childs[word[idx]]);
        }

        for (const auto& [k, v]: node -> childs) {
            if (v != nullptr && backtracking(idx + 1, word, v)) {
                return true;
            }
        }

        return false;
    }

public:
    Node* root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;

        for (auto& i: word) {
            if (node -> childs[i] == nullptr) {
                node -> childs[i] = new Node();
            }

            node = node -> childs[i];
        }

        node -> isWord = true;
    }
    
    bool search(string word) {
        return backtracking(0, word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
