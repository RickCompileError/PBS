// Time: O(logn), Space: O(1)
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int counter = 0;
        int multi = 0;

        k--;
        while (k > 0) {
            if ((k & 1) && operations[multi]) {
                counter++;
            }
            k >>= 1;
            multi = (multi + 1) % operations.size();
        }

        return 'a' + counter % 26;
    }
};
