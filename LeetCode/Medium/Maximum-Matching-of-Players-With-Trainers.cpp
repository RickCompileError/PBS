// Time: O(nlogn), Space: O(n), PQ
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        priority_queue<int> pqPlayers(players.begin(), players.end());
        priority_queue<int> pqTrainers(trainers.begin(), trainers.end());
        int matches = 0;

        while (pqPlayers.size() && pqTrainers.size()) {
            if (pqPlayers.top() <= pqTrainers.top()) {
                pqTrainers.pop();
                matches++;
            }
            pqPlayers.pop();
        }

        return matches;
    }
};

// Time: O(nlogn), Space: O(1), sort
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int matches = 0;
        int szP = players.size(), szT = trainers.size();
        int p = 0, t = 0;

        sort(players.begin(), players.end(), [](auto& a, auto& b) { return a > b; });
        sort(trainers.begin(), trainers.end(), [](auto& a, auto& b) { return a > b; });
        while (p < szP && t < szT) {
            if (players[p] <= trainers[t]) {
                matches++;
                t++;
            }
            p++;
        }

        return matches;
    }
};
