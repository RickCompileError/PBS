// Time: O(n), Space: O(1)
class Solution {
public:
    int possibleStringCount(string word) {
        int counter = 1;
        char ch = '-';
        int possible = 0;

        for (auto& c: word) {
            if (c != ch) {
                possible += (counter - 1);
                ch = c;
                counter = 1;
            } else {
                counter++;
            }
        }
        possible += (counter - 1);

        return possible + 1;
    }
};
