// Time: O(nlogn), Space: O(n)
const int N = 2048;
class SegmentTree {
private:
    unsigned n;
    vector<int> seg;

public:
    SegmentTree(vector<int>& A): n(A.size()), seg(N) {
        build(A, 1, 0, n - 1);
    }

    void build(vector<int>& A, int idx, int l, int r) {
        if (l == r) {
            seg[idx] = A[l];
        } else {
            const int m = (l + r) / 2;
            build(A, 2 * idx, l, m);
            build(A, 2 * idx + 1, m + 1, r);
            seg[idx] = max(seg[2 * idx], seg[2 * idx + 1]);
        }
    }

    int search(int idx, int l, int r, int k) {
        if (seg[idx] < k) {
            return -1;
        }

        if (l == r) {
            seg[idx] = -1;
            return l;
        }

        const int m = (l + r) / 2;
        int pos;

        if (seg[2 * idx] >= k) {
            pos = search(2 * idx, l, m, k);
        } else {
            pos = search(2 * idx + 1, m + 1, r, k);
        }

        seg[idx] = max(seg[2 * idx], seg[2 * idx + 1]);

        return pos;
    }

    void print() {

    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        const int n = fruits.size();
        int ans = 0;
        SegmentTree tree(baskets);

        for (auto& f: fruits) {
            if (tree.search(1, 0, n - 1, f) == -1) {
                ans++;
            }
        }

        return ans;
    }
};
