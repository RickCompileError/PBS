class Solution {
public:
    int findClosest(int x, int y, int z) {
        int xdis = abs(x - z), ydis = abs(y - z);
        return xdis == ydis ? 0 : (xdis < ydis ? 1 : 2);
    }
};
