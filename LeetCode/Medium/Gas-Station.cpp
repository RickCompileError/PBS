// Time: O(n), Space: O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sz = gas.size();
        int minValue = 0;
        int minPos = 0;
        int acc = 0;

        for (int i = 0; i < sz; i++) {
            acc += gas[i] - cost[i];
            if (acc < minValue) {
                minValue = acc;
                minPos = i + 1;
            }
        }

        return acc < 0 ? -1 : minPos % sz;
    }
};
