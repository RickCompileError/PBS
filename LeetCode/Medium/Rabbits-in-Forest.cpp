// Time: O(n), Space: O(n)
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        unordered_map<int,int> forest;

        for (auto& i: answers) {
            if (forest[i]) {
                forest[i]--;
                continue;
            }
            ans += i + 1;
            forest[i] = i;
        }

        return ans;
    }
};

// Time: O(nlogn), Space: O(1)
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        int sz = answers.size();
        sort(answers.begin(), answers.end());

        for (int i = 0; i < sz;) {
            int jmp = i + 1;
            int sibling = answers[i];

            ans += sibling + 1;
            while (jmp < sz && sibling > 0) {
                if (answers[i] != answers[jmp]) {
                    break;
                }
                jmp++;
                sibling--;
            }
            i = jmp;
        }

        return ans;
    }
};

// Time: O(n), Space: O(n)
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        unordered_map<int, int> forest;

        for (auto& i: answers) {
            forest[i]++;
        }

        for (auto& [k, v]: forest) {
            ans += ceil((double)v / (k + 1)) * (k + 1);
        }

        return ans;
    }
};
