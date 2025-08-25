// Time: O(n), Space: O(n)
class Solution {
private:
    char mn(vector<int>& f) {
        for (int i = 0; i < 26; i++) {
            if (f[i]) {
                return 'a' + i;
            }
        }
        return 'z' + 1;
    }

public:
    string robotWithString(string s) {
        string ans = "";
        vector<int> freq(26, 0);
        stack<char> t;

        for (auto& c: s) {
            freq[c - 'a']++;
        }

        for (auto& c: s) {
            freq[c - 'a']--;
            t.push(c);

            while (t.size() && t.top() <= mn(freq)) {
                ans += t.top();
                t.pop();
            }
        }

        while (t.size()) {
            ans += t.top();
            t.pop();
        }

        return ans;
    }
};

// Simplify
class Solution {
public:
    string robotWithString(string s) {
        int low = 0;
        string ans = "";
        vector<int> freq(26, 0);
        stack<char> t;

        for (auto& c: s) {
            freq[c - 'a']++;
        }

        for (auto& c: s) {
            freq[c - 'a']--;
            t.push(c);

            while (low < 25 && freq[low] == 0) {
                low++;
            }

            while (t.size() && t.top() - 'a' <= low) {
                ans += t.top();
                t.pop();
            }
        }

        return ans;
    }
};
