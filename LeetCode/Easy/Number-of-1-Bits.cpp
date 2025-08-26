class Solution {
public:
    int hammingWeight(int n) {
        int counter = 0;
        while (n) {
            counter += (1 & n);
            n >>= 1;
        }
        return counter;
    }
};
