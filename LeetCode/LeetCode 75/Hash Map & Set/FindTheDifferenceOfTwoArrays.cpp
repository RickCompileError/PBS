// Time: O(m+n), Space: O(m+n)
// handmade
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2, vector<int>(0));
        set<int> s1, s2;
        for (int i: nums1) s1.insert(i);
        for (int i: nums2) s2.insert(i);
        set<int>::iterator first1 = s1.begin(), last1 = s1.end(), first2 = s2.begin(), last2 = s2.end();
        while (first1 != last1 && first2 != last2) {
            if (*first1 < *first2) ans[0].emplace_back(*first1++);
            else if (*first2 < *first1) ans[1].emplace_back(*first2++);
            else first1++, first2++;
        }
        while (first1 != last1) ans[0].emplace_back(*first1++);
        while (first2 != last2) ans[1].emplace_back(*first2++);
        return ans;
    }
};

// more concise code
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        set<int>::iterator first1 = s1.begin(), last1 = s1.end(), first2 = s2.begin(), last2 = s2.end();
        vector<int> diff1, diff2;
        while (first1 != last1 && first2 != last2) {
            if (*first1 < *first2) diff1.emplace_back(*first1++);
            else if (*first2 < *first1) diff2.emplace_back(*first2++);
            else first1++, first2++;
        }
        while (first1 != last1) diff1.emplace_back(*first1++);
        while (first2 != last2) diff2.emplace_back(*first2++);
        return {diff1, diff2};
    }
};