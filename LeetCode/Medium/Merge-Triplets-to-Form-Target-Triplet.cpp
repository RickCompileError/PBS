// Time: O(n), Space: O(1)
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int exist = 0;

        for (vector<int>& triplet: triplets) {
            int lower = 0;
            bool valid = true;
            for (int i = 0; i < 3 && valid; i++) {
                if (triplet[i] > target[i]) {
                    valid = false;
                }
                if (triplet[i] == target[i]) {
                    lower |= (1 << i);
                }
            }
            if (valid) {
                exist |= lower;
            }
        }

        return exist == 0b111;
    }
};

// Time: O(n), Space: O(1)
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool x{0}, y{0}, z{0};

        for (vector<int>& triplet: triplets) {
            x |= (triplet[0] == target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]);
            y |= (triplet[0] <= target[0] && triplet[1] == target[1] && triplet[2] <= target[2]);
            z |= (triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] == target[2]);
            if (x && y && z) {
                return true;
            }
        }

        return false;
    }
};
