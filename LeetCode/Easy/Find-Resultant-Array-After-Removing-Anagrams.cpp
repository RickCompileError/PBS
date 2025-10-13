// Time: O(n), Space: O(1)
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        for (int i = 1; i < words.size();) {
            string tmp1 = words[i - 1];
            string tmp2 = words[i];
            sort(tmp1.begin(), tmp1.end());
            sort(tmp2.begin(), tmp2.end());

            if (tmp1 == tmp2) {
                words.erase(words.begin() + i);
            } else {
                i++;
            }
        }

        return words;
    }
};
