class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int size = arr.size();

        int leftNonDec = 0;
        while (leftNonDec + 1 < size && arr[leftNonDec] <= arr[leftNonDec + 1]) {
            leftNonDec++;
        }

        if (leftNonDec == size - 1) return 0;

        int rightNonDec = size - 1;
        while (rightNonDec - 1 >= 0 && arr[rightNonDec - 1] <= arr[rightNonDec]) {
            rightNonDec--;
        }

        int ans = min(size - leftNonDec - 1, rightNonDec);

        int l = 0, r = rightNonDec;
        while (l <= leftNonDec && r < size) {
            if (arr[l] <= arr[r]) {
                ans = min(ans, r - l - 1);
                l++;
            } else {
                r++;
            }
        }
        
        return ans;
    }
};
