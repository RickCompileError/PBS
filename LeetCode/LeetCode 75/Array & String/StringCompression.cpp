// Complexity: O(n), Space: O(1) 
class Solution {
public:
    int compress(vector<char>& chars) {
        int counter = 0, pos = 0;
        char curCh = chars[0];
        string newChars = "";
        for (char i: chars) {
            if (i == curCh) {
                counter++;
                continue;
            }
            newChars += curCh;
            if (counter > 1) newChars += to_string(counter);
            curCh = i;
            counter = 1;
        }
        newChars += curCh;
        if (counter > 1) newChars += to_string(counter);
        chars = vector(newChars.begin(), newChars.end());
        return chars.size();
    }
};

// Another version, more concise but more runtime, must seperate the if condition
class Solution {
public:
    int compress(vector<char>& chars) {
        int left = 0;
        string newChars = "";
        for (int i = 1, sz = chars.size(); i <= sz; i++) {
            if (i == sz || chars[i] != chars[left]) {
                newChars += chars[left];
                if (i - left > 1) newChars += to_string(counter);
                left = i;
            }
        }
        chars = vector(newChars.begin(), newChars.end());
        return chars.size();
    }
};