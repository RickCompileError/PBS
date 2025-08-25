// Time: O(alpha(n)) (amortized time), Space: O(26)
class Solution {
private:
    int findSet(vector<int>& v, int c) {
        if (c == v[c]) {
            return c;
        }
        return v[c] = findSet(v, v[c]);
    }

    void unionSet(vector<int>& v, int a, int b) {
        a = findSet(v, a);
        b = findSet(v, b);
        if (a != b) {
            if (a > b) {
                swap(a, b);
            }
            v[b] = a;
        }
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int ssz = s1.size();
        int bsz = baseStr.size();
        vector<int> DJS(26);

        for (int i = 0; i < 26; i++) DJS[i] = i;
        for (int i = 0; i < ssz; i++) {
            unionSet(DJS, s1[i] - 'a', s2[i] - 'a');
        }
        for (int i = 0; i < bsz; i++) {
            baseStr[i] = findSet(DJS, baseStr[i] - 'a') + 'a';
        }

        return baseStr;
    }
};
