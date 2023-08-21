// Time: O(nlogn), Space(n)
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // the lengths of two words aren't same
        if (word1.size() != word2.size()) return false;
        // first, check two words use same letter
        set<char> s1(word1.begin(), word1.end()), s2(word2.begin(), word2.end());
        if (s1 != s2) return false;
        // second, count the letters
        map<char,int> counter1, counter2;
        for (char i: word1) counter1[i]++;
        for (char i: word2) counter2[i]++;
        // third, examine if the times are same
        map<int,int> counterer1, counterer2;
        for (auto const& [key,val]: counter1) counterer1[val]++;
        for (auto const& [key,val]: counter2) counterer2[val]++;
        return counterer1 == counterer2;
    }
};

// Another version, using unordered_map
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // the lengths of two words aren't same
        if (word1.size() != word2.size()) return false;
        // map the words
        unordered_map<char,int> mc1, mc2;
        for (char i: word1) mc1[i]++;
        for (char i: word2) mc2[i]++;
        // reconstruct the word to non-repeat word, and map the times of the letters
        string m1s, m2s;
        unordered_map<int,int> mi1, mi2;
        for (auto const& [key, val]: mc1) m1s += key, mi1[val]++;
        for (auto const& [key, val]: mc2) m2s += key, mi2[val]++;
        sort(m1s.begin(), m1s.end()), sort(m2s.begin(), m2s.end());
        return m1s == m2s && mi1 == mi2;
    }
};