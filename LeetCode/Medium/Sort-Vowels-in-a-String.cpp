// Time: O(nlogn), Space: O(n)
class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

public:
    string sortVowels(string s) {
        string vowels = "";
        
        for (auto& c: s) {
            if (isVowel(c)) {
                vowels.push_back(c);
            }
        }

        sort(vowels.begin(), vowels.end());

        int ssz = s.size(), vsz = vowels.size();

        for (int i = 0, j = 0; i < ssz && j < vsz; i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[j++];
            }
        }

        return s;
    }
};
