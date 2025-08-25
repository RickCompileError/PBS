// Time: O(nk), Space: O(n)
class FindSumPairs {
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int,int> m2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this -> nums1 = nums1;
        this -> nums2 = nums2;
        for (auto& i: nums2) {
            m2[i]++;
        }
    }

    void add(int index, int val) {
        m2[this -> nums2[index]]--;
        this -> nums2[index] += val;
        m2[this -> nums2[index]]++;
    }

    int count(int tot) {
        int counter = 0;
        for (auto& i: this -> nums1) {
            counter += m2[tot - i];
        }
        return counter;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
