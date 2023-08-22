// Time: O(n), Space: O(n)
class Solution {
public:
    string predictPartyVictory(string senate) {
        int sz = senate.size();
        queue<int> rpos, dpos;
        for (int i = 0; i < sz; i++) {
            if (senate[i] == 'R') rpos.push(i);
            else dpos.push(i);
        }
        while (!rpos.empty() && !dpos.empty()) {
            if (rpos.front() < dpos.front()) {
                rpos.push(rpos.front() + sz);
            } else {
                dpos.push(dpos.front() + sz);
            }
            rpos.pop();
            dpos.pop();
        }
        return rpos.empty() ? "Dire" : "Radiant";
    }
};

class Solution {
public:
    string predictPartyVictory(string senate) {
        int sz = senate.size(), r, d;
        queue<int> rpos, dpos;
        for (int i = 0; i < sz; i++) senate[i] == 'R' ? rpos.push(i) : dpos.push(i);
        while (!rpos.empty() && !dpos.empty()) {
            r = rpos.front(), d = dpos.front();
            rpos.pop(), dpos.pop();
            r < d ? rpos.push(r + sz) : dpos.push(d + sz);
        }
        return rpos.empty() ? "Dire" : "Radiant";
    }
};