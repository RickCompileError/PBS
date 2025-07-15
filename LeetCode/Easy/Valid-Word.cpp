// Time: O(n), Space: O(1)
class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) {
            return false;
        }

        bool isVowel = false, isConsonant = false;

        for (auto& c: word) {
            if (c >= '0' && c <= '9') {
                continue;
            }
            c = tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                isVowel = true;
                continue;
            } else if (c >= 'a' && c <= 'z') {
                isConsonant = true;
                continue;
            }
            return false;
        }

        return isVowel && isConsonant;
    }
};
