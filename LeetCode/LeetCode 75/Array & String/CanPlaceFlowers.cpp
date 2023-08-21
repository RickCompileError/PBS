// Complexity: O(n), Space: O(1)
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0, sz = flowerbed.size(); i < sz; i++) {
            if (flowerbed[i] == 1) continue;

            if (i + 1 < sz && flowerbed[i+1] == 1) continue;
            if (i - 1 >= 0 && flowerbed[i-1] == 1) continue;
            flowerbed[i] = 1;
            n--;
        }
        return n <= 0;
    }
};