// Time: O(mn), Space: O(n), m: avg of string size, n: # of string
class Solution {
private:
    string toLower(string s) {
        for (auto& c: s) {
            c = tolower(c);
        }
        return s;
    }

    string toVowel(string s) {
        s = toLower(s);
        for (auto& c: s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '#';
            }
        }
        return s;
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> us(wordlist.begin(), wordlist.end());
        unordered_map<string,string> ucap, uvowel;

        for (auto& word: wordlist) {
            string lower = toLower(word);
            string vowel = toVowel(word);
            ucap.insert({lower, word});
            uvowel.insert({vowel, word});
        }

        vector<string> ans;

        for (auto& query: queries) {
            if (us.find(query) != us.end()) {
                ans.push_back(query);
                continue;
            }
            string lowerQuery = toLower(query), vowelQuery = toVowel(query);
            if (ucap[lowerQuery] != "") {
                ans.push_back(ucap[lowerQuery]);
            } else if (uvowel[vowelQuery] != "") {
                ans.push_back(uvowel[vowelQuery]);
            } else {
                ans.push_back("");
            }
        }

        return ans;
    }
};
