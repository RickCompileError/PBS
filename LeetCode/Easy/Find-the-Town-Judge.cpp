// Time: O(n), Space: O(n)
// all except judge must trust judge
// all except judge can trust others
// ai can repeat
// bi can change
// ai cannot be judge
// bi can be anyone
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1) {
            return 1;
        }
        
        unordered_set<int> people;
        unordered_map<int,int> trusted;

        for (auto& t: trust) {
            people.insert(t[0]);
            trusted[t[1]]++;
        }

        for (auto& [k, v]: trusted) {
            if (v == n - 1 && people.find(k) == people.end()) {
                return k;
            }
        }

        return -1;
    }
};

// Time: O(n), Space: O(1)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustCount(n + 1, 0);

        for (auto& t: trust) {
            trustCount[t[0]]--;
            trustCount[t[1]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (trustCount[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};
