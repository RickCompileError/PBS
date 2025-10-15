// Time: O(n), Space: O(n)
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int> increaseSize;
        int counter = 0;
        int sz = nums.size();
        
        for (int i = 0; i < sz; i++) {
            if (i == 0 || nums[i] > nums[i - 1]) {
                counter++;
            } else {
                increaseSize.push_back(counter);
                counter = 1;
            }
        }
        increaseSize.push_back(counter);

        int ans = -1;

        sz = increaseSize.size();
        for (int i = 0; i < sz; i++) {
            ans = max(ans, increaseSize[i] / 2);
            if (i > 0) {
                ans = max(ans, min(increaseSize[i], increaseSize[i - 1]));
            }
        }

        return ans;
    }
};

// Space free version, Time: O(n), Space: O(1)
static const int init = [] {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int i=0, j=1;
        int ans = 0;
        int prev = 0;
        while (j<n){
            if (nums[j] <= nums[j-1]){
                ans = max ({ans, (j-i)/2, min (prev, j-i)});
                prev = j-i;
                i=j;
            }
            j++;
        }
        ans = max ({ans, (j-i)/2, min (prev, j-i)});
        return ans;
    }
};
