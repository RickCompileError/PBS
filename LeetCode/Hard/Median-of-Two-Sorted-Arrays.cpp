// O(m + n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size(), sz2 = nums2.size();
        int halfR = (sz1 + sz2) / 2 + 1;

        int counter1 = 0, counter2 = 0;
        int midL = 0, midR = 0;

        for (int counter = 0; counter < halfR; counter++) {
            midL = midR;
            if (counter1 < sz1 && counter2 < sz2) {
                if (nums1[counter1] < nums2[counter2]) {
                    midR = nums1[counter1++];
                } else {
                    midR = nums2[counter2++];
                }
            } else if (counter1 < sz1) {
                midR = nums1[counter1++];
            } else {
                midR = nums2[counter2++];
            }
        }

        return (sz1 + sz2) % 2 ? (double)midR : (midL + midR) / 2.0;
    }
};

// O(log(min(m, n)))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int half = (total + 1) / 2;

        if (nums2.size() < nums1.size()) {
            swap(nums2, nums1);
        }        

        int l = 0;
        int r = nums1.size();

        while (l <= r) {
            int m = l + (r - l) / 2;
            int remain = half - m;

            int left1 = m > 0 ? nums1[m - 1] : INT_MIN;
            int right1 = m < nums1.size() ? nums1[m] : INT_MAX;
            int left2 = remain > 0 ? nums2[remain - 1] : INT_MIN;
            int right2 = remain < nums2.size() ? nums2[remain] : INT_MAX;

            if (left1 <= right2 && left2 <= right1) {
                return total % 2 ? max(left1, left2) : (max(left1, left2) + min(right1, right2)) / 2.0;
            } else if (left1 > right2) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return -1;
    }
};
