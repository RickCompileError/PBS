// Time: O(nlogn), Space: O(n)
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int sz = hand.size();

        if (sz % groupSize != 0) {
            return false;
        }

        map<int,int> m;
        for (auto& i: hand) {
            m[i]++;
        }

        for (auto& [k,v]: m) {
            if (v == 0) {
                continue;
            }

            int freq = v;
            for (int i = 0; i < groupSize; i++) {
                m[k + i] -= freq;
                if (m[k + i] < 0) {
                    return false;
                }
            }
        }

        return true;
    }
};

// Time: O(n), Space: O(n)
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int sz = hand.size();

        if (sz % groupSize != 0) {
            return false;
        }

        unordered_map<int,int> m;
        for (auto& i: hand) {
            m[i]++;
        }

        for (auto& [k,v]: m) {
            if (v == 0) {
                continue;
            }
            int start = k;

            while (m[start - 1] > 0) {
                start--;
            }
            while (start <= k) {
                while (m[start] > 0) {
                    int freq = m[start];
                    for (int i = 0; i < groupSize; i++) {
                        if (m[start + i] < freq) {
                            return false;
                        }
                        m[start + i] -= freq;
                    }
                }
                start++;
            }
        }

        return true;
    }
};

// Time: O(nlogn), Space: O(1), more faster
class Solution {
private:
    bool findConsecutive(vector<int>& hand, int groupSize, int idx, int sz) {
        int nxt = hand[idx] + 1;
        int count = 1;
        hand[idx] = -1;
        idx++;

        while (idx < sz && count < groupSize) {
            if (hand[idx] == nxt) {
                nxt++;
                count++;
                hand[idx] = -1;
            }
            idx++;
        }

        return count == groupSize;
    }

public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int sz = hand.size();

        if (sz % groupSize != 0) {
            return false;
        }

        sort(hand.begin(), hand.end());

        for (int i = 0; i < sz; i++) {
            if (hand[i] >= 0 && !findConsecutive(hand, groupSize, i, sz)) {
                return false;
            }
        }

        return true;
    }
};
