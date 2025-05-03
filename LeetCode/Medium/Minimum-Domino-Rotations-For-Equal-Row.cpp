// Ugly, Time: O(a+b), Space: O(1)
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int sz = tops.size();
        int counter[4]{0};

        for (int i = 0; i < sz; i++) {
            if (tops[0] != tops[i] && tops[0] != bottoms[i]) {
                counter[0] = counter[1] = -1;
                break;
            }
            if (tops[0] != tops[i]) {
                counter[0]++;
            } else if (tops[0] != bottoms[i]) {
                counter[1]++;
            }
        }
        for (int i = 0; i < sz; i++) {
            if (bottoms[0] != tops[i] && bottoms[0] != bottoms[i]) {
                counter[2] = counter[3] = -1;
                break;
            }
            if (bottoms[0] != tops[i]) {
                counter[2]++;
            } else if (bottoms[0] != bottoms[i]) {
                counter[3]++;
            }
        }

        int topMin = min(counter[0], counter[1]);
        int bottomMin = min(counter[2], counter[3]);
        return topMin < 0 && bottomMin < 0 ? -1 : topMin < 0 ? bottomMin : bottomMin < 0 ? topMin : min(topMin, bottomMin);
    }
};

// Count intersection, Time: O(n), Space: O(1)
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int sz = tops.size();
        vector<int> countTop(7, 0), countBottom(7, 0), countSame(7, 0);

        for (int i = 0; i < sz; i++) {
            countTop[tops[i]]++;
            countBottom[bottoms[i]]++;
            if (tops[i] == bottoms[i]) {
                countSame[tops[i]]++;
            }
        }

        for (int i = 1; i <= 6; i++) {
            if (countTop[i] + countBottom[i] - countSame[i] == sz) {
                return min(countTop[i], countBottom[i]) - countSame[i];
            }
        }

        return -1;
    }
};
