class Solution {
private:
    int circularIdx(const int& size, int idx) {
        return (size + idx) % size;
    }

public:
    vector<int> decrypt(vector<int>& code, int k) {
        int size = code.size();

        if (k == 0) return vector<int>(size, 0);

        vector<int> ans(size);
        if (k > 0) {
            int nextK = 0;
            for (int i = 0; i < k; i++) {
                nextK += code[circularIdx(size, i)];
            }

            for (int i = 0; i < size; i++) {
                nextK = nextK - code[circularIdx(size, i)] + code[circularIdx(size, i + k)];
                ans[i] = nextK;
            }
        } else {
            int prevK = 0;
            for (int i = -2; i > k - 2; i--) {
                prevK += code[circularIdx(size, i)];
            }

            for (int i = 0; i < size; i++) {
                prevK = prevK - code[circularIdx(size, i + k - 1)] + code[circularIdx(size, i - 1)];
                ans[i] = prevK;
            }
        }

        return ans;
    }
};

// clear
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int size = code.size();
        vector<int> ans(size, 0);
        if (k == 0) {
            return ans;
        }

        int start = 1, end = k, sum = 0;
        if (k < 0) {
            start = size - abs(k);
            end = size - 1;
        }

        for (int i = start; i <= end; i++) sum += code[i];
        for (int i = 0; i < size; i++) {
            ans[i] = sum;
            sum += code[(end + 1) % size];
            sum -= code[start % size];
            start++;
            end++;
        }

        return ans;
    }
};
