// Time: O(n^3), Space: O(1)
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int sz = arr.size();
        int good = 0;
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                for (int k = j + 1; k < sz; k++) {
                    if (abs(arr[i] - arr[j]) > a) {
                        continue;
                    }
                    if (abs(arr[j] - arr[k]) > b) {
                        continue;
                    }
                    if (abs(arr[i] - arr[k]) > c) {
                        continue;
                    }
                    good++;
                }
            }
        }
        return good;
    }
};
