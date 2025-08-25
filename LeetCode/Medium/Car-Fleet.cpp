// O(nlogn)
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        int sz = position.size();
        for (int i = 0; i < sz; i++) pq.push({position[i], speed[i]});

        stack<float> s;
        while (!pq.empty()) {
            float dis = target - pq.top().first;
            float time = dis / pq.top().second;
            while (!s.empty() && s.top() <= time) {
                s.pop();
            }
            s.push(time);
            pq.pop();
        }

        return s.size();
    }
};

