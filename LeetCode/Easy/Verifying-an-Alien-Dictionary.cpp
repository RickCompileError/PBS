// Time: O(mn), Space: O(1)
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int sz = words.size();
        unordered_map<char,int> letterValue;
        auto greater = [&](const auto& a, const auto& b) {
            int sza = a.size();
            int szb = b.size();

            for (int idx = 0; idx < sza && idx < szb; idx++) {
                // string a greater than string b at idx
                if (letterValue[a[idx]] > letterValue[b[idx]]) {
                    return true;
                }
                // string a smaller than string b at idx
                if (letterValue[a[idx]] < letterValue[b[idx]]) {
                    return false;
                }
            }

            // string a == string b from range(0, min(sza, szb)) but longer than string b
            return sza > szb ? true : false;
        };

        for (int i = 0; i < 26; i++) {
            letterValue[order[i]] = i;
        }

        for (int i = 1; i < sz; i++) {
            if (greater(words[i - 1], words[i])) {
                return false;
            }
        }

        return true;
    }
};
