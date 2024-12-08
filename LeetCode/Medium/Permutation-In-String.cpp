class Solution {
private:
    bool check(vector<int>& v) {
        for (auto& i: v) if (i != 0) return false;
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v(26, 0);
        int sz1 = s1.size(), sz2 = s2.size();

        if (sz1 > sz2) return false;
        
        int i;
        for (i = 0; i < sz1; i++) {
            v[s1[i] - 'a']++;
            v[s2[i] - 'a']--;
        }

        while (i < sz2) {
            if (check(v)) return true;
            v[s2[i - sz1] - 'a']++;
            v[s2[i] - 'a']--;
            i++;
        }

        return check(v);
    }
};
