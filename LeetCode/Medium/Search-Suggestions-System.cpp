// Time: O(mn), Space: O(mn), m = # of prods, n = avg len of prods
class Node {
public:
    map<int, Node*> childs;
    bool exist;
    string word;

    Node(){
        exist = false;
        word = "";
    };
};

class Trie {
private:
    Node* node;

public:
    Trie() {
        node = new Node();
    }

    void insert(string& w) {
        Node* nxt = node;

        for (auto& c: w) {
            if (nxt -> childs[c] == nullptr) {
                nxt -> childs[c] = new Node();
            }
            nxt = nxt -> childs[c];
        }

        nxt -> exist = true;
        nxt -> word = w;
    }

    vector<vector<string>> predict(string s) {
        vector<vector<string>> suggests;
        Node* nxt = node;

        for (auto& c: s) {
            if (nxt -> childs[c] == nullptr) {
                nxt -> childs[c] = new Node();
            }
            nxt = nxt -> childs[c];
            vector<string> suggest;
            int predictAmount = 3;
            dfs(nxt, suggest, predictAmount);
            suggests.push_back(suggest);
        }

        return suggests;
    }

    void dfs(Node* node, vector<string>& v, int& count) {
        if (count == 0) {
            return;
        }
        if (node -> exist) {
            v.push_back(node -> word);
            count--;
        }
        for (auto& [key, val]: node -> childs) {
            dfs(val, v, count);
        }
        return;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* t = new Trie();
        for (auto& product: products) {
            t -> insert(product);
        }
        vector<int> empty;
        return t -> predict(searchWord);
    }
};

// Time: O(nlogn), Space: O(1)
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        for (auto& p: products) cout <<p <<endl;
        vector<vector<string>> result;
        int start, prevStart = 0, sz = products.size();
        string prefix = "";

        for (auto& c: searchWord) {
            prefix += c;
            start = lower_bound(products.begin() + prevStart, products.end(), prefix) - products.begin();
            result.push_back({});
            for (int i = start; i < min(start + 3, sz) && !products[i].compare(0, prefix.size(), prefix); i++) {
                result.back().push_back(products[i]);
            }
            prevStart = start;
        }

        return result;
    }
};
