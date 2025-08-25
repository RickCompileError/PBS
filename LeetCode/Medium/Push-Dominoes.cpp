// Time: O(n), Space: O(1)
class Solution {
public:
    string pushDominoes(string dominoes) {
        int sz = dominoes.size();
        int right = -1;

        for (int i = 0; i < sz; i++) {
            if (dominoes[i] == 'L') {
                int left = i - 1;
                if (right == -1) {
                    for (; left >= 0 && dominoes[left] == '.'; left--) {
                        dominoes[left] = 'L';
                    }
                } else {
                    while (right < left) {
                        dominoes[right++] = 'R';
                        dominoes[left--] = 'L';
                    }
                    right = -1;
                }
            } else if (dominoes[i] == 'R') {
                if (right != -1) {
                    while (right < i) {
                        dominoes[right++] = 'R';
                    }
                }
                right = i + 1;
            }
        }
        if (right != -1) {
            while (right < sz) {
                dominoes[right++] = 'R';
            }
        }

        return dominoes;
    }
};
