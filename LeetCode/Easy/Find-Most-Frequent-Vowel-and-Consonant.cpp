class Solution {
public:
    int maxFreqSum(string s) {
        map<char,int> freq;

        for (auto& c: s) {
            freq[c]++;
        }

        int vowel = 0, consonant = 0;
        
        for (auto& [k, v]: freq) {
            if (k == 'a' || k == 'e' || k == 'i' || k == 'o' || k == 'u') {
                vowel = max(vowel, freq[k]);
            } else {
                consonant = max(consonant, freq[k]);
            }
        }

        return vowel + consonant;
    }
};
